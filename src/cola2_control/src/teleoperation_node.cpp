#include <cola2_control/low_level_controllers/only_thruster_allocator.h>
#include <cola2_control/low_level_controllers/poly.h>
#include <cola2_lib/utils/angles.h>
#include <rclcpp/rclcpp.hpp>
#include <cola2_lib_ros/diagnostic_helper.h>
#include <cola2_lib_ros/navigation_helper.h>
#include "rclcpp/rclcpp.hpp"
#include <cola2_lib_ros/param_loader.h>
#include <cola2_lib_ros/serviceclient_helper.h>
#include <cola2_lib_ros/this_node.h>
#include <cola2_msgs/msg/body_velocity_req.hpp>
#include <cola2_msgs/msg/goal_descriptor.hpp>
#include <cola2_msgs/srv/max_joy_velocity.hpp>
#include <cola2_msgs/msg/nav_sts.hpp>
#include <cola2_msgs/msg/setpoints.hpp>
#include "rclcpp/logging.hpp"
#include <cola2_msgs/msg/world_waypoint_req.hpp>
#include <diagnostic_msgs/msg/diagnostic_status.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include "rclcpp/client.hpp"
#include "rclcpp/parameter_client.hpp"
#include <std_msgs/msg/string.hpp>
#include <std_srvs/srv/trigger.hpp>

#include <Eigen/Dense>
#include <cmath>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <any>
#include <vector>

// These define maximum velocities and turning rates for open loop teleoperation
static constexpr double OPEN_LOOP_MAX_SURGE_VEL = 1.0; //!< Maximum open loop surge velocity.
static constexpr double OPEN_LOOP_MAX_SWAY_VEL = 0.4;  //!< Maximum open loop sway velocity.
static constexpr double OPEN_LOOP_MAX_HEAVE_VEL = 0.4; //!< Maximum open loop heave velocity.
static constexpr double OPEN_LOOP_MAX_YAW_RATE = 0.6;  //!< Maximum open loop yaw turning rate.

/**
 * @brief We need a small wrapper class because the methods we want to access are protected.
 */
class ThrusterAllocatorWrapper : public OnlyThrusterAllocator
{
public:
    /**
     * @brief Constructor of the class.
     *
     * @param n_thrusters Number of thrusters.
     */
    explicit ThrusterAllocatorWrapper(unsigned int n_thrusters) : OnlyThrusterAllocator(n_thrusters) {}

    /**
     * @brief This method converts wrench to thruster forces.
     *
     * @param input Input wrench.
     * @return Returns the corresponding thruster forces.
     */
    std::vector<double> wrenchToThrusterForcesAsVector(const std::vector<double> &input)
    {
        Eigen::VectorXd wrench(input.size());
        for (std::size_t i = 0; i < input.size(); ++i)
        {
            wrench(i) = input[i];
        }
        const Eigen::VectorXd thruster_forces = wrenchToThrusterForces(wrench);
        std::vector<double> output(thruster_forces.size());
        for (std::size_t i = 0; i < static_cast<std::size_t>(thruster_forces.size()); ++i)
        {
            output[i] = thruster_forces(i);
        }
        return output;
    }

    /**
     * @brief This method converts thruster forces to thruster setpoints.
     *
     * @param input Input thruster forces.
     * @return Returns the corresponding thruster setpoints.
     */
    std::vector<double> forcesToSetpointsAsVector(const std::vector<double> &input)
    {
        Eigen::VectorXd thruster_forces(input.size());
        for (std::size_t i = 0; i < input.size(); ++i)
        {
            thruster_forces(i) = input[i];
        }
        const Eigen::VectorXd setpoint = forceToSetpoint(thruster_forces);
        std::vector<double> output(setpoint.size());
        for (std::size_t i = 0; i < static_cast<std::size_t>(setpoint.size()); ++i)
        {
            output[i] = setpoint(i);
        }
        return output;
    }
};

/**
 * @brief This class receives a joy message and generates a world_waypoint_req or a body_velocity_req.
 *
 * The joy message always have the same structure. The axis contain the value for pose and twist:
 *   --> axis: [x][y][z][roll][pitch][yaw][u][v][w][p][q][r]
 * While the buttons decide if an axis is controlled in pose or in twist:
 *   --> buttons: [x][y][z][roll][pitch][yaw][u][v][w][p][q][r]
 */
class Teleoperation : public rclcpp::Node
{
private:
    // ROS2
    rclcpp::Publisher<cola2_msgs::msg::BodyVelocityReq>::SharedPtr pub_bvr_;          //!< This publishes a body velocity request.
    rclcpp::Publisher<cola2_msgs::msg::WorldWaypointReq>::SharedPtr pub_wwr_;         //!< This publishes a world waypoint request.
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_check_joystick_;          //!< This publishes the teleoperation ACK.
    rclcpp::Publisher<cola2_msgs::msg::Setpoints>::SharedPtr pub_thruster_setpoints_; //!< This publishes thruster setpoints.
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_ack_;                  //!< Subscriber to the teleoperation ACK.
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_output_;               //!< Subscriber to the teleoperation output.
    rclcpp::Subscription<cola2_msgs::msg::NavSts>::SharedPtr sub_nav_;                //!< Subscriber to the robot navigation.
    rclcpp::Service<cola2_msgs::srv::MaxJoyVelocity>::SharedPtr srv_set_max_joy_vel_; //!< Service to set the maximum velocities.
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_set_joy_axes_to_vel_;      //!< Service to set axes to control velocity.
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_reload_params_;            //!< Service to reload params from the ROS param server.
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_enable_thrusters_;         //!< Service to enable thrusters.
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_disable_thrusters_;        //!< Service to disable thrusters.
    rclcpp::TimerBase::SharedPtr timer_slow_;                                         //!< Timer at slow rate.
    rclcpp::TimerBase::SharedPtr timer_fast_;                                         //!< Timer at fast rate.
    rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr controller_params_client_;
    std::string ns_;                                           //!< ROS namespace of this node.
    std::shared_ptr<cola2::ros::DiagnosticHelper> diagnostic_; //!< Diagnostic helper.

    // ACK control
    double last_map_ack_; //!< Time stamp in seconds of the last ACK message.
    bool map_ack_init_;   //!< It is set to true when a ACK is received.
    bool map_ack_alive_;  //!< Keeps track of the ACK.
    int seq_;             //!< Always increasing sequence number.

    // Last pose from the navigation
    double last_navigation_;        //!< Time stamp in seconds of the last valid navigation message.
    std::vector<double> last_pose_; //!< Last pose from the navigation.
    bool has_navigation_;           //!< True if navigation received at least once.

    // Velocity and position control ranges
    std::vector<double> max_vel_;            //!< Array of maximum velocities for each DoF.
    std::vector<double> min_vel_;            //!< Array of minimum velocities for each DoF.
    std::vector<double> max_pos_;            //!< Array of maximum position/orientation for each DoF.
    std::vector<double> min_pos_;            //!< Array of minimum position/orientation for each DoF.
    std::vector<double> base_pose_;          //!< Pose from which the min and max poses will be computed.
    bool actualize_base_pose_;               //!< When true, base pose is updated when pose control is enabled.
    std::vector<bool> pose_controlled_axis_; //!< This array keeps track of which DoF are pose controlled.

    // Reset keep position feature
    double last_nonzero_command_time_; //!< Time stamp in seconds of the last nonzero command.
    bool reset_keep_position_called_;  //!< It is set to false when a a keep position is needed.

    // Open loop teleoperation variables
    double max_wrench_surge_; //!< Maximum surge force.
    double max_wrench_sway_;  //!< Maximum sway force.
    double max_wrench_heave_; //!< Maximum heave force.
    double max_wrench_yaw_;   //!< Maximum yaw torque.
    Poly poly_surge_;         //!< Open loop force model for the surge DoF.
    Poly poly_sway_;          //!< Open loop force model for the sway DoF.
    Poly poly_heave_;         //!< Open loop force model for the heave DoF.
    Poly poly_yaw_;           //!< Open loop torque model for the yaw DoF.

    // Thruster allocator
    std::shared_ptr<ThrusterAllocatorWrapper> thruster_allocator_ptr_; //!< Thruster allocator wrapper.

    // Thruster enable/disable
    bool thrusters_enabled_;

    // Callback functions

    /**
     * @brief This is the callback for the navigation message.
     *
     * @param msg Navigation message.
     */
    void navCallback(const cola2_msgs::msg::NavSts::SharedPtr msg);
    /**
     * @brief This is the callback for the ACK safety message.
     *
     * @param msg ACK safety message.
     */
    void ackCallback(const std_msgs::msg::String::SharedPtr msg);
    /**
     * @brief Slow timer callback.
     *
     * @param event Timer event.
     */
    void timerSlowCallback();
    /**
     * @brief Fast timer callback.
     *
     * @param event Timer event.
     */
    void timerFastCallback();
    /**
     * @brief This is the main callback. Data is received, processed and sent to pose and velocity controllers.
     *
     * @param data Input Joy message.
     */
    void outputCallback(const sensor_msgs::msg::Joy::SharedPtr data);
    /**
     * @brief Change max/min joy velocity.
     *
     * @param req Service request.
     * @param res Service response.
     * @return Service success.
     */
    bool setMaxJoyVelCallback(const cola2_msgs::srv::MaxJoyVelocity::Request::SharedPtr req, const cola2_msgs::srv::MaxJoyVelocity::Response::SharedPtr res);
    /**
     * @brief Set all joystick axes to velocity control.
     *
     * @param req Service request.
     * @param res Service response.
     * @return Service success.
     */
    bool setJoyAxesToVelCallback(const std_srvs::srv::Trigger::Request::SharedPtr req, const std_srvs::srv::Trigger::Response::SharedPtr res);
    /**
     * @brief Enable thrusters service callback.
     *
     * @param req Service request.
     * @param res Service response.
     * @return Service success.
     */
    bool enableThrustersCallback(const std_srvs::srv::Trigger::Request::SharedPtr req, const std_srvs::srv::Trigger::Response::SharedPtr res);
    /**
     * @brief Disable thrusters service callback.
     *
     * @param req Service request.
     * @param res Service response.
     * @return Service success.
     */
    bool disableThrustersCallback(const std_srvs::srv::Trigger::Request::SharedPtr req, const std_srvs::srv::Trigger::Response::SharedPtr res);
    /**
     * @brief Reload joystick config values.
     *
     * @param req Service request.
     * @param res Service response.
     * @return Service success.
     */
    bool reloadParamsCallback(const std_srvs::srv::Trigger::Request::SharedPtr req, const std_srvs::srv::Trigger::Response::SharedPtr res);
    /**
     * @brief Get config from ROS param server.
     *
     * @return Returns true if the config is successfully loaded, and false otherwise.
     */
    bool getConfig();
    /**
     * @brief This method can be used to handle a Trigger service call.
     *
     * @param srv_name Service name.
     * @param timeout Timeout.
     * @param wait_time Wait time.
     * @return Returns true if the call is successful and false otherwise.
     */
    bool callTriggerService(const std::string &srv_name, const double timeout, const double wait_time);

public:
    /**
     * @brief Default constructor.
     */
    Teleoperation();
    void init();
};

void Teleoperation::init()
{
    ns_ = cola2::ros::getNamespace(shared_from_this());
    // RCLCPP_INFO(this->get_logger(), ns_.c_str());

    // Controller params
    controller_params_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("controller/get_parameters");

    if (!getConfig())
    {
        RCLCPP_FATAL(this->get_logger(), "Invalid parameters in ROS param server. Shutting down");
        rclcpp::shutdown();
    }

    // Publishers
    pub_check_joystick_ = this->create_publisher<std_msgs::msg::String>(cola2::ros::getNamespace(shared_from_this()) + "/ack", 10);
    pub_bvr_ = this->create_publisher<cola2_msgs::msg::BodyVelocityReq>("controller/body_velocity_req", 10);
    pub_wwr_ = this->create_publisher<cola2_msgs::msg::WorldWaypointReq>("controller/world_waypoint_req", 10);
    pub_thruster_setpoints_ = this->create_publisher<cola2_msgs::msg::Setpoints>("controller/thruster_setpoints", 1);

    // Subscribers
    sub_ack_ = this->create_subscription<std_msgs::msg::String>("input_to_teleoperation/ack", 10, std::bind(&Teleoperation::ackCallback, this, std::placeholders::_1));
    sub_output_ = this->create_subscription<sensor_msgs::msg::Joy>("input_to_teleoperation/output", 10, std::bind(&Teleoperation::outputCallback, this, std::placeholders::_1));
    sub_nav_ = this->create_subscription<cola2_msgs::msg::NavSts>("navigator/navigation", 10, std::bind(&Teleoperation::navCallback, this, std::placeholders::_1));

    // Services
    srv_set_max_joy_vel_ = this->create_service<cola2_msgs::srv::MaxJoyVelocity>("controller/set_max_joy_velocity", std::bind(&Teleoperation::setMaxJoyVelCallback, this, std::placeholders::_1, std::placeholders::_2));
    srv_set_joy_axes_to_vel_ = this->create_service<std_srvs::srv::Trigger>("controller/set_joystick_axes_to_velocity", std::bind(&Teleoperation::setJoyAxesToVelCallback, this, std::placeholders::_1, std::placeholders::_2));
    srv_reload_params_ = this->create_service<std_srvs::srv::Trigger>("controller/reload_params", std::bind(&Teleoperation::reloadParamsCallback, this, std::placeholders::_1, std::placeholders::_2));
    srv_enable_thrusters_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) +"/enable_thrusters", std::bind(&Teleoperation::enableThrustersCallback, this, std::placeholders::_1, std::placeholders::_2));
    srv_disable_thrusters_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) +"/disable_thrusters", std::bind(&Teleoperation::disableThrustersCallback, this, std::placeholders::_1, std::placeholders::_2));

    // Timers
    timer_slow_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&Teleoperation::timerSlowCallback, this));
    timer_fast_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&Teleoperation::timerFastCallback, this));

    // Show message
    diagnostic_ = std::make_shared<cola2::ros::DiagnosticHelper>(shared_from_this(), "teleop", cola2::ros::getUnresolvedNodeName(shared_from_this()));
    diagnostic_->setEnabled(true);
    RCLCPP_INFO(this->get_logger(), "Initialized");
}

Teleoperation::Teleoperation()
    : Node("teleoperation"),
      last_map_ack_(0.0),
      map_ack_init_(false),
      map_ack_alive_(true),
      seq_(0),
      last_navigation_(0.0),
      last_pose_(6, 0.0),
      has_navigation_(false),
      max_vel_(6, 0.0),
      min_vel_(6, 0.0),
      max_pos_(6, 0.0),
      min_pos_(6, 0.0),
      base_pose_(6, 0.0),
      actualize_base_pose_(true),
      pose_controlled_axis_(6, false),
      last_nonzero_command_time_(0.0),
      reset_keep_position_called_(true),
      max_wrench_surge_(0.0),
      max_wrench_sway_(0.0),
      max_wrench_heave_(0.0),
      max_wrench_yaw_(0.0),
      poly_surge_("poly_surge"),
      poly_sway_("poly_sway"),
      poly_heave_("poly_heave"),
      poly_yaw_("poly_yaw"),
      thrusters_enabled_(false)
{
    while (rclcpp::Clock().now().seconds() == 0.0 && rclcpp::ok())
    {
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Waiting for valid time source");
        rclcpp::sleep_for(std::chrono::milliseconds(100));
    }
}

void Teleoperation::navCallback(const cola2_msgs::msg::NavSts::SharedPtr msg)
{
    if (cola2::ros::navigationIsValid(*msg))
    {
        last_navigation_ = msg->header.stamp.sec + msg->header.stamp.nanosec * 1e-9;
        last_pose_[0] = msg->position.north;
        last_pose_[1] = msg->position.east;
        last_pose_[2] = msg->position.depth;
        last_pose_[3] = msg->orientation.roll;
        last_pose_[4] = msg->orientation.pitch;
        last_pose_[5] = msg->orientation.yaw;
        has_navigation_ = true;
    }
}

void Teleoperation::ackCallback(const std_msgs::msg::String::SharedPtr msg)
{
    if (msg->data.size() >= 5)
    {
        const std::vector<std::string> data = {msg->data.substr(0, msg->data.size() - 4), msg->data.substr(msg->data.size() - 3)};
        if ((data[1] == "ack") && (data[0] == std::to_string(seq_ + 1)))
        {
            map_ack_alive_ = true;
            if (!map_ack_init_)
            {
                RCLCPP_INFO(this->get_logger(), "Teleoperation link established");
            }
            map_ack_init_ = true;
            ++seq_;
            last_map_ack_ = this->now().seconds();
        }
    }
}

void Teleoperation::timerFastCallback()
{
    // Check whether navigation expired or not
    if (this->get_clock()->now().seconds() - last_navigation_ > 1.0)
    {
        has_navigation_ = false;
    }

    // Call reset keep position if needed
    if ((!reset_keep_position_called_) && (this->get_clock()->now().seconds() - last_nonzero_command_time_ > 3.0))
    {
        callTriggerService("captain/reset_keep_position", 1.0, 1.0);
        reset_keep_position_called_ = true;
    }
}

void Teleoperation::timerSlowCallback()
{
    diagnostic_->setLevelAndMessage(diagnostic_msgs::msg::DiagnosticStatus::OK);

    if (map_ack_init_)
    {
        diagnostic_->addKeyValue("last_ack", this->get_clock()->now().seconds() - last_map_ack_);
        if (map_ack_alive_)
        {
            map_ack_alive_ = false;
            diagnostic_->reportValidData(this->get_clock()->now());
        }
        else
        {
            // Reset pose controlled axis
            diagnostic_->setLevelAndMessage(diagnostic_msgs::msg::DiagnosticStatus::WARN, "Missing teleoperation link");
            diagnostic_->reportData();
            pose_controlled_axis_ = std::vector<bool>(6, false);
        }
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "Teleoperation link not established yet");
    }

    // Publish diagnostics
    diagnostic_->publish(shared_from_this());

    // Send ack message. The other end needs to reply with the corresponding sequence number
    std_msgs::msg::String msg;
    msg.data = std::to_string(seq_) + " ok";
    pub_check_joystick_->publish(msg);
}

bool Teleoperation::setMaxJoyVelCallback(const std::shared_ptr<cola2_msgs::srv::MaxJoyVelocity::Request> req, std::shared_ptr<cola2_msgs::srv::MaxJoyVelocity::Response> res)
{
    RCLCPP_INFO(this->get_logger(), "Change max/min joy velocity");
    for (std::size_t i = 0; i < 6; ++i)
    {
        max_vel_[i] = req->max_joy_velocity[i];
        min_vel_[i] = -req->max_joy_velocity[i];
    }
    res->attempted = true;
    return true;
}

bool Teleoperation::setJoyAxesToVelCallback(const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
    RCLCPP_INFO(this->get_logger(), "Set all axes to velocity");
    sensor_msgs::msg::Joy data;
    data.axes.resize(12, 0.0);
    data.buttons.resize(6, 0);
    data.buttons.resize(12, 1);
    outputCallback(std::make_shared<sensor_msgs::msg::Joy>(data));
    res->message = "Success";
    res->success = true;
    return true;
}

bool Teleoperation::enableThrustersCallback(const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
    RCLCPP_INFO(this->get_logger(), "Enabling thrusters");

    if (callTriggerService("controller/enable_thrusters", 1.0, 1.0))
    {
        thrusters_enabled_ = true;
        res->message = "Thrusters enabled";
        res->success = true;
        RCLCPP_INFO_STREAM(this->get_logger(), res->message);
    }
    else
    {
        res->message = "Error enabling thrusters. Controller service call failed";
        res->success = false;
        RCLCPP_ERROR_STREAM(this->get_logger(), res->message);
    }
    return true;
}

bool Teleoperation::disableThrustersCallback(const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
    RCLCPP_INFO(this->get_logger(), "Disabling thrusters");

    if (callTriggerService("controller/disable_thrusters", 1.0, 1.0))
    {
        // callTriggerService(ns_ + "/safety_supervisor/reset_emergency_ramp", 1.0, 1.0);
        thrusters_enabled_ = false;
        res->message = "Thrusters disabled";
        res->success = true;
        RCLCPP_INFO(this->get_logger(), res->message.c_str());
    }
    else
    {
        res->message = "Error disabling thrusters. Controller service call failed";
        res->success = false;
        RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    }
    return true;
}

bool Teleoperation::reloadParamsCallback(const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
    RCLCPP_INFO(this->get_logger(), "Reloading teleoperation params");
    if (getConfig())
    {
        res->message = "Success";
        res->success = true;
        // callTriggerService(ns_ + "/param_logger/publish_params", 1.0, 1.0); //TODO?
    }
    else
    {
        res->message = "Unable to successfully reload params";
        res->success = false;
        RCLCPP_WARN(this->get_logger(), res->message.c_str());
    }
    return true;
}

bool Teleoperation::callTriggerService(const std::string &srv_name, const double timeout, const double wait_time)
{
    try
    {
        auto client = this->create_client<std_srvs::srv::Trigger>(srv_name);
        if (!client->wait_for_service(std::chrono::seconds((int)wait_time)))
        {
            RCLCPP_ERROR(this->get_logger(), "Service %s not available", srv_name.c_str());
            return false;
        }
        auto request = std::make_shared<std_srvs::srv::Trigger::Request>();
        auto future = client->async_send_request(request);

        future.wait_for(std::chrono::seconds((int)timeout));
        return true;
    }
    catch (const std::exception &ex)
    {
        RCLCPP_ERROR(this->get_logger(), "Exception while calling trigger service %s: %s", srv_name.c_str(), ex.what());
    }
    return false;
}

void Teleoperation::outputCallback(const sensor_msgs::msg::Joy::SharedPtr data)
{
    // Check axes and buttons length
    if (data->axes.size() != 12)
    {
        RCLCPP_ERROR(this->get_logger(), "Invalid axes array length");
        return;
    }
    if (data->buttons.size() != 12)
    {
        RCLCPP_ERROR(this->get_logger(), "Invalid buttons array length");
        return;
    }

    // Store time if the command is different than zero. This time is used by the reset keep position feature
    if (data->header.frame_id != "captain")
    {
        for (std::size_t i = 0; i < data->axes.size(); ++i)
        {
            if (std::fabs(data->axes[i]) > 1e-3)
            {
                last_nonzero_command_time_ = this->now().seconds();
                reset_keep_position_called_ = false;
            }
        }
        for (std::size_t i = 0; i < data->buttons.size(); ++i)
        {
            if (std::fabs(data->buttons[i]) > 1e-3)
            {
                last_nonzero_command_time_ = this->now().seconds();
                reset_keep_position_called_ = false;
            }
        }
    }

    // Check if pose controller is enabled
    for (std::size_t i = 0; i < 6; ++i)
    {
        if (data->buttons[i] == 1)
        {
            pose_controlled_axis_[i] = true;
            if (actualize_base_pose_)
            {
                base_pose_[i] = last_pose_[i];
            }
            RCLCPP_INFO(this->get_logger(), "Axis %zu now is pose", i);
        }
    }

    // Check if velocity controller is enabled
    for (std::size_t i = 6; i < 12; ++i)
    {
        if (data->buttons[i] == 1)
        {
            pose_controlled_axis_[i - 6] = false;
            RCLCPP_INFO(this->get_logger(), "Axis %zu now is velocity", i - 6);
        }
    }

    // With navigation, we use position and velocity requests. Without navigation, we use open loop thruster commands
    if (has_navigation_)
    {
        // Compute desired positions
        std::vector<double> desired(12, 0);
        for (std::size_t i = 0; i < 6; ++i)
        {
            if (data->axes[i] < 0.0)
            {
                desired[i] = std::fabs(data->axes[i]) * min_pos_[i] + base_pose_[i];
            }
            else
            {
                desired[i] = data->axes[i] * max_pos_[i] + base_pose_[i];
            }
            if (i > 2)
            {
                // Normalize angles
                desired[i] = cola2::utils::wrapAngle(desired[i]);
            }
        }

        // Compute desired velocities
        for (std::size_t i = 6; i < 12; ++i)
        {
            if (data->axes[i] < 0.0)
            {
                desired[i] = std::fabs(data->axes[i]) * min_vel_[i - 6];
            }
            else
            {
                desired[i] = data->axes[i] * max_vel_[i - 6];
            }
        }

        // Publish world waypoint request
        cola2_msgs::msg::WorldWaypointReq world_waypoint_req;
        world_waypoint_req.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_TELEOPERATION;
        world_waypoint_req.goal.requester = cola2::ros::getUnresolvedNodeName(shared_from_this()) + "_pose";
        world_waypoint_req.position.north = desired[0];
        world_waypoint_req.position.east = desired[1];
        world_waypoint_req.position.depth = desired[2];
        world_waypoint_req.orientation.roll = desired[3];
        world_waypoint_req.orientation.pitch = desired[4];
        world_waypoint_req.orientation.yaw = desired[5];
        world_waypoint_req.disable_axis.x = !pose_controlled_axis_[0];
        world_waypoint_req.disable_axis.y = !pose_controlled_axis_[1];
        world_waypoint_req.disable_axis.z = !pose_controlled_axis_[2];
        world_waypoint_req.disable_axis.roll = !pose_controlled_axis_[3];
        world_waypoint_req.disable_axis.pitch = !pose_controlled_axis_[4];
        world_waypoint_req.disable_axis.yaw = !pose_controlled_axis_[5];
        world_waypoint_req.header.stamp = this->now();
        world_waypoint_req.header.frame_id = "world_ned";
        if (world_waypoint_req.disable_axis.x && world_waypoint_req.disable_axis.y && world_waypoint_req.disable_axis.z &&
            world_waypoint_req.disable_axis.roll && world_waypoint_req.disable_axis.pitch &&
            world_waypoint_req.disable_axis.yaw)
        {
            world_waypoint_req.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_TELEOPERATION_LOW;
        }
        pub_wwr_->publish(world_waypoint_req);

        // Create body velocity request
        cola2_msgs::msg::BodyVelocityReq body_velocity_req;
        body_velocity_req.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_TELEOPERATION;
        body_velocity_req.goal.requester = cola2::ros::getUnresolvedNodeName(shared_from_this()) + "_vel";
        body_velocity_req.twist.linear.x = desired[6];
        body_velocity_req.twist.linear.y = desired[7];
        body_velocity_req.twist.linear.z = desired[8];
        body_velocity_req.twist.angular.x = desired[9];
        body_velocity_req.twist.angular.y = desired[10];
        body_velocity_req.twist.angular.z = desired[11];
        body_velocity_req.disable_axis.x = pose_controlled_axis_[0];
        body_velocity_req.disable_axis.y = pose_controlled_axis_[1];
        body_velocity_req.disable_axis.z = pose_controlled_axis_[2];
        body_velocity_req.disable_axis.roll = pose_controlled_axis_[3];
        body_velocity_req.disable_axis.pitch = pose_controlled_axis_[4];
        body_velocity_req.disable_axis.yaw = pose_controlled_axis_[5];

        // Check if DoF need to be disabled due to very small command
        if (std::fabs(body_velocity_req.twist.linear.x) < 0.025)
        {
            body_velocity_req.disable_axis.x = true;
        }
        if (std::fabs(body_velocity_req.twist.linear.y) < 0.025)
        {
            body_velocity_req.disable_axis.y = true;
        }
        if (std::fabs(body_velocity_req.twist.linear.z) < 0.025)
        {
            body_velocity_req.disable_axis.z = true;
        }
        if (std::fabs(body_velocity_req.twist.angular.x) < 0.01)
        {
            body_velocity_req.disable_axis.roll = true;
        }
        if (std::fabs(body_velocity_req.twist.angular.y) < 0.01)
        {
            body_velocity_req.disable_axis.pitch = true;
        }
        if (std::fabs(body_velocity_req.twist.angular.z) < 0.01)
        {
            body_velocity_req.disable_axis.yaw = true;
        }

        // If all DoF are disabled set priority to low
        if (body_velocity_req.disable_axis.x && body_velocity_req.disable_axis.y && body_velocity_req.disable_axis.z &&
            body_velocity_req.disable_axis.roll && body_velocity_req.disable_axis.pitch &&
            body_velocity_req.disable_axis.yaw)
        {
            body_velocity_req.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_TELEOPERATION_LOW;
        }

        // Publish body velocity request
        body_velocity_req.header.stamp = this->now();
        body_velocity_req.header.frame_id = std::string(this->get_namespace()) + "/base_link";
        pub_bvr_->publish(body_velocity_req);
    }
    else
    {
        // Display message
        // RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5, "Teleoperation working in open loop mode");

        if (thrusters_enabled_)
        {
            // Compute desired velocities
            const double desired_surge_vel = data->axes[6] * OPEN_LOOP_MAX_SURGE_VEL;
            const double desired_sway_vel = data->axes[7] * OPEN_LOOP_MAX_SWAY_VEL;
            const double desired_heave_vel = data->axes[8] * OPEN_LOOP_MAX_HEAVE_VEL;
            const double desired_yaw_rate = data->axes[11] * OPEN_LOOP_MAX_YAW_RATE;

            // Compute desired forces using the open loop poly models
            const double desired_surge_force = poly_surge_.compute(0.0, desired_surge_vel, 0.0);
            const double desired_sway_force = poly_sway_.compute(0.0, desired_sway_vel, 0.0);
            const double desired_heave_force = poly_heave_.compute(0.0, desired_heave_vel, 0.0);
            const double desired_yaw_torque = poly_yaw_.compute(0.0, desired_yaw_rate, 0.0);

            // Compute thruster forces
            const std::vector<double> wrench = {desired_surge_force, desired_sway_force, desired_heave_force, 0.0, 0.0, desired_yaw_torque};
            const std::vector<double> thruster_forces = thruster_allocator_ptr_->wrenchToThrusterForcesAsVector(wrench);

            // Compute thruster setpoints
            const std::vector<double> setpoints = thruster_allocator_ptr_->forcesToSetpointsAsVector(thruster_forces);

            // Publish setpoints
            cola2_msgs::msg::Setpoints msg_setpoints;
            msg_setpoints.header.stamp = this->now();    // Safer than using joy stamp
            msg_setpoints.header.frame_id = "open_loop"; // The frame_id must be "open_loop"
            msg_setpoints.setpoints = setpoints;
            pub_thruster_setpoints_->publish(msg_setpoints);
        }
        else
        {
            // RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5, "Discarding open loop mode setpoints because thrusters are not enabled");
        }
    }
}

bool Teleoperation::getConfig()
{
    bool ok = true;

    // Declare default values for the parameters
    this->declare_parameter<std::vector<double>>("max_pos", std::vector<double>{10.0, 10.0, 2.0, 3.14159265359, 3.14159265359, 3.14159265359});
    this->declare_parameter<std::vector<double>>("min_pos", std::vector<double>{-10.0, -10.0, -2.0, -3.14159265359, -3.14159265359, -3.14159265359});
    this->declare_parameter<std::vector<double>>("max_vel", std::vector<double>{0.6, 0.2, 0.35, 0.0, 0.0, 0.25});
    this->declare_parameter<std::vector<double>>("min_vel", std::vector<double>{-0.6, -0.2, -0.35, 0.0, 0.0, -0.25});
    this->declare_parameter<std::vector<bool>>("pose_controlled_axis", std::vector<bool>{false, false, false, false, false, false});
    this->declare_parameter<std::vector<double>>("base_pose", std::vector<double>{0, 0, 0, 0, 0, 0});
    this->declare_parameter<bool>("actualize_base_pose", true);

    ok &= this->get_parameter("max_pos", max_pos_);
    ok &= this->get_parameter("min_pos", min_pos_);
    ok &= this->get_parameter("max_vel", max_vel_);
    ok &= this->get_parameter("min_vel", min_vel_);
    ok &= this->get_parameter("pose_controlled_axis", pose_controlled_axis_);
    ok &= this->get_parameter("base_pose", base_pose_);
    ok &= this->get_parameter("actualize_base_pose", actualize_base_pose_);

    if (!ok)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to load parameters");
    }

    int n_thrusters = 0;
    std::vector<double> tcm;
    std::vector<std::vector<double>> poly_positive_v, poly_negative_v;
    std::vector<double> max_force_thruster_positive_v, max_force_thruster_negative_v;
    double poly_surge_a, poly_surge_b, poly_surge_c;
    double poly_sway_a, poly_sway_b, poly_sway_c;
    double poly_heave_a, poly_heave_b, poly_heave_c;
    double poly_yaw_a, poly_yaw_b, poly_yaw_c;
    std::map<std::string, double> poly_surge_params;
    std::map<std::string, double> poly_sway_params;
    std::map<std::string, double> poly_heave_params;
    std::map<std::string, double> poly_yaw_params;

    while (!controller_params_client_->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_INFO(this->get_logger(), "Waiting for controller get_parameters service to be available");
    }
    RCLCPP_INFO(this->get_logger(), "Controller get_parameters service to be available");

    rcl_interfaces::srv::GetParameters::Request::SharedPtr request = std::make_shared<rcl_interfaces::srv::GetParameters::Request>();
    request->names.push_back("n_thrusters");
    request->names.push_back("thruster_1_poly_positive");
    request->names.push_back("thruster_1_poly_negative");
    request->names.push_back("thruster_1_max_force_positive");
    request->names.push_back("thruster_1_max_force_negative");
    request->names.push_back("TCM");
    request->names.push_back("max_wrench_X");
    request->names.push_back("max_wrench_Y");
    request->names.push_back("max_wrench_Z");
    request->names.push_back("max_wrench_Yaw");
    request->names.push_back("poly_surge_A");
    request->names.push_back("poly_surge_B");
    request->names.push_back("poly_surge_C");
    request->names.push_back("poly_sway_A");
    request->names.push_back("poly_sway_B");
    request->names.push_back("poly_sway_C");
    request->names.push_back("poly_heave_A");
    request->names.push_back("poly_heave_B");
    request->names.push_back("poly_heave_C");
    request->names.push_back("poly_yaw_A");
    request->names.push_back("poly_yaw_B");
    request->names.push_back("poly_yaw_C");

    auto future = controller_params_client_->async_send_request(request);
    rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);

    if (future.valid())
    {
        auto response = future.get();
        n_thrusters = response->values[0].integer_value;

        std::vector<double> thruster_poly_positive, thruster_poly_negative;
        double max_force_positive, max_force_negative;
        thruster_poly_positive = response->values[1].double_array_value;
        thruster_poly_negative = response->values[2].double_array_value;
        max_force_positive = response->values[3].double_value;
        max_force_negative = response->values[4].double_value;

        for (int i = 0; i < n_thrusters; ++i) // Setting all the data for all the thrusters the same
        {
            poly_positive_v.push_back(thruster_poly_positive);
            poly_negative_v.push_back(thruster_poly_negative);
            max_force_thruster_positive_v.push_back(max_force_positive);
            max_force_thruster_negative_v.push_back(max_force_negative);
        }

        tcm = response->values[5].double_array_value;

        // this->declare_parameter<int>(ns_ + "/controller/period", 0.5);

        max_wrench_surge_ = response->values[6].double_value;
        max_wrench_sway_ = response->values[7].double_value;
        max_wrench_heave_ = response->values[8].double_value;
        max_wrench_yaw_ = response->values[9].double_value;

        poly_surge_a = response->values[10].double_value;
        poly_surge_b = response->values[11].double_value;
        poly_surge_c = response->values[12].double_value;

        poly_sway_a = response->values[13].double_value;
        poly_sway_b = response->values[14].double_value;
        poly_sway_c = response->values[15].double_value;

        poly_heave_a = response->values[16].double_value;
        poly_heave_b = response->values[17].double_value;
        poly_heave_c = response->values[18].double_value;

        poly_yaw_a = response->values[19].double_value;
        poly_yaw_b = response->values[20].double_value;
        poly_yaw_c = response->values[21].double_value;

        poly_surge_params.insert(std::pair<std::string, double>("n_dof", 3.0));
        poly_surge_params.insert(std::pair<std::string, double>("0", poly_surge_a));
        poly_surge_params.insert(std::pair<std::string, double>("1", poly_surge_b));
        poly_surge_params.insert(std::pair<std::string, double>("2", poly_surge_c));

        poly_sway_params.insert(std::pair<std::string, double>("n_dof", 3.0));
        poly_sway_params.insert(std::pair<std::string, double>("0", poly_sway_a));
        poly_sway_params.insert(std::pair<std::string, double>("1", poly_sway_b));
        poly_sway_params.insert(std::pair<std::string, double>("2", poly_sway_c));

        poly_heave_params.insert(std::pair<std::string, double>("n_dof", 3.0));
        poly_heave_params.insert(std::pair<std::string, double>("0", poly_heave_a));
        poly_heave_params.insert(std::pair<std::string, double>("1", poly_heave_b));
        poly_heave_params.insert(std::pair<std::string, double>("2", poly_heave_c));

        poly_yaw_params.insert(std::pair<std::string, double>("n_dof", 3.0));
        poly_yaw_params.insert(std::pair<std::string, double>("0", poly_yaw_a));
        poly_yaw_params.insert(std::pair<std::string, double>("1", poly_yaw_b));
        poly_yaw_params.insert(std::pair<std::string, double>("2", poly_yaw_c));

        // Open loop parameters (e.g., polynomial parameters)
        poly_surge_.setParameters(poly_surge_params);
        poly_sway_.setParameters(poly_sway_params);
        poly_heave_.setParameters(poly_heave_params);
        poly_yaw_.setParameters(poly_yaw_params);

        thruster_allocator_ptr_ = std::make_shared<ThrusterAllocatorWrapper>(n_thrusters);
        thruster_allocator_ptr_->setParams(max_force_thruster_positive_v, max_force_thruster_negative_v, poly_positive_v, poly_negative_v, tcm);
    }
    else
    {
        ok = false;
        RCLCPP_ERROR(this->get_logger(), "Failed to get parameters from controller get_parameters");
    }

    return ok;
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Teleoperation>();
    node->init();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}