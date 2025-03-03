/*
 * Copyright (c) 2023 Iqua Robotics SL - All Rights Reserved
 *
 * This file is subject to the terms and conditions defined in file
 * 'LICENSE.txt', which is part of this source code package.
 */

#include <cola2_control/controllers/types.h>
#include <cola2_lib/mission/mission.h>
#include <cola2_lib/utils/filesystem.h>
#include <cola2_lib/utils/ned.h>
#include <cola2_lib_ros/diagnostic_helper.h>
#include <cola2_lib_ros/navigation_helper.h>
#include <cola2_lib_ros/param_loader.h>
#include <cola2_lib_ros/serviceclient_helper.h>
#include <cola2_lib_ros/this_node.h>
#include <cola2_msgs/srv/action.hpp>
#include "cola2_msgs/msg/captain_state_feedback.hpp"
#include "cola2_msgs/msg/captain_status.hpp"
#include "cola2_msgs/msg/goal_descriptor.hpp"
#include <rclcpp_action/rclcpp_action.hpp>
#include "cola2_msgs/srv/goto.hpp"
#include "cola2_msgs/msg/key_value.hpp"
#include "cola2_msgs/srv/mission.hpp"
#include "cola2_msgs/msg/mission_state.hpp"
#include "cola2_msgs/msg/nav_sts.hpp"
#include "cola2_msgs/action/pilot.hpp"
#include "cola2_msgs/srv/section.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/path.hpp"
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include <sensor_msgs/msg/joy.hpp>
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>

#include <algorithm>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// Helper functions to modify the key-value list
void setKeyValue(cola2_msgs::msg::CaptainStateFeedback *feedback, const std::string &key, const std::string &value)
{
  for (std::size_t i = 0; i < feedback->keyvalues.size(); ++i)
  {
    if (feedback->keyvalues[i].key == key)
    {
      feedback->keyvalues[i].value = value;
      return;
    }
  }
  cola2_msgs::msg::KeyValue keyvalue;
  keyvalue.key = key;
  keyvalue.value = value;
  feedback->keyvalues.push_back(keyvalue);
}

/**
 * \brief Captain class. It can execute maneuvers like goto and keep position as well as missions
 */
class Captain : public rclcpp::Node
{
protected:
  // ROS

  rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr controller_params_client_;
  rclcpp::Client<rcl_interfaces::srv::GetParameters>::SharedPtr pilot_params_client_;

  rclcpp::Subscription<cola2_msgs::msg::NavSts>::SharedPtr sub_nav_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub_path_;
  rclcpp::Publisher<cola2_msgs::msg::CaptainStatus>::SharedPtr pub_captain_status_;
  rclcpp::Publisher<cola2_msgs::msg::CaptainStateFeedback>::SharedPtr pub_captain_state_feedback_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_mission_str_;
  rclcpp::Publisher<sensor_msgs::msg::Joy>::SharedPtr pub_joy_;

  // Service servers
  rclcpp::Service<cola2_msgs::srv::Goto>::SharedPtr enable_goto_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_goto_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr disable_goto_client_; // To call the service
  rclcpp::Service<cola2_msgs::srv::Section>::SharedPtr enable_section_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_section_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr disable_section_client_; // To call the service
  rclcpp::Service<cola2_msgs::srv::Mission>::SharedPtr enable_mission_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr pause_mission_srv_;
  rclcpp::Service<cola2_msgs::srv::Mission>::SharedPtr resume_mission_srv_;
  rclcpp::Service<cola2_msgs::srv::Mission>::SharedPtr disable_mission_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr enable_keep_position_holonomic_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr enable_keep_position_holonomic_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr enable_keep_position_non_holonomic_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr enable_keep_position_non_holonomic_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_keep_position_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr disable_keep_position_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr enable_safety_keep_position_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr enable_safety_keep_position_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_safety_keep_position_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr disable_safety_keep_position_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_all_keep_positions_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reset_keep_position_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr reset_keep_position_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr enable_external_mission_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_external_mission_srv_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr disable_external_mission_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr disable_all_and_set_idle_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr disable_all_and_set_idle_client_; // To call the service
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_reload_params_;

  // Service client
  // rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr srv_publish_params_;

  rclcpp::TimerBase::SharedPtr main_timer_;
  rclcpp::TimerBase::SharedPtr diagnostics_timer_;

  // Diagnostics
  std::shared_ptr<cola2::ros::DiagnosticHelper> diagnostic_;

  // Actionlib client
  using pilot_action = cola2_msgs::action::Pilot;
  using GoalHandlePilot = rclcpp_action::ClientGoalHandle<pilot_action>;

  rclcpp_action::Client<pilot_action>::SharedPtr pilot_actionlib_;
  rclcpp_action::Client<pilot_action>::GoalHandle::SharedPtr goal_handle_;
  bool is_pilot_actionlib_running_;

  // Possible captain states
  enum class CaptainStates
  {
    Idle,
    Goto,
    Section,
    Mission,
    KeepPosition,
    SafetyKeepPosition,
    ExternalMission
  };
  CaptainStates state_;
  std::string last_running_mission_;
  std::string external_mission_caller_name_;

  // Some keep position parameters
  bool last_keep_position_holonomic_;
  double last_keep_position_time_;
  double last_keep_position_duration_;

  bool goal_asked_;

  // Feedback for the different modes
  cola2_msgs::msg::CaptainStateFeedback goto_feedback_;
  cola2_msgs::msg::CaptainStateFeedback section_feedback_;
  cola2_msgs::msg::CaptainStateFeedback mission_feedback_;
  cola2_msgs::msg::CaptainStateFeedback keep_position_feedback_;
  cola2_msgs::msg::CaptainStateFeedback safety_keep_position_feedback_;
  std::uint16_t external_mission_feedback_id_;

  // Navigation data
  cola2_msgs::msg::NavSts nav_;
  double last_nav_received_;

  // Detect sudden change in position
  double position_checking_north_;
  double position_checking_east_;
  double position_checking_time_;

  // Actionlib request, used for feedback
  cola2_msgs::action::Pilot::Goal actionlib_request_;

  // Section request
  cola2_msgs::srv::Section::Request section_req_;

  // Maneuver flags
  bool goto_enabled_;
  bool section_enabled_;
  bool approach_completed_;
  bool step_completed_;

  // Internal list of missions
  struct MissionWithState
  {
    Mission mission;
    std::size_t current_step;
    rclcpp::Time last_active;
    MissionWithState() : current_step(0)
    {
    }
  };
  std::map<std::string, MissionWithState> loaded_missions_;

  // Config
  struct
  {
    double max_distance_to_waypoint;
    double safety_keep_position_depth;
    bool safety_keep_position_goes_to_ned_origin;
    bool reset_keep_position_on_navigation_jump;
    double pilot_section_max_surge_velocity;
    double controller_max_velocity_z;
    std::string vehicle_config_launch_mission_package;
    bool idle_no_altitude_goes_up;
    std::string enable_no_altitude_goes_up_service;
    std::string disable_no_altitude_goes_up_service;
  } config_;

  /**
   * \brief This method changes the no altitude reactive behavior of the safe depth altitude
   * \param[in] True if no altitude goes up and false otherwise
   * \param[in] Safe depth altitude service wait time
   */
  void updateNoAltitudeGoesUp(const bool, const double wait_time = 1.0);

  /**
   * \brief This method changes the no altitude reactive behavior of the safe depth altitude
   *        corresponding to the Idle state
   * \param[in] Safe depth altitude service wait time
   */
  void updateNoAltitudeGoesUpIdle(const double wait_time = 1.0);

  /**
   * \brief This method publishes a Joy message to disable teleoperation pose controllers.
   */
  void disableTeleoperationPoseControllers();

  /**
   * \brief Waits for the actionlib to become ready
   * \param[in] Actionlib client
   * \param[in] Actionlib name (only used to display rosout msgs)
   */
  template <typename T>
  void waitActionlib(const typename rclcpp_action::Client<T>::SharedPtr &, const std::string &);

  /**
   * \brief This method can be used to handle a Trigger service call
   * \param[in] Service name
   * \param[in] Timeout
   * \param[in] Wait time
   * \return Returns true if the call is successful and false otherwise
   */
  bool callTriggerService(const std::string &, const double, const double);

  /**
   * \brief This method cancels the pilot actionlib
   */
  void cancelPilotActionlib();

  /**
   * \brief Callback to 'namespace'/navigator/navigation topic
   * \param[in] Navigation message
   */
  void updateNav(const cola2_msgs::msg::NavSts &);

  /**
   * \brief Diagnostics timer
   */
  void diagnosticsTimer();

  /**
   * \brief Main timer. It triggers the main iteration
   */
  void mainTimer();

  /**
   * \brief Main iteration. It checks the current state and performs the required actions
   */
  void mainIteration();

  /**
   * \brief Given a mission builds a nav_msgs::Path to represent it in RViz
   * \param[in] Mission
   * \return Path
   */
  nav_msgs::msg::Path createPathFromMission(Mission);

  /**
   * \brief Calls a standard action or a trigger service with name const std::string action_id and parameters
   *        const std::vector<std::string> parameters
   * \param[in] Is the action empty?
   * \param[in] Action ID
   * \param[in] Action parameters
   */
  void callAction(bool, const std::string &, std::vector<std::string>);

  /**
   * \brief This method sets to false all maneuver flags
   */
  void resetManeuverFlags();

  /**
   * \brief Use this method to remove a mission from the loaded missions list
   * \param[in] Mission name
   * \return Returns true if the mission was found and thus deleted and false otherwise
   */
  bool deleteLoadedMission(const std::string &);

  /**
   * \brief This method returns the default mission name
   * \return It returns the default mission name if it is available, or an empty string otherwise
   */
  std::string getDefaultMissionName();

  /**
   * \brief Execute all pending actions
   * \param[in] Mission index
   */
  void executePendingActions(std::string);

  /**
   * \brief Main goto method that is called at each iteration from the main timer
   */
  void goTo(); // Should be goto, but it is a keyword

  /**
   * \brief This method checks whether the pilot has finished or not
   * \return It returns true if it has finished and false otherwise
   */
  bool pilotHasFinished();

  /**
   * \brief This method returns the timeout and distance to the end of an actionlib request
   * \param[in] Actionlib request
   * \param[out] Timeout
   * \param[out] Distance xy
   */
  void computeTimeoutAndDistance(const cola2_msgs::action::Pilot::Goal &, double &, double &);

  /**
   * \brief Main section method that is called at each iteration from the main timer
   */
  void section();

  /**
   * \brief This method checks and enables a mission request
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableMission(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response);

  /**
   * \brief Main mission method that is called at each iteration from the main timer
   */
  void mission();

  /**
   * \brief This method checks the mission step count to see if it has finalized
   * \return It returns true if it has finalized and false otherwise
   */
  bool missionHasFinished();

  /**
   * \brief Main keep position method that is called at each iteration from the main timer
   */
  void keepPosition();

  /**
   * \brief Main safety keep position method that is called at each iteration from the main timer
   */
  void safetyKeepPosition();

  /**
   * \brief Enable goto maneuver
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableGotoSrv(const std::shared_ptr<cola2_msgs::srv::Goto::Request> request, std::shared_ptr<cola2_msgs::srv::Goto::Response> response);

  /**
   * \brief Disable goto maneuver
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableGotoSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Enable section maneuver
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableSectionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<cola2_msgs::srv::Section::Request> req, std::shared_ptr<cola2_msgs::srv::Section::Response> res);

  /**
   * \brief Disable section maneuver
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableSectionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Enable mission
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableMissionSrv(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response);

  /**
   * \brief Disable mission
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableMissionSrv(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response);

  /**
   * \brief This method disables an active mission
   */
  void disableMissionHelper();

  /**
   * \brief Resume mission
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool resumeMissionSrv(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response);

  /**
   * \brief Pause mission
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool pauseMissionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Enable keep position for surge, sway, heave and yaw DoFs
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableKeepPositionHolonomicSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Enable keep position for surge, heave, and yaw DoFs
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableKeepPositionNonHolonomicSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Disable keep position
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Enable safety keep position for surge, heave, and yaw DoFs
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableSafetyKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Disable safety keep position
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableSafetyKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Disable all keep positions
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableAllKeepPositionsSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Reset keep position
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool resetKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Allows an external controller to 'fake' that a mission is under execution
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool enableExternalMissionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Finalizes the external mission
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableExternalMissionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Disables everything so that the state becomes idle
   * \param[in] Request
   * \param[out] Response
   * \return Success
   */
  bool disableAllAndSetIdleSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Service to reload parameters from ROS param server
   * \param[in] Request
   * \param[out] Response
   */
  bool reloadParamsCallback(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  /**
   * \brief Load parameters from ROS param server
   * \return Returns true if all parameters were found and false otherwise
   */
  bool getConfig();

  void goal_response_callback(std::shared_ptr<GoalHandlePilot> goal_handle);
  void feedback_callback(std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback);
  void result_callback(const GoalHandlePilot::WrappedResult &result);

public:
  /**
   * \brief Class constructor
   */
  Captain();

  void init();

  /**
   * \brief Class destructor
   */
  ~Captain();
};

Captain::Captain()
    : Node("captain"), is_pilot_actionlib_running_(false), state_(CaptainStates::Idle), last_nav_received_(0.0), position_checking_time_(0.0), goto_enabled_(false), section_enabled_(false), approach_completed_(false), step_completed_(false)
{
  // Wait for time
  while (this->get_clock()->now().seconds() == 0.0)
  {
    RCLCPP_INFO(this->get_logger(), "Waiting for valid time source");
  }
}

void Captain::init()
{

  controller_params_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("controller/get_parameters");
  pilot_params_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("pilot/get_parameters");
  // Get config. It must be valid, at least the first time
  if (!getConfig())
  {
    RCLCPP_FATAL(this->get_logger(), "Invalid parameters in ROS param server. Shutting down");
    rclcpp::shutdown();
  }

  goal_asked_ = false;

  // Init state feedback
  goto_feedback_.name = "Goto";
  section_feedback_.name = "Section";
  mission_feedback_.name = "Mission";
  keep_position_feedback_.name = "Keep position";
  safety_keep_position_feedback_.name = "Safety keep position";
  goto_feedback_.id = 0;
  section_feedback_.id = 0;
  mission_feedback_.id = 0;
  keep_position_feedback_.id = 0;
  safety_keep_position_feedback_.id = 0;
  external_mission_feedback_id_ = 0;

  // Publishers
  pub_path_ = this->create_publisher<nav_msgs::msg::Path>(cola2::ros::getNamespace(shared_from_this()) + "/trajectory_path", 1);
  pub_captain_status_ = this->create_publisher<cola2_msgs::msg::CaptainStatus>(cola2::ros::getNamespace(shared_from_this()) + "/captain_status", 1);
  pub_captain_state_feedback_ = this->create_publisher<cola2_msgs::msg::CaptainStateFeedback>(cola2::ros::getNamespace(shared_from_this()) + "/state_feedback", 1);
  pub_mission_str_ = this->create_publisher<std_msgs::msg::String>(cola2::ros::getNamespace(shared_from_this()) + "/mission", 1);
  pub_joy_ = this->create_publisher<sensor_msgs::msg::Joy>("input_to_teleoperation/output", 10);

  // Subscribers
  sub_nav_ = this->create_subscription<cola2_msgs::msg::NavSts>("navigator/navigation", 10, std::bind(&Captain::updateNav, this, std::placeholders::_1));

  // Services
  enable_goto_srv_ = this->create_service<cola2_msgs::srv::Goto>(cola2::ros::getNamespace(shared_from_this()) + "/enable_goto", std::bind(&Captain::enableGotoSrv, this, std::placeholders::_1, std::placeholders::_2));
  disable_goto_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_goto", std::bind(&Captain::disableGotoSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_goto_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_goto");
  enable_section_srv_ = this->create_service<cola2_msgs::srv::Section>(cola2::ros::getNamespace(shared_from_this()) + "/enable_section", std::bind(&Captain::enableSectionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_section_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_section", std::bind(&Captain::disableSectionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_section_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_section");
  enable_mission_srv_ = this->create_service<cola2_msgs::srv::Mission>(cola2::ros::getNamespace(shared_from_this()) + "/enable_mission", std::bind(&Captain::enableMissionSrv, this, std::placeholders::_1, std::placeholders::_2));
  disable_mission_srv_ = this->create_service<cola2_msgs::srv::Mission>(cola2::ros::getNamespace(shared_from_this()) + "/disable_mission", std::bind(&Captain::disableMissionSrv, this, std::placeholders::_1, std::placeholders::_2));
  pause_mission_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/pause_mission", std::bind(&Captain::pauseMissionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  resume_mission_srv_ = this->create_service<cola2_msgs::srv::Mission>(cola2::ros::getNamespace(shared_from_this()) + "/resume_mission", std::bind(&Captain::resumeMissionSrv, this, std::placeholders::_1, std::placeholders::_2));
  enable_keep_position_holonomic_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_keep_position_holonomic", std::bind(&Captain::enableKeepPositionHolonomicSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  enable_keep_position_holonomic_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_keep_position_holonomic");
  enable_keep_position_non_holonomic_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_keep_position_non_holonomic", std::bind(&Captain::enableKeepPositionNonHolonomicSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  enable_keep_position_non_holonomic_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_keep_position_non_holonomic");
  disable_keep_position_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_keep_position", std::bind(&Captain::disableKeepPositionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_keep_position_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_keep_position");
  enable_safety_keep_position_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_safety_keep_position", std::bind(&Captain::enableSafetyKeepPositionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  enable_safety_keep_position_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_safety_keep_position");
  disable_safety_keep_position_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_safety_keep_position", std::bind(&Captain::disableSafetyKeepPositionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_safety_keep_position_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_safety_keep_position");
  disable_all_keep_positions_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_all_keep_positions", std::bind(&Captain::disableAllKeepPositionsSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  reset_keep_position_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/reset_keep_position", std::bind(&Captain::resetKeepPositionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  reset_keep_position_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/reset_keep_position");
  enable_external_mission_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/enable_external_mission", std::bind(&Captain::enableExternalMissionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_external_mission_srv_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_external_mission", std::bind(&Captain::disableExternalMissionSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_external_mission_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_external_mission");
  disable_all_and_set_idle_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_all_and_set_idle", std::bind(&Captain::disableAllAndSetIdleSrv, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  disable_all_and_set_idle_client_ = this->create_client<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/disable_all_and_set_idle");
  srv_reload_params_ = this->create_service<std_srvs::srv::Trigger>(cola2::ros::getNamespace(shared_from_this()) + "/reload_params", std::bind(&Captain::reloadParamsCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

  // Service client to publish parameters
  // const std::string publish_params_srv_name = cola2::ros::getNamespace(shared_from_this()) + "/param_logger/publish_params";
  // srv_publish_params_ = this->create_client<std_srvs::srv::Trigger>(publish_params_srv_name);

  // while (!srv_publish_params_->wait_for_service(std::chrono::seconds(5)))
  // {
  //   RCLCPP_INFO(this->get_logger(), "Waiting for client to service %s ", publish_params_srv_name.c_str());
  // }

  // Diagnostics timer
  diagnostics_timer_ = this->create_wall_timer(std::chrono::duration<double>(0.5), std::bind(&Captain::diagnosticsTimer, this));

  // Main timer
  main_timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&Captain::mainTimer, this));

  pilot_actionlib_ = rclcpp_action::create_client<pilot_action>(this, "pilot/actionlib");
  waitActionlib<pilot_action>(pilot_actionlib_, "pilot/actionlib");

  if (!this->pilot_actionlib_->wait_for_action_server())
  {
    RCLCPP_ERROR(this->get_logger(), "Pilot actionlib server not available after waiting");
    rclcpp::shutdown();
  }

  // Set the no altitude reactive behavior corresponding to the Idle state
  updateNoAltitudeGoesUpIdle(20.0);

  diagnostic_ = std::make_shared<cola2::ros::DiagnosticHelper>(shared_from_this(), "captain", cola2::ros::getUnresolvedNodeName(shared_from_this()));
  diagnostic_->setEnabled(true);
  RCLCPP_INFO(this->get_logger(), "Initialized");
}

Captain::~Captain()
{
  cancelPilotActionlib();
}

void Captain::goal_response_callback(std::shared_ptr<GoalHandlePilot> goal_handle)
{
  goal_handle_ = goal_handle;
  goal_asked_ = false;
  if (!goal_handle)
  {
    RCLCPP_ERROR(this->get_logger(), "Goal was rejected by pilot server");
  }
}

void Captain::feedback_callback(std::shared_ptr<GoalHandlePilot>, const std::shared_ptr<const pilot_action::Feedback> feedback)
{
  std::stringstream ss;
  ss << "Feedback received from pilot:\ndistance_to_end: " << feedback->distance_to_end << ", cross_track_error: " << feedback->cross_track_error;
}

void Captain::result_callback(const GoalHandlePilot::WrappedResult &result)
{
  std::stringstream ss;
  ss << "Result state: " << result.result->state;
}

void Captain::updateNoAltitudeGoesUp(const bool no_altitude_goes_up, const double wait_time)
{
  // if (no_altitude_goes_up)
  // {
  //   callTriggerService("/minig/" + cola2::ros::getNamespace(shared_from_this()) + "/" + config_.enable_no_altitude_goes_up_service, 5.0, wait_time);
  // }
  // else
  // {
  //   callTriggerService("/minig/" + cola2::ros::getNamespace(shared_from_this()) + "/" + config_.disable_no_altitude_goes_up_service, 5.0, wait_time);
  // }
}

void Captain::updateNoAltitudeGoesUpIdle(const double wait_time)
{
  updateNoAltitudeGoesUp(config_.idle_no_altitude_goes_up, wait_time);
}

void Captain::disableTeleoperationPoseControllers()
{
  sensor_msgs::msg::Joy joy_msg;
  joy_msg.header.stamp = this->get_clock()->now();
  joy_msg.header.frame_id = "captain";
  joy_msg.axes.resize(12, 0.0);
  joy_msg.buttons.resize(6, false);
  joy_msg.buttons.resize(12, true);
  pub_joy_->publish(joy_msg);
}

template <typename T>
void Captain::waitActionlib(const typename rclcpp_action::Client<T>::SharedPtr &client, const std::string &name)
{
  const std::chrono::seconds timeout(5);
  const std::chrono::milliseconds retry_interval(500);

  while (rclcpp::ok())
  {
    try
    {
      if (client->wait_for_action_server(timeout))
      {
        break;
      }
    }
    catch (const std::exception &ex)
    {
      RCLCPP_WARN(this->get_logger(), "Action client wait_for_action_server() has thrown an exception (try updating your system): %s", ex.what());
      std::this_thread::sleep_for(retry_interval);
    }
    RCLCPP_INFO(this->get_logger(), "Waiting %s action server", name.c_str());
  }
}

bool Captain::callTriggerService(const std::string &srv_name, const double timeout, const double wait_time)
{
  try
  {
    std_srvs::srv::Trigger::Request req;
    std_srvs::srv::Trigger::Response res;
    const bool success = cola2::ros::callServiceWithTimeout<std_srvs::srv::Trigger>(shared_from_this(), req, res, srv_name, timeout, wait_time);
    if (!success)
    {
      RCLCPP_ERROR(this->get_logger(), "Trigger service %s call failed", srv_name.c_str());
    }
    else
    {
      if (!res.success)
      {
        RCLCPP_WARN(this->get_logger(), "Trigger service %s responded False with msg: %s", srv_name.c_str(), res.message.c_str());
      }
      else
        return true;
    }
  }
  catch (const std::exception &ex)
  {
    RCLCPP_ERROR(this->get_logger(), "Exception while calling trigger service %s : %s", srv_name.c_str(), ex.what());
  }
  return false;
}

void Captain::cancelPilotActionlib()
{

  if (is_pilot_actionlib_running_)
  {
    try
    {
      if (goal_handle_)
      {
        auto status = goal_handle_->get_status();
        if (!(status == rclcpp_action::GoalStatus::STATUS_SUCCEEDED || status == rclcpp_action::GoalStatus::STATUS_CANCELED || status == rclcpp_action::GoalStatus::STATUS_ABORTED))
        {
          auto cancel_action = pilot_actionlib_->async_cancel_goal(goal_handle_);
        }
      }
    }
    catch (const rclcpp_action::exceptions::UnknownGoalHandleError &e)
    {
      RCLCPP_ERROR(this->get_logger(), "UnknownGoalHandleError: %s", e.what());
    }
  }
  is_pilot_actionlib_running_ = false;
}

void Captain::updateNav(const cola2_msgs::msg::NavSts &nav_msg)
{
  // Check for valid navigation
  if (!cola2::ros::navigationIsValid(nav_msg))
  {
    return;
  }

  // Store navigation data
  nav_ = nav_msg;
  last_nav_received_ = this->get_clock()->now().seconds();

  // Checking for sudden changes in position approximately once per second
  if (position_checking_time_ == 0)
  {
    position_checking_north_ = nav_.position.north;
    position_checking_east_ = nav_.position.east;
    position_checking_time_ = last_nav_received_;
  }
  else if (last_nav_received_ - position_checking_time_ > 1.0)
  {
    // TODO: What follows is ugly. It also does not account for the keep positions inside a mission...
    const double dist = std::sqrt(std::pow(nav_.position.north - position_checking_north_, 2) +
                                  std::pow(nav_.position.east - position_checking_east_, 2));
    if (dist > 10.0) // TODO: Param? Maybe not, as it is going to be one of those that is never changed
    {
      RCLCPP_WARN(this->get_logger(), "Detected a sudden jump in the navigation position of %f meters in less than one second", dist);
      if (config_.reset_keep_position_on_navigation_jump)
      {
        auto request = std::make_shared<std_srvs::srv::Trigger::Request>();
        auto future = reset_keep_position_client_->async_send_request(request);
        // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
      }
    }
    position_checking_north_ = nav_.position.north;
    position_checking_east_ = nav_.position.east;
    position_checking_time_ = last_nav_received_;
  }
}

void Captain::diagnosticsTimer()
{
  const bool keep_position_enabled = (state_ == CaptainStates::KeepPosition) || (state_ == CaptainStates::SafetyKeepPosition);
  const bool trajectory_enabled = (state_ == CaptainStates::Goto) || (state_ == CaptainStates::Section) ||
                                  (state_ == CaptainStates::Mission) || (state_ == CaptainStates::ExternalMission);
  diagnostic_->addKeyValue("keep_position_enabled", keep_position_enabled);
  diagnostic_->addKeyValue("trajectory_enabled", trajectory_enabled);
  diagnostic_->setLevelAndMessage(diagnostic_msgs::msg::DiagnosticStatus::OK);
  diagnostic_->reportValidData(this->get_clock()->now());
  diagnostic_->publish(shared_from_this());
}

void Captain::mainTimer()
{
  mainIteration();
}

void Captain::mainIteration()
{
  // Check navigation
  if (state_ != CaptainStates::Idle)
  {
    if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
    {
      RCLCPP_WARN(this->get_logger(), "Navigation too old or never received");
      // Disable everything?
    }
  }

  // Perform actions
  if (state_ == CaptainStates::Goto)
  {
    goTo();
    if (pilotHasFinished())
    {
      RCLCPP_INFO(this->get_logger(), "Goto finalized");
      state_ = CaptainStates::Idle;
      updateNoAltitudeGoesUpIdle();

      // Feedback
      goto_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::SUCCESS;
      goto_feedback_.header.stamp = this->get_clock()->now();
      pub_captain_state_feedback_->publish(goto_feedback_);
      ++goto_feedback_.id;
    }
  }
  else if (state_ == CaptainStates::Section)
  {
    section();
    if (pilotHasFinished())
    {
      RCLCPP_INFO(this->get_logger(), "Section finalized");
      state_ = CaptainStates::Idle;
      updateNoAltitudeGoesUpIdle();

      // Feedback
      section_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::SUCCESS;
      section_feedback_.header.stamp = this->get_clock()->now();
      pub_captain_state_feedback_->publish(section_feedback_);
      ++section_feedback_.id;
    }
  }
  else if (state_ == CaptainStates::Mission)
  {
    mission();
    if (missionHasFinished())
    {
      RCLCPP_INFO(this->get_logger(), "Mission finalized: %s", last_running_mission_.c_str());
      state_ = CaptainStates::Idle;
      updateNoAltitudeGoesUpIdle();
      deleteLoadedMission(last_running_mission_);

      // Feedback
      mission_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::SUCCESS;
      mission_feedback_.header.stamp = this->get_clock()->now();
      pub_captain_state_feedback_->publish(mission_feedback_);
      ++mission_feedback_.id;
    }
  }
  else if (state_ == CaptainStates::KeepPosition)
  {
    keepPosition();
    if (pilotHasFinished())
    {
      RCLCPP_INFO(this->get_logger(), "KeepPosition finalized");
      state_ = CaptainStates::Idle;
      updateNoAltitudeGoesUpIdle();

      // Feedback
      keep_position_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::SUCCESS;
      keep_position_feedback_.header.stamp = this->get_clock()->now();
      pub_captain_state_feedback_->publish(keep_position_feedback_);
      ++keep_position_feedback_.id;
    }
  }
  else if (state_ == CaptainStates::SafetyKeepPosition)
  {
    safetyKeepPosition();
    if (pilotHasFinished())
    {
      RCLCPP_ERROR(this->get_logger(), "SafetyKeepPosition finalized"); // This should not happen
      state_ = CaptainStates::Idle;
      updateNoAltitudeGoesUpIdle();

      // Feedback
      safety_keep_position_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::SUCCESS;
      safety_keep_position_feedback_.header.stamp = this->get_clock()->now();
      pub_captain_state_feedback_->publish(safety_keep_position_feedback_);
      ++safety_keep_position_feedback_.id;
    }
  }
  else if (state_ == CaptainStates::ExternalMission)
  {
    // Nothing
  }

  // Publish captain status
  cola2_msgs::msg::CaptainStatus captain_status_msg;
  captain_status_msg.header.stamp = this->get_clock()->now();
  if (state_ == CaptainStates::Idle)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::IDLE;
  }
  else if (state_ == CaptainStates::Goto)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::GOTO;
  }
  else if (state_ == CaptainStates::Section)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::SECTION;
  }
  else if (state_ == CaptainStates::Mission)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::MISSION;
    captain_status_msg.message = "Mission name: " + last_running_mission_;
  }
  else if (state_ == CaptainStates::KeepPosition)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::KEEPPOSITION;
  }
  else if (state_ == CaptainStates::SafetyKeepPosition)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::SAFETYKEEPPOSITION;
  }
  else if (state_ == CaptainStates::ExternalMission)
  {
    captain_status_msg.state = cola2_msgs::msg::CaptainStatus::EXTERNALMISSION;
    captain_status_msg.message = "External mission caller name: " + external_mission_caller_name_;
  }
  for (const auto &name_mission : loaded_missions_)
  {
    cola2_msgs::msg::MissionState mission_state;
    mission_state.name = name_mission.first;
    mission_state.last_active = name_mission.second.last_active;
    mission_state.current_step = name_mission.second.current_step;
    captain_status_msg.loaded_missions.push_back(mission_state);
  }
  pub_captain_status_->publish(captain_status_msg);
}

void Captain::executePendingActions(std::string mission_name)
{
  Mission &mission = loaded_missions_[mission_name].mission;
  while (loaded_missions_[mission_name].current_step < mission.size())
  {
    auto step = mission.getStep(loaded_missions_[mission_name].current_step);
    std::vector<MissionAction> actions = step->getActions();
    for (const auto &action : actions)
    {
      if (!rclcpp::ok())
      {
        return;
      }
      callAction(action.getIsTrigger(), action.getActionId(), action.getParameters());
      /*ros::Duration(2.0).sleep();*/
    }
    ++loaded_missions_[mission_name].current_step;
  }
}

std::string Captain::getDefaultMissionName()
{
  std::string output;
  const std::string package_path = ament_index_cpp::get_package_share_directory(config_.vehicle_config_launch_mission_package);
  if (package_path.empty())
  {
    RCLCPP_ERROR(this->get_logger(), "Error defining mission package path");
    return output;
  }
  const std::string mission_path = package_path + "/missions/default_mission.xml";
  if (!cola2::utils::isFileAccessible(mission_path))
  {
    RCLCPP_ERROR(this->get_logger(), "Default mission path not accessible");
    return output;
  }
  if (cola2::utils::isSymlink(mission_path))
  {
    output = cola2::utils::getSymlinkTarget(mission_path);
  }
  else
  {
    output = "default_mission.xml";
  }
  return output;
}

nav_msgs::msg::Path Captain::createPathFromMission(Mission mission)
{
  // Create path from mission using NED
  nav_msgs::msg::Path path;
  path.header.stamp = this->get_clock()->now();
  path.header.frame_id = "world_ned";
  cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
  for (std::size_t i = 0; i < mission.size(); ++i)
  {
    geometry_msgs::msg::PoseStamped pose;
    pose.header.frame_id = path.header.frame_id;
    double x, y, z;
    ned.geodetic2Ned(mission.getStep(i)->getManeuverPtr()->x(), mission.getStep(i)->getManeuverPtr()->y(), 0.0, x, y, z);
    pose.pose.position.x = x;
    pose.pose.position.y = y;
    pose.pose.position.z = mission.getStep(i)->getManeuverPtr()->z();
    path.poses.push_back(pose);
  }
  return path;
}

void Captain::callAction(const bool is_trigger, const std::string &action_id, const std::vector<std::string> parameters)
{
  if (is_trigger)
  {
    RCLCPP_INFO(this->get_logger(), "Calling trigger service with id %s", action_id.c_str());
    callTriggerService(action_id, 5.0, 1.0);
  }
  else
  {
    RCLCPP_INFO(this->get_logger(), "Calling action service with id %s", action_id.c_str());
    try
    {
      cola2_msgs::srv::Action::Request req;
      cola2_msgs::srv::Action::Response res;
      if (parameters.size() % 2 != 0)
      {
        RCLCPP_WARN(this->get_logger(), "Action service %s is being called with an odd number of strings", action_id.c_str());
      }
      for (const auto &param : parameters)
      {
        req.param.push_back(param);
      }
      const bool success = cola2::ros::callServiceWithTimeout<cola2_msgs::srv::Action>(shared_from_this(), req, res, action_id, 5.0, 1.0);
      if (!success)
      {
        RCLCPP_ERROR(this->get_logger(), "Action service %s call failed", action_id.c_str());
      }
      else
      {
        if (!res.success)
        {
          RCLCPP_WARN(this->get_logger(), "Action service %s responded False with msg: %s", action_id.c_str(), res.message.c_str());
        }
      }
    }
    catch (const std::exception &ex)
    {
      RCLCPP_ERROR(this->get_logger(), "Exception while calling action service %s : %s", action_id.c_str(), ex.what());
    }
  }
}

void Captain::goTo()
{
  // Feedback
  goto_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::ACTIVE;
  double timeout, distance_xy;
  computeTimeoutAndDistance(actionlib_request_, timeout, distance_xy);
  goto_feedback_.time_to_finish = timeout;
  goto_feedback_.header.stamp = this->get_clock()->now();
  setKeyValue(&goto_feedback_, "distance_to_end", std::to_string(distance_xy));
  pub_captain_state_feedback_->publish(goto_feedback_);
}

void Captain::computeTimeoutAndDistance(const cola2_msgs::action::Pilot::Goal &goal, double &timeout, double &distance)
{
  // Maximum DVL range = Maximum change in depth due to altitude. TODO: hardcoded value
  const double max_dvl_range = 200.0;

  // Extract initial and final xy
  cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
  double final_x, final_y, dummy_z;
  ned.geodetic2Ned(goal.final_latitude, goal.final_longitude, 0.0, final_x, final_y, dummy_z);

  // The "returned" distance is only the distance xy
  distance = std::sqrt(std::pow(final_x - nav_.position.north, 2) + std::pow(final_y - nav_.position.east, 2));

  // Penalize distance. When using a section, the vehicle might perform an L shape maneuver
  const double dist_xy = std::sqrt(2.0) * distance;

  // Compute distance z
  double dist_z = 0.0;
  if (goal.heave_mode == cola2_msgs::action::Pilot::Goal::DEPTH)
    dist_z = std::fabs(goal.final_depth - nav_.position.depth);
  else if (goal.heave_mode == cola2_msgs::action::Pilot::Goal::ALTITUDE)
    dist_z = max_dvl_range;
  else // BOTH
    dist_z = std::fabs(goal.final_depth - nav_.position.depth) + max_dvl_range;

  // Compute velocities
  const double x_vel =
      std::max(std::min(goal.surge_velocity, config_.pilot_section_max_surge_velocity), 0.001);
  const double z_vel = std::max(std::min(0.3, config_.controller_max_velocity_z), 0.001);

  // Compute timeout
  const double time_xy = dist_xy / x_vel;
  const double time_z = dist_z / z_vel;
  timeout = 2.0 * std::max(time_xy, time_z) + 30.0;

  // For the HOLONOMIC_KEEP_POSITION and ANCHOR controllers, the timeout is given by the user
  if ((goal.controller_type == cola2_msgs::action::Pilot::Goal::HOLONOMIC_KEEP_POSITION) ||
      (goal.controller_type == cola2_msgs::action::Pilot::Goal::ANCHOR))
    timeout = goal.timeout;
}

void Captain::section()
{
  // Feedback
  section_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::ACTIVE;
  double timeout, distance_xy;
  computeTimeoutAndDistance(actionlib_request_, timeout, distance_xy);
  section_feedback_.time_to_finish = timeout;
  section_feedback_.header.stamp = this->get_clock()->now();
  setKeyValue(&section_feedback_, "distance_to_end", std::to_string(distance_xy));
  pub_captain_state_feedback_->publish(section_feedback_);
}

bool Captain::pilotHasFinished()
{
  if (goal_asked_)
    return false;
  if (goal_handle_)
  {
    auto status = goal_handle_->get_status();
    is_pilot_actionlib_running_ = (status != rclcpp_action::GoalStatus::STATUS_SUCCEEDED && status != rclcpp_action::GoalStatus::STATUS_CANCELED && status != rclcpp_action::GoalStatus::STATUS_ABORTED);
    return !is_pilot_actionlib_running_;
  }
  return true; // If there's no active goal handle, consider the action finished
}

bool Captain::enableMission(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response)
{
  Mission mission;

  // Get path were missions are stored
  const std::string package_path = ament_index_cpp::get_package_share_directory(config_.vehicle_config_launch_mission_package);
  if (package_path.empty())
  {
    response->message = "Error defining mission path!";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return false;
  }
  const std::string mission_path = package_path + "/missions/" + request->mission;

  // Load mission
  try
  {
    RCLCPP_INFO(this->get_logger(), "Loading mission: %s", mission_path.c_str());
    mission.loadMission(mission_path);
    RCLCPP_INFO(this->get_logger(), "Mission loaded");
  }
  catch (const std::exception &ex)
  {
    response->message = std::string("Problem loading mission: ") + ex.what();
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return false;
  }

  // Check services in the mission before starting
  std::set<std::string> missing_services; // Use set to avoid reporting duplicates
  for (std::size_t i = 0; i < mission.size(); ++i)
  {
    std::vector<MissionAction> actions = mission.getStep(i)->getActions();
    for (const auto &action : actions)
    {
      if (!rclcpp::ok())
      {
        return true;
      }
      std::string action_id = action.getActionId();
      if (missing_services.find(action_id) != missing_services.end())
      {
        continue; // Already in missing_services
      }
      if (action.getIsTrigger())
      {
        auto action_client = this->create_client<std_srvs::srv::Trigger>(action_id);
        if (!action_client->wait_for_service(std::chrono::seconds(1)))
        {
          missing_services.insert(action_id);
        }
      }
      else
      {
        auto action_client = this->create_client<cola2_msgs::srv::Action>(action_id);
        if (!action_client->wait_for_service(std::chrono::seconds(1)))
        {
          missing_services.insert(action_id);
        }
      }
    }
  }
  if (!missing_services.empty())
  {
    response->message = "Problem loading mission. Missing services:";
    for (const auto &service : missing_services)
    {
      response->message += " " + service;
    }
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return false;
  }

  // Check distance to first waypoint in the mission
  cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
  if (mission.size() > 0)
  {
    double x, y, dummy_z;
    ned.geodetic2Ned(mission.getStep(0)->getManeuverPtr()->x(), mission.getStep(0)->getManeuverPtr()->y(), 0.0, x, y, dummy_z);
    const double distance_xy = std::sqrt(std::pow(x - nav_.position.north, 2) + std::pow(y - nav_.position.east, 2));
    if (distance_xy > config_.max_distance_to_waypoint)
    {
      response->message = "Problem loading mission. Distance between the the robot and the first waypoint is too large (" +
                          std::to_string(distance_xy) + " > " + std::to_string(config_.max_distance_to_waypoint) + " meters)";
      response->success = false;
      RCLCPP_ERROR(this->get_logger(), response->message.c_str());
      return false;
    }
  }

  // Check distance between points in the mission
  std::vector<std::size_t> waypoints_too_far_list;
  for (std::size_t i = 0; i + 1 < mission.size(); ++i)
  {
    double x1, y1, x2, y2, dummy_z;
    ned.geodetic2Ned(mission.getStep(i)->getManeuverPtr()->x(), mission.getStep(i)->getManeuverPtr()->y(), 0.0, x1, y1, dummy_z);
    ned.geodetic2Ned(mission.getStep(i + 1)->getManeuverPtr()->x(), mission.getStep(i + 1)->getManeuverPtr()->y(), 0.0, x2, y2, dummy_z);
    if (std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2)) > config_.max_distance_to_waypoint)
    {
      waypoints_too_far_list.push_back(i);
    }
  }
  if (!waypoints_too_far_list.empty())
  {
    response->message = "Problem loading mission. Distance between the following waypoint pairs is to large (>" + std::to_string(config_.max_distance_to_waypoint) + " meters):";
    for (const auto &waypoint : waypoints_too_far_list)
    {
      response->message += " [" + std::to_string(waypoint) + ", " + std::to_string(waypoint + 1) + "]";
    }
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return false;
  }

  // Publish mission as string
  try
  {
    std_msgs::msg::String mission_str_msg;
    std::ifstream ifs(mission_path.c_str(), std::ifstream::in);
    char c;
    while (ifs >> std::noskipws >> c)
    {
      mission_str_msg.data += c;
    }
    pub_mission_str_->publish(mission_str_msg);
  }
  catch (const std::exception &ex)
  {
    RCLCPP_ERROR(this->get_logger(), "Error publishing mission as string: %s", ex.what());
  }

  // Add it to the loaded missions
  MissionWithState mission_with_state;
  mission_with_state.mission = mission;
  mission_with_state.last_active = this->get_clock()->now();
  loaded_missions_.insert({request->mission, mission_with_state});

  // Return success
  response->message = "Enabled";
  response->success = true;
  return true;
}

void Captain::mission()
{
  // Create reference to mission
  Mission &mission = loaded_missions_[last_running_mission_].mission;

  // Feedback
  mission_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::ACTIVE;
  mission_feedback_.time_to_finish = 0.0;
  setKeyValue(&mission_feedback_, "current_step",
              std::to_string(loaded_missions_[last_running_mission_].current_step + 1));
  setKeyValue(&mission_feedback_, "total_steps", std::to_string(mission.size()));

  // Publish mission path
  nav_msgs::msg::Path path = createPathFromMission(mission);
  pub_path_->publish(path);

  // Main loop over mission steps
  if (loaded_missions_[last_running_mission_].current_step < mission.size())
  {
    // Update last active time
    loaded_missions_[last_running_mission_].last_active = this->get_clock()->now();

    // Get step pointer
    auto step = mission.getStep(loaded_missions_[last_running_mission_].current_step);

    // Play mission step maneuver
    if (step->getManeuverPtr()->getManeuverType() == MissionManeuver::GOTO_MANEUVER)
    {
      auto maneuver_goto = std::dynamic_pointer_cast<MissionGoto>(step->getManeuverPtr());

      // Feedback
      setKeyValue(&mission_feedback_, "active_controller", "Section");
      if (maneuver_goto->getHeaveMode() == MissionGoto::HeaveMode::DEPTH)
        setKeyValue(&mission_feedback_, "heave_mode", "DEPTH");
      else if (maneuver_goto->getHeaveMode() == MissionGoto::HeaveMode::ALTITUDE)
        setKeyValue(&mission_feedback_, "heave_mode", "ALTITUDE");
      else
        setKeyValue(&mission_feedback_, "heave_mode", "BOTH");

      if (!goto_enabled_)
      {
        RCLCPP_INFO(this->get_logger(), "Executing mission waypoint. Step %ld", loaded_missions_[last_running_mission_].current_step);
        goto_enabled_ = true;

        // Create actionlib request
        cola2_msgs::action::Pilot::Goal actionlib_request;
        actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
        actionlib_request.goal.requester = this->get_name();
        actionlib_request.initial_latitude = nav_.global_position.latitude;
        actionlib_request.initial_longitude = nav_.global_position.longitude;
        actionlib_request.final_latitude = maneuver_goto->getFinalLatitude();
        actionlib_request.final_longitude = maneuver_goto->getFinalLongitude();
        actionlib_request.final_yaw = 0.0;
        if (maneuver_goto->getHeaveMode() == MissionGoto::HeaveMode::DEPTH)
        {
          actionlib_request.initial_depth = nav_.position.depth;
          actionlib_request.final_depth = maneuver_goto->getFinalDepth();
          actionlib_request.final_altitude = 0.0;
          actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
        }
        else if (maneuver_goto->getHeaveMode() == MissionGoto::HeaveMode::ALTITUDE)
        {
          actionlib_request.initial_depth = 0.0;
          actionlib_request.final_depth = 0.0;
          actionlib_request.final_altitude = maneuver_goto->getFinalAltitude();
          actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::ALTITUDE;
        }
        else // BOTH
        {
          actionlib_request.initial_depth = nav_.position.depth;
          actionlib_request.final_depth = maneuver_goto->getFinalDepth();
          actionlib_request.final_altitude = maneuver_goto->getFinalAltitude();
          actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::BOTH;
        }
        actionlib_request.surge_velocity = maneuver_goto->getSurgeVelocity();
        actionlib_request.tolerance_xy = maneuver_goto->getToleranceXY();
        actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::SECTION;

        // Compute timeout and distance
        double distance_xy;
        computeTimeoutAndDistance(actionlib_request, actionlib_request.timeout, distance_xy);

        // Check distance
        if (distance_xy > config_.max_distance_to_waypoint)
        {
          RCLCPP_ERROR(this->get_logger(), "Mission waypoint failed. Distance too large");
          disableMissionHelper();
          return;
        }

        // Display message
        double final_north, final_east, dummy_z;
        cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
        ned.geodetic2Ned(maneuver_goto->getFinalLatitude(), maneuver_goto->getFinalLongitude(), 0.0, final_north,
                         final_east, dummy_z);
        if (maneuver_goto->getHeaveMode() == MissionGoto::HeaveMode::DEPTH)
        {
          RCLCPP_INFO(this->get_logger(), "Send waypoint request at [%f, %f] with depth %f. Timeout is %f seconds.",
                      final_north, final_east, actionlib_request.final_depth, actionlib_request.timeout);
        }
        else
        {
          RCLCPP_INFO(this->get_logger(), "Send waypoint request at [%f, %f] with altitude %f. Timeout is %f seconds.",
                      final_north, final_east, actionlib_request.final_altitude, actionlib_request.timeout);
        }

        // Update no altitude reactive behavior
        updateNoAltitudeGoesUp(maneuver_goto->getNoAltitudeGoesUp());

        // Call actionlib
        is_pilot_actionlib_running_ = true;
        auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
        pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
        {
          this->goal_response_callback(goal_handle);
        };
        pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
        {
          this->feedback_callback(goal_handle, feedback);
        };
        pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
        {
          this->result_callback(result);
        };
        pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
        goal_asked_ = true;
        actionlib_request_ = actionlib_request;
      }
      if (goto_enabled_ && pilotHasFinished())
      {
        RCLCPP_INFO(this->get_logger(), "Mission waypoint finalized");
        goto_enabled_ = false;
        step_completed_ = true;
      }
    }
    else if (step->getManeuverPtr()->getManeuverType() == MissionManeuver::SECTION_MANEUVER)
    {
      auto maneuver_sec = std::dynamic_pointer_cast<MissionSection>(step->getManeuverPtr());

      // Feedback
      setKeyValue(&mission_feedback_, "active_controller", "Section");
      if (maneuver_sec->getHeaveMode() == MissionSection::HeaveMode::DEPTH)
        setKeyValue(&mission_feedback_, "heave_mode", "DEPTH");
      else if (maneuver_sec->getHeaveMode() == MissionSection::HeaveMode::ALTITUDE)
        setKeyValue(&mission_feedback_, "heave_mode", "ALTITUDE");
      else
        setKeyValue(&mission_feedback_, "heave_mode", "BOTH");

      if (!section_enabled_)
      {
        RCLCPP_INFO(this->get_logger(), "Execute mission section. Step %ld", loaded_missions_[last_running_mission_].current_step);
        section_enabled_ = true;

        // Create actionlib request
        cola2_msgs::action::Pilot::Goal actionlib_request;
        actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
        actionlib_request.goal.requester = this->get_name();
        actionlib_request.initial_latitude = maneuver_sec->getInitialLatitude();
        actionlib_request.initial_longitude = maneuver_sec->getInitialLongitude();
        actionlib_request.final_latitude = maneuver_sec->getFinalLatitude();
        actionlib_request.final_longitude = maneuver_sec->getFinalLongitude();
        actionlib_request.final_yaw = 0.0;
        if (maneuver_sec->getHeaveMode() == MissionSection::HeaveMode::DEPTH)
        {
          actionlib_request.initial_depth = maneuver_sec->getInitialDepth();
          actionlib_request.final_depth = maneuver_sec->getFinalDepth();
          actionlib_request.final_altitude = 0.0;
          actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
        }
        else if (maneuver_sec->getHeaveMode() == MissionSection::HeaveMode::ALTITUDE)
        {
          actionlib_request.initial_depth = 0.0;
          actionlib_request.final_depth = 0.0;
          actionlib_request.final_altitude = maneuver_sec->getFinalAltitude();
          actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::ALTITUDE;
        }
        else // BOTH
        {
          actionlib_request.initial_depth = maneuver_sec->getInitialDepth();
          actionlib_request.final_depth = maneuver_sec->getFinalDepth();
          actionlib_request.final_altitude = maneuver_sec->getFinalAltitude();
          actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::BOTH;
        }
        actionlib_request.surge_velocity = maneuver_sec->getSurgeVelocity();
        actionlib_request.tolerance_xy = maneuver_sec->getToleranceXY();
        actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::SECTION;

        // Compute timeout and distance
        double distance_xy;
        computeTimeoutAndDistance(actionlib_request, actionlib_request.timeout, distance_xy);

        // Check distance
        if (distance_xy > config_.max_distance_to_waypoint)
        {
          RCLCPP_ERROR(this->get_logger(), "Mission section failed. Distance too large");
          disableMissionHelper();
          return;
        }

        // Display message
        double initial_north, initial_east, final_north, final_east, dummy_z;
        cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
        ned.geodetic2Ned(maneuver_sec->getInitialLatitude(), maneuver_sec->getInitialLongitude(), 0.0, initial_north, initial_east, dummy_z);
        ned.geodetic2Ned(maneuver_sec->getFinalLatitude(), maneuver_sec->getFinalLongitude(), 0.0, final_north, final_east, dummy_z);
        if (maneuver_sec->getHeaveMode() == MissionSection::HeaveMode::DEPTH)
        {
          RCLCPP_INFO(this->get_logger(), "Send section request from [%f, %f] to [%f, %f] with depth from %f to %f. Timeout is %f seconds.",
                      initial_north, initial_east, final_north, final_east, actionlib_request.initial_depth, actionlib_request.final_depth, actionlib_request.timeout);
        }
        else
        {
          RCLCPP_INFO(this->get_logger(), "Send section request from [%f, %f] to [%f, %f] with altitude from %f to %f. Timeout is %f seconds.",
                      initial_north, initial_east, final_north, final_east, actionlib_request.initial_depth, actionlib_request.final_altitude, actionlib_request.timeout);
        }

        // Update no altitude reactive behavior
        updateNoAltitudeGoesUp(maneuver_sec->getNoAltitudeGoesUp());

        // Call actionlib
        is_pilot_actionlib_running_ = true;
        auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
        pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
        {
          this->goal_response_callback(goal_handle);
        };
        pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
        {
          this->feedback_callback(goal_handle, feedback);
        };
        pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
        {
          this->result_callback(result);
        };
        pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
        goal_asked_ = true;
        actionlib_request_ = actionlib_request;
      }
      if (section_enabled_ && pilotHasFinished())
      {
        RCLCPP_INFO(this->get_logger(), "Mission section finalized");
        section_enabled_ = false;
        step_completed_ = true;
      }
    }
    else if (step->getManeuverPtr()->getManeuverType() == MissionManeuver::PARK_MANEUVER)
    {
      auto maneuver_park = std::dynamic_pointer_cast<MissionPark>(step->getManeuverPtr());

      // Feedback
      if (maneuver_park->getUseYaw())
        setKeyValue(&mission_feedback_, "active_controller", "Holonomic keep position");
      else
        setKeyValue(&mission_feedback_, "active_controller", "Anchor");
      if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::DEPTH)
        setKeyValue(&mission_feedback_, "heave_mode", "DEPTH");
      else if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::ALTITUDE)
        setKeyValue(&mission_feedback_, "heave_mode", "ALTITUDE");
      else
        setKeyValue(&mission_feedback_, "heave_mode", "BOTH");

      if (!approach_completed_)
      {
        // Approach
        if (!goto_enabled_)
        {
          RCLCPP_INFO(this->get_logger(), "Executing mission park approach. Step %ld", loaded_missions_[last_running_mission_].current_step);
          goto_enabled_ = true;

          // Create actionlib request
          cola2_msgs::action::Pilot::Goal actionlib_request;
          actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
          actionlib_request.goal.requester = this->get_name();
          actionlib_request.initial_latitude = nav_.global_position.latitude;
          actionlib_request.initial_longitude = nav_.global_position.longitude;
          actionlib_request.final_latitude = maneuver_park->getFinalLatitude();
          actionlib_request.final_longitude = maneuver_park->getFinalLongitude();
          actionlib_request.final_yaw = 0.0;
          if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::DEPTH)
          {
            actionlib_request.initial_depth = nav_.position.depth;
            actionlib_request.final_depth = maneuver_park->getFinalDepth();
            actionlib_request.final_altitude = 0.0;
            actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
          }
          else if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::ALTITUDE)
          {
            actionlib_request.initial_depth = 0.0;
            actionlib_request.final_depth = 0.0;
            actionlib_request.final_altitude = maneuver_park->getFinalAltitude();
            actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::ALTITUDE;
          }
          else // BOTH
          {
            actionlib_request.initial_depth = nav_.position.depth;
            actionlib_request.final_depth = maneuver_park->getFinalDepth();
            actionlib_request.final_altitude = maneuver_park->getFinalAltitude();
            actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::BOTH;
          }
          actionlib_request.surge_velocity = maneuver_park->getSurgeVelocity();
          actionlib_request.tolerance_xy = 3.0; // Fixed tolerance for park, as it is only to transition between modes
          actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::SECTION;

          // Compute timeout and distance
          double distance_xy;
          computeTimeoutAndDistance(actionlib_request, actionlib_request.timeout, distance_xy);

          // Check distance
          if (distance_xy > config_.max_distance_to_waypoint)
          {
            RCLCPP_ERROR(this->get_logger(), "Mission park approach failed. Distance too large");
            disableMissionHelper();
            return;
          }

          // Display message
          double final_north, final_east, dummy_z;
          cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
          ned.geodetic2Ned(maneuver_park->getFinalLatitude(), maneuver_park->getFinalLongitude(), 0.0, final_north,
                           final_east, dummy_z);
          if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::DEPTH)
          {
            RCLCPP_INFO(this->get_logger(), "Send park approach request at [%f, %f] with depth %f. Timeout is %f seconds.",
                        final_north, final_east, actionlib_request.final_depth, actionlib_request.timeout);
          }
          else
          {
            RCLCPP_INFO(this->get_logger(), "Send park approach request at [%f, %f] with altitude %f. Timeout is %f seconds.",
                        final_north, final_east, actionlib_request.final_altitude, actionlib_request.timeout);
          }

          // Update no altitude reactive behavior
          updateNoAltitudeGoesUp(maneuver_park->getNoAltitudeGoesUp());

          // Call actionlib
          is_pilot_actionlib_running_ = true;
          auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
          pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
          {
            this->goal_response_callback(goal_handle);
          };
          pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
          {
            this->feedback_callback(goal_handle, feedback);
          };
          pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
          {
            this->result_callback(result);
          };
          pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
          goal_asked_ = true;
          actionlib_request_ = actionlib_request;
        }
        if (goto_enabled_ && pilotHasFinished())
        {
          RCLCPP_INFO(this->get_logger(), "Mission park approach finalized");
          goto_enabled_ = false;
          approach_completed_ = true;
        }
      }
      else
      {
        // Keep position
        if (!goto_enabled_)
        {
          RCLCPP_INFO(this->get_logger(), "Executing mission park wait for %f seconds. Step %ld", maneuver_park->getTime(), loaded_missions_[last_running_mission_].current_step);
          goto_enabled_ = true;

          // Create actionlib request
          cola2_msgs::action::Pilot::Goal actionlib_request;
          actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
          actionlib_request.goal.requester = this->get_name();
          actionlib_request.initial_latitude = nav_.global_position.latitude;
          actionlib_request.initial_longitude = nav_.global_position.longitude;
          actionlib_request.final_latitude = maneuver_park->getFinalLatitude();
          actionlib_request.final_longitude = maneuver_park->getFinalLongitude();
          if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::DEPTH)
          {
            actionlib_request.initial_depth = nav_.position.depth;
            actionlib_request.final_depth = maneuver_park->getFinalDepth();
            actionlib_request.final_altitude = 0.0;
            actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
          }
          else if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::ALTITUDE)
          {
            actionlib_request.initial_depth = 0.0;
            actionlib_request.final_depth = 0.0;
            actionlib_request.final_altitude = maneuver_park->getFinalAltitude();
            actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::ALTITUDE;
          }
          else // BOTH
          {
            actionlib_request.initial_depth = nav_.position.depth;
            actionlib_request.final_depth = maneuver_park->getFinalDepth();
            actionlib_request.final_altitude = maneuver_park->getFinalAltitude();
            actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::BOTH;
          }
          actionlib_request.surge_velocity = maneuver_park->getSurgeVelocity();
          actionlib_request.tolerance_xy = 0.0;
          actionlib_request.timeout = static_cast<double>(maneuver_park->getTime());
          if (maneuver_park->getUseYaw())
          {
            actionlib_request.final_yaw = maneuver_park->getFinalYaw();
            actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::HOLONOMIC_KEEP_POSITION;
          }
          else
          {
            actionlib_request.final_yaw = 0.0;
            actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::ANCHOR;
          }

          // Compute timeout and distance
          double dummy_timeout, distance_xy;
          computeTimeoutAndDistance(actionlib_request, dummy_timeout, distance_xy);

          // Check distance
          if (distance_xy > config_.max_distance_to_waypoint)
          {
            RCLCPP_ERROR(this->get_logger(), "Mission park failed. Distance too large");
            disableMissionHelper();
            return;
          }

          // Display message
          double final_north, final_east, dummy_z;
          cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
          ned.geodetic2Ned(maneuver_park->getFinalLatitude(), maneuver_park->getFinalLongitude(), 0.0, final_north,
                           final_east, dummy_z);
          if (maneuver_park->getHeaveMode() == MissionPark::HeaveMode::DEPTH)
          {
            RCLCPP_INFO(this->get_logger(), "Send park request at [%f, %f] with depth %f. Timeout is %f seconds.",
                        final_north, final_east, actionlib_request.final_depth, actionlib_request.timeout);
          }
          else
          {
            RCLCPP_INFO(this->get_logger(), "Send park request at [%f, %f] with altitude %f. Timeout is %f seconds.",
                        final_north, final_east, actionlib_request.final_altitude, actionlib_request.timeout);
          }

          // Update no altitude reactive behavior
          updateNoAltitudeGoesUp(maneuver_park->getNoAltitudeGoesUp());

          // Call actionlib
          is_pilot_actionlib_running_ = true;
          auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
          pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
          {
            this->goal_response_callback(goal_handle);
          };
          pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
          {
            this->feedback_callback(goal_handle, feedback);
          };
          pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
          {
            this->result_callback(result);
          };
          pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
          goal_asked_ = true;
          actionlib_request_ = actionlib_request;
        }
        if (goto_enabled_ && pilotHasFinished())
        {
          RCLCPP_INFO(this->get_logger(), "Mission park wait finalized");
          goto_enabled_ = false;
          approach_completed_ = false;
          step_completed_ = true;
        }
      }
    }

    // Publish feedback
    mission_feedback_.header.stamp = this->get_clock()->now();
    pub_captain_state_feedback_->publish(mission_feedback_);

    // Check if the step maneuvers are done
    if (step_completed_)
    {
      // Call actions
      const std::vector<MissionAction> actions = step->getActions();
      for (const auto &action : actions)
      {
        if (!rclcpp::ok())
        {
          return;
        }
        callAction(action.getIsTrigger(), action.getActionId(), action.getParameters());
        /*ros::Duration(2.0).sleep();*/
      }

      // Increment step
      ++loaded_missions_[last_running_mission_].current_step;
      step_completed_ = false;
    }
  }
}

bool Captain::missionHasFinished()
{
  return (loaded_missions_[last_running_mission_].current_step >=
          loaded_missions_[last_running_mission_].mission.size());
}

void Captain::keepPosition()
{
  // Feedback
  keep_position_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::ACTIVE;
  keep_position_feedback_.time_to_finish = last_keep_position_duration_ - (this->get_clock()->now().seconds() - last_keep_position_time_);
  keep_position_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(keep_position_feedback_);
}

void Captain::safetyKeepPosition()
{
  // Feedback
  safety_keep_position_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::ACTIVE;
  safety_keep_position_feedback_.time_to_finish = last_keep_position_duration_ - (this->get_clock()->now().seconds() - last_keep_position_time_);
  safety_keep_position_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(safety_keep_position_feedback_);
}

bool Captain::enableGotoSrv(const std::shared_ptr<cola2_msgs::srv::Goto::Request> request, std::shared_ptr<cola2_msgs::srv::Goto::Response> response)
{
  // Check current state
  if (state_ != CaptainStates::Idle)
  {
    response->message = "Impossible to enable goto. Something is already running";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Check for navigation
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    response->message = "Impossible to enable goto. Navigation too old or never received";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Check reference frame
  if ((request->reference != cola2_msgs::srv::Goto::Request::NED) && (request->reference != cola2_msgs::srv::Goto::Request::GLOBAL))
  {
    response->message = "Impossible to enable goto. Invalid reference frame";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Create actionlib request
  cola2_msgs::action::Pilot::Goal actionlib_request;
  actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
  actionlib_request.goal.requester = this->get_name();
  actionlib_request.initial_latitude = nav_.global_position.latitude;
  actionlib_request.initial_longitude = nav_.global_position.longitude;
  actionlib_request.initial_depth = nav_.position.depth;
  if (request->reference == cola2_msgs::srv::Goto::Request::NED)
  {
    cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
    double dummy_z;
    ned.ned2Geodetic(request->final_x, request->final_y, 0.0, actionlib_request.final_latitude, actionlib_request.final_longitude, dummy_z);
  }
  else
  {
    actionlib_request.final_latitude = request->final_x;
    actionlib_request.final_longitude = request->final_y;
  }
  actionlib_request.final_depth = request->final_depth;
  actionlib_request.final_yaw = 0.0;
  actionlib_request.final_altitude = request->final_altitude;
  if (request->heave_mode == cola2_msgs::srv::Goto::Request::DEPTH)
    actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
  else if (request->heave_mode == cola2_msgs::srv::Goto::Request::ALTITUDE)
    actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::ALTITUDE;
  else if (request->heave_mode == cola2_msgs::srv::Goto::Request::BOTH)
    actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::BOTH;
  else
  {
    response->message = "Impossible to enable goto. Invalid heave mode";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }
  actionlib_request.surge_velocity = request->surge_velocity;
  actionlib_request.tolerance_xy = request->tolerance_xy;
  actionlib_request.timeout = request->timeout;
  actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::SECTION;

  // Compute timeout and distance
  double timeout, distance_xy;
  computeTimeoutAndDistance(actionlib_request, timeout, distance_xy);

  // Check distance
  if (distance_xy > config_.max_distance_to_waypoint)
  {
    response->message = "Impossible to enable goto. Distance too large";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Change timeout if required
  actionlib_request.timeout = std::min(actionlib_request.timeout, timeout);

  // Display message
  double final_north, final_east, dummy_z;
  cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
  ned.geodetic2Ned(actionlib_request.final_latitude, actionlib_request.final_longitude, 0.0, final_north, final_east, dummy_z);
  if (actionlib_request.heave_mode != cola2_msgs::action::Pilot::Goal::DEPTH)
  {
    RCLCPP_INFO(this->get_logger(), "Send waypoint request at [%f, %f] with altitude %f. Timeout is %f seconds.",
                final_north, final_east, actionlib_request.final_altitude, actionlib_request.timeout);
  }
  else
  {
    RCLCPP_INFO(this->get_logger(), "Send waypoint request at [%f, %f] with depth %f. Timeout is %f seconds.",
                final_north, final_east, actionlib_request.final_depth, actionlib_request.timeout);
  }

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  // Call actionlib
  is_pilot_actionlib_running_ = true;
  auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
  pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
  {
    this->goal_response_callback(goal_handle);
  };
  pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
  {
    this->feedback_callback(goal_handle, feedback);
  };
  pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
  {
    this->result_callback(result);
  };
  pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
  goal_asked_ = true;
  actionlib_request_ = actionlib_request;
  response->message = "Goto enabled";
  response->success = true;
  RCLCPP_INFO(this->get_logger(), response->message.c_str());
  state_ = CaptainStates::Goto;
  updateNoAltitudeGoesUp(request->no_altitude_goes_up);
  mainIteration();
  return true;
}

bool Captain::disableGotoSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ != CaptainStates::Goto)
  {
    res->message = "Impossible to disable goto. Captain not in goto state";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
    return true;
  }

  // Reset flags
  resetManeuverFlags();

  // Cancel actionlib
  cancelPilotActionlib();

  // Set captain state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  // Feedback
  goto_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::STOPPED;
  goto_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(goto_feedback_);
  ++goto_feedback_.id;

  res->message = "Goto disabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  mainIteration();
  return true;
}

bool Captain::enableSectionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<cola2_msgs::srv::Section::Request> req, std::shared_ptr<cola2_msgs::srv::Section::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ != CaptainStates::Idle)
  {
    res->message = "Impossible to enable section. Something is already running";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Check for navigation
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    res->message = "Impossible to enable section. Navigation too old or never received";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Check reference frame
  if ((req->reference != cola2_msgs::srv::Section::Request::NED) && (req->reference != cola2_msgs::srv::Section::Request::GLOBAL))
  {
    res->message = "Impossible to enable section. Invalid reference frame";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Create actionlib request
  cola2_msgs::action::Pilot::Goal actionlib_request;
  actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
  actionlib_request.goal.requester = this->get_name();
  if (req->reference == cola2_msgs::srv::Section::Request::NED)
  {
    cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
    double dummy_z;
    ned.ned2Geodetic(req->initial_x, req->initial_y, 0.0, actionlib_request.initial_latitude,
                     actionlib_request.initial_longitude, dummy_z);
    ned.ned2Geodetic(req->final_x, req->final_y, 0.0, actionlib_request.final_latitude, actionlib_request.final_longitude, dummy_z);
  }
  else
  {
    actionlib_request.initial_latitude = req->initial_x;
    actionlib_request.initial_longitude = req->initial_y;
    actionlib_request.final_latitude = req->final_x;
    actionlib_request.final_longitude = req->final_y;
  }
  actionlib_request.initial_depth = req->initial_depth;
  actionlib_request.final_depth = req->final_depth;
  actionlib_request.final_yaw = 0.0;
  actionlib_request.final_altitude = req->final_altitude;
  if (req->heave_mode == cola2_msgs::srv::Section::Request::DEPTH)
    actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
  else if (req->heave_mode == cola2_msgs::srv::Section::Request::ALTITUDE)
    actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::ALTITUDE;
  else if (req->heave_mode == cola2_msgs::srv::Section::Request::BOTH)
    actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::BOTH;
  else
  {
    res->message = "Impossible to enable section. Invalid heave mode";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }
  actionlib_request.surge_velocity = req->surge_velocity;
  actionlib_request.tolerance_xy = req->tolerance_xy;
  actionlib_request.timeout = req->timeout;
  actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::SECTION;

  // Compute timeout and distance
  double timeout, distance_xy;
  computeTimeoutAndDistance(actionlib_request, timeout, distance_xy);

  // Check distance
  if (distance_xy > config_.max_distance_to_waypoint)
  {
    res->message = "Impossible to enable section. Distance too large";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Change timeout if required
  actionlib_request.timeout = std::min(actionlib_request.timeout, timeout);

  // Display message
  double final_north, final_east, dummy_z;
  cola2::utils::NED ned(nav_.origin.latitude, nav_.origin.longitude, 0.0);
  ned.geodetic2Ned(actionlib_request.final_latitude, actionlib_request.final_longitude, 0.0, final_north, final_east, dummy_z);
  if (actionlib_request.heave_mode != cola2_msgs::action::Pilot::Goal::DEPTH)
  {
    RCLCPP_INFO(this->get_logger(), "Send section request at [%f, %f] with altitude %f. Timeout is %f seconds",
                final_north, final_east, actionlib_request.final_altitude, actionlib_request.timeout);
  }
  else
  {
    RCLCPP_INFO(this->get_logger(), "Send section request at [%f, %f] with depth %f. Timeout is %f seconds",
                final_north, final_east, actionlib_request.final_depth, actionlib_request.timeout);
  }

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  // Call actionlib
  is_pilot_actionlib_running_ = true;
  auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
  pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
  {
    this->goal_response_callback(goal_handle);
  };
  pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
  {
    this->feedback_callback(goal_handle, feedback);
  };
  pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
  {
    this->result_callback(result);
  };
  pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
  goal_asked_ = true;
  actionlib_request_ = actionlib_request;

  res->message = "Section enabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  state_ = CaptainStates::Section;
  updateNoAltitudeGoesUp(req->no_altitude_goes_up);
  mainIteration();
  return true;
}

bool Captain::disableSectionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ != CaptainStates::Section)
  {
    res->message = "Impossible to disable section. Captain not in section state";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
    return true;
  }

  // Reset flags
  resetManeuverFlags();

  // Cancel actionlib
  cancelPilotActionlib();

  // Set captain state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  // Feedback
  section_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::STOPPED;
  section_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(section_feedback_);
  ++section_feedback_.id;

  res->message = "Section disabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  mainIteration();
  return true;
}

bool Captain::enableMissionSrv(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response)
{
  // Check current state
  if (state_ != CaptainStates::Idle)
  {
    response->message = "Impossible to enable mission. Something is already running";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Check for navigation
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    response->message = "Impossible to enable mission. Navigation too old or never received";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Check mission name. If empty, use default mission name
  if (request->mission.empty())
  {
    request->mission = getDefaultMissionName();
    if (request->mission.empty())
    {
      response->message = "Impossible to obtain default mission name";
      response->success = false;
      RCLCPP_ERROR(this->get_logger(), response->message.c_str());
      return true;
    }
    RCLCPP_INFO(this->get_logger(), "Enabling mission without name. Using %s", request->mission.c_str());
  }

  // Remove old mission with the same name
  deleteLoadedMission(request->mission);

  // Enable mission
  if (enableMission(request, response))
  {
    // Disable teleoperation pose controllers
    disableTeleoperationPoseControllers();

    RCLCPP_INFO(this->get_logger(), "Mission enabled");
    state_ = CaptainStates::Mission;
    last_running_mission_ = request->mission;
  }

  mainIteration();
  return true;
}

bool Captain::resumeMissionSrv(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response)
{
  // Check current state
  if (state_ != CaptainStates::Idle)
  {
    response->message = "Impossible to resume mission. Something is already running";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Check for navigation
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    response->message = "Impossible to resume mission. Navigation too old or never received";
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Check mission name. If empty, use default mission name
  if (request->mission.empty())
  {
    request->mission = getDefaultMissionName();
    if (request->mission.empty())
    {
      response->message = "Impossible to obtain default mission name";
      response->success = false;
      RCLCPP_ERROR(this->get_logger(), response->message.c_str());
      return true;
    }
    RCLCPP_INFO(this->get_logger(), "Resuming mission without name. Using %s", request->mission.c_str());
  }

  // If the mission was not found, display a message and return
  if (loaded_missions_.find(request->mission) == loaded_missions_.end())
  {
    response->message = std::string("Impossible to resume ") + request->mission +
                        std::string(". This mission was disabled or has never been enabled");
    response->success = false;
    RCLCPP_ERROR(this->get_logger(), response->message.c_str());
    return true;
  }

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  // Set captain state
  state_ = CaptainStates::Mission;
  last_running_mission_ = request->mission;

  response->message = "Resuming mission: " + last_running_mission_;
  response->success = true;
  RCLCPP_INFO(this->get_logger(), response->message.c_str());
  mainIteration();
  return true;
}

void Captain::resetManeuverFlags()
{
  goto_enabled_ = false;
  section_enabled_ = false;
  approach_completed_ = false;
}

bool Captain::deleteLoadedMission(const std::string &mission_name)
{
  if (loaded_missions_.find(mission_name) != loaded_missions_.end())
  {
    loaded_missions_.erase(loaded_missions_.find(mission_name));
    return true;
  }
  return false;
}

bool Captain::pauseMissionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ != CaptainStates::Mission)
  {
    res->message = "Impossible to pause mission. Captain not in mission state";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
    return true;
  }

  // Reset flags
  resetManeuverFlags();

  // Cancel actionlib
  cancelPilotActionlib();

  // Change state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  res->message = "Mission paused: " + last_running_mission_;
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  mainIteration();
  return true;
}

void Captain::disableMissionHelper()
{
  // Cancel actionlib if necessary
  cancelPilotActionlib();

  // Execute pending actions
  executePendingActions(last_running_mission_);

  // Reset flags
  resetManeuverFlags();

  // Remove from loaded missions
  deleteLoadedMission(last_running_mission_);

  // Set captain state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  // Feedback
  mission_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::STOPPED;
  mission_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(mission_feedback_);
  ++mission_feedback_.id;
}

bool Captain::disableMissionSrv(const std::shared_ptr<cola2_msgs::srv::Mission::Request> request, std::shared_ptr<cola2_msgs::srv::Mission::Response> response)
{
  if ((state_ == CaptainStates::Mission) && (request->mission.empty() || (request->mission == last_running_mission_)))
  {
    // Disable mission
    disableMissionHelper();

    response->message = "Active mission disabled: " + last_running_mission_;
    response->success = true;
    RCLCPP_INFO(this->get_logger(), response->message.c_str());
    mainIteration();
    return true;
  }
  else if (request->mission.empty())
  {
    response->message = "Disable mission service with empty mission name does nothing when not in mission state";
    response->success = true;
    RCLCPP_INFO(this->get_logger(), response->message.c_str());
    return true;
  }
  else
  {
    // If found, execute pending actions and remove from loaded missions
    if (loaded_missions_.find(request->mission) != loaded_missions_.end())
    {
      executePendingActions(request->mission);
      deleteLoadedMission(request->mission);
      response->message = "Mission removed from paused missions: " + request->mission;
      RCLCPP_INFO(this->get_logger(), response->message.c_str());
    }
    else
    {
      response->message = "Mission not found. Nothing to remove";
      RCLCPP_INFO(this->get_logger(), response->message.c_str());
    }
    response->success = true;
    mainIteration();
    return true;
  }
}

bool Captain::enableKeepPositionHolonomicSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ == CaptainStates::KeepPosition)
  {
    res->message = "Keep position already enabled";
    res->success = true;
    RCLCPP_INFO(this->get_logger(), res->message.c_str());
    return true;
  }
  if (state_ != CaptainStates::Idle)
  {
    res->message = "Impossible to enable keep position. Something is already running";
    res->success = false;
    RCLCPP_INFO(this->get_logger(), res->message.c_str());
    return true;
  }

  // Check for navigation
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    res->message = "Impossible to enable keep position. Navigation too old or never received";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Create actionlib request
  cola2_msgs::action::Pilot::Goal actionlib_request;
  actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
  actionlib_request.goal.requester = this->get_name();
  actionlib_request.initial_latitude = nav_.global_position.latitude;
  actionlib_request.initial_longitude = nav_.global_position.longitude;
  actionlib_request.initial_depth = nav_.position.depth;
  actionlib_request.final_latitude = actionlib_request.initial_latitude;
  actionlib_request.final_longitude = actionlib_request.initial_longitude;
  actionlib_request.final_depth = actionlib_request.initial_depth;
  actionlib_request.final_yaw = nav_.orientation.yaw;
  actionlib_request.final_altitude = 0.0;
  actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
  actionlib_request.surge_velocity = 0.0;
  actionlib_request.tolerance_xy = 0.0;
  actionlib_request.timeout = 3600.0; // Wait value of one hour
  actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::HOLONOMIC_KEEP_POSITION;

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  // Call actionlib
  is_pilot_actionlib_running_ = true;
  auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
  pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
  {
    this->goal_response_callback(goal_handle);
  };
  pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
  {
    this->feedback_callback(goal_handle, feedback);
  };
  pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
  {
    this->result_callback(result);
  };
  pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
  goal_asked_ = true;
  actionlib_request_ = actionlib_request;

  res->message = "Holonomic keep position enabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), "Start holonomic keep position at [%f, %f, %f] with orientation %f", nav_.position.north, nav_.position.east, nav_.position.depth, nav_.orientation.yaw);

  state_ = CaptainStates::KeepPosition;
  last_keep_position_holonomic_ = true;
  updateNoAltitudeGoesUp(false);
  mainIteration();
  return true;
}

bool Captain::enableKeepPositionNonHolonomicSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ == CaptainStates::KeepPosition)
  {
    res->message = "Keep position already enabled";
    res->success = true;
    RCLCPP_INFO(this->get_logger(), res->message.c_str());
    return true;
  }
  if (state_ != CaptainStates::Idle)
  {
    res->message = "Impossible to enable keep position. Something is already running";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Check for navigation
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    res->message = "Impossible to enable keep position. Navigation too old or never received";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Create actionlib request
  cola2_msgs::action::Pilot::Goal actionlib_request;
  actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_NORMAL;
  actionlib_request.goal.requester = this->get_name();
  actionlib_request.initial_latitude = nav_.global_position.latitude;
  actionlib_request.initial_longitude = nav_.global_position.longitude;
  actionlib_request.initial_depth = nav_.position.depth;
  actionlib_request.final_latitude = actionlib_request.initial_latitude;
  actionlib_request.final_longitude = actionlib_request.initial_longitude;
  actionlib_request.final_depth = actionlib_request.initial_depth;
  actionlib_request.final_yaw = 0.0;
  actionlib_request.final_altitude = 0.0;
  actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
  actionlib_request.surge_velocity = 0.0;
  actionlib_request.tolerance_xy = 0.0;
  actionlib_request.timeout = 3600.0; // Wait value of one hour
  actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::ANCHOR;

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  // Call actionlib
  is_pilot_actionlib_running_ = true;
  auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
  pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
  {
    this->goal_response_callback(goal_handle);
  };
  pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
  {
    this->feedback_callback(goal_handle, feedback);
  };
  pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
  {
    this->result_callback(result);
  };
  pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
  goal_asked_ = true;
  actionlib_request_ = actionlib_request;

  res->message = "Non-holonomic keep position enabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), "Start non-holonomic keep position at [%f, %f, %f]", nav_.position.north, nav_.position.east, nav_.position.depth);

  state_ = CaptainStates::KeepPosition;
  last_keep_position_holonomic_ = false;
  updateNoAltitudeGoesUp(false);
  mainIteration();
  return true;
}

bool Captain::disableKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  if (state_ != CaptainStates::KeepPosition)
  {
    res->message = "Impossible to disable keep position. Captain not in keep position state";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
    return true;
  }

  // Reset flags
  resetManeuverFlags();

  // Cancel actionlib if necessary
  cancelPilotActionlib();

  // Set captain state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  // Feedback
  keep_position_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::STOPPED;
  keep_position_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(keep_position_feedback_);
  ++keep_position_feedback_.id;

  res->message = "Keep position disabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  mainIteration();
  return true;
}

bool Captain::enableSafetyKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ == CaptainStates::SafetyKeepPosition)
  {
    res->message = "Safety keep position already enabled";
    res->success = true;
    RCLCPP_INFO(this->get_logger(), res->message.c_str());
    return true;
  }

  // Disable everything
  auto request = std::make_shared<std_srvs::srv::Trigger::Request>();
  auto future = disable_all_and_set_idle_client_->async_send_request(request);
  // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);

  // Check for navigation. It is better to do this after disabling everything
  if (this->get_clock()->now().seconds() - last_nav_received_ > 5.0)
  {
    res->message = "Impossible to enable safety keep position. Navigation too old or never received";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Create actionlib request
  cola2_msgs::action::Pilot::Goal actionlib_request;
  actionlib_request.goal.priority = cola2_msgs::msg::GoalDescriptor::PRIORITY_SAFETY;
  actionlib_request.goal.requester = this->get_name();
  actionlib_request.initial_latitude = nav_.global_position.latitude;
  actionlib_request.initial_longitude = nav_.global_position.longitude;
  actionlib_request.initial_depth = nav_.position.depth;
  if (config_.safety_keep_position_goes_to_ned_origin)
  {
    RCLCPP_INFO(this->get_logger(), "Start safety keep position (non-holonomic) at [0, 0, %f]", config_.safety_keep_position_depth);
    actionlib_request.final_latitude = nav_.origin.latitude;
    actionlib_request.final_longitude = nav_.origin.longitude;
  }
  else
  {
    RCLCPP_INFO(this->get_logger(), "Start safety keep position (non-holonomic) at [%f, %f, %f]",
                nav_.position.north, nav_.position.east, config_.safety_keep_position_depth);
    actionlib_request.final_latitude = actionlib_request.initial_latitude;
    actionlib_request.final_longitude = actionlib_request.initial_longitude;
  }
  actionlib_request.final_depth = config_.safety_keep_position_depth;
  actionlib_request.final_yaw = 0.0;
  actionlib_request.final_altitude = 0.0;
  actionlib_request.heave_mode = cola2_msgs::action::Pilot::Goal::DEPTH;
  actionlib_request.surge_velocity = 0.0;
  actionlib_request.tolerance_xy = 0.0;
  actionlib_request.timeout = 1e6; // Effectively waiting forever
  actionlib_request.controller_type = cola2_msgs::action::Pilot::Goal::ANCHOR;

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  // Call actionlib
  is_pilot_actionlib_running_ = true;
  auto pilot_actionlib_options_ = rclcpp_action::Client<pilot_action>::SendGoalOptions();
  pilot_actionlib_options_.goal_response_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle)
  {
    this->goal_response_callback(goal_handle);
  };
  pilot_actionlib_options_.feedback_callback = [this](std::shared_ptr<GoalHandlePilot> goal_handle, const std::shared_ptr<const pilot_action::Feedback> feedback)
  {
    this->feedback_callback(goal_handle, feedback);
  };
  pilot_actionlib_options_.result_callback = [this](const rclcpp_action::ClientGoalHandle<pilot_action>::WrappedResult &result)
  {
    this->result_callback(result);
  };
  pilot_actionlib_->async_send_goal(actionlib_request, pilot_actionlib_options_);
  goal_asked_ = true;
  actionlib_request_ = actionlib_request;

  res->message = "Safety non-holonomic keep position enabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  state_ = CaptainStates::SafetyKeepPosition;
  updateNoAltitudeGoesUp(false);
  mainIteration();
  return true;
}

bool Captain::disableSafetyKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ != CaptainStates::SafetyKeepPosition)
  {
    res->message = "Impossible to disable safety keep position. Captain not in safety keep position state";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
    return true;
  }

  // Reset flags
  resetManeuverFlags();

  // Cancel actionlib if necessary
  cancelPilotActionlib();

  // Set captain state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  // Feedback
  safety_keep_position_feedback_.state = cola2_msgs::msg::CaptainStateFeedback::STOPPED;
  safety_keep_position_feedback_.header.stamp = this->get_clock()->now();
  pub_captain_state_feedback_->publish(safety_keep_position_feedback_);
  ++safety_keep_position_feedback_.id;

  res->message = "Safety keep position disabled";
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  mainIteration();
  return true;
}

bool Captain::disableAllKeepPositionsSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  if (state_ == CaptainStates::KeepPosition)
  {
    auto future = disable_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
  }
  else if (state_ == CaptainStates::SafetyKeepPosition)
  {
    auto future = disable_safety_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
  }
  else if (state_ == CaptainStates::Idle)
  {
    res->message = "Already in Idle state";
    res->success = true;
    RCLCPP_INFO(this->get_logger(), res->message.c_str());
  }
  else
  {
    res->message = "Impossible to disable keep positions. Captain is not Idle nor keeping position";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
  }
  return true;
}

bool Captain::resetKeepPositionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  const double last_keep_position_time = last_keep_position_time_;
  if (state_ == CaptainStates::KeepPosition)
  {
    RCLCPP_INFO(this->get_logger(), "Resetting keep position");
    auto future = disable_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    if (last_keep_position_holonomic_)
    {
      auto future = enable_keep_position_holonomic_client_->async_send_request(req);
      // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    }
    else
    {
      auto future = enable_keep_position_non_holonomic_client_->async_send_request(req);
      // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    }
  }
  else if (state_ == CaptainStates::SafetyKeepPosition)
  {
    RCLCPP_INFO(this->get_logger(), "Resetting safety keep position");
    auto future = disable_safety_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    // enableSafetyKeepPositionSrv(event);
    auto future_enable = enable_safety_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_enable);
  }
  else
  {
    res->success = true;
    res->message = "Captain not in any keep position state. Reset does nothing";
  }

  last_keep_position_time_ = last_keep_position_time;
  return true;
}

bool Captain::enableExternalMissionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  // Check current state
  if (state_ != CaptainStates::Idle)
  {
    res->message = "Impossible to enable external mission. Something is already running";
    res->success = false;
    RCLCPP_ERROR(this->get_logger(), res->message.c_str());
    return true;
  }

  // Store caller name
  // external_mission_caller_name_ = event.getCallerName();

  // Set captain state
  state_ = CaptainStates::ExternalMission;

  // Disable teleoperation pose controllers
  disableTeleoperationPoseControllers();

  res->message = std::to_string(external_mission_feedback_id_); // The message is used to pass the id
  res->success = true;
  RCLCPP_INFO(this->get_logger(), "External mission enabled. Feedback id: %s", res->message.c_str());
  mainIteration();
  return true;
}

bool Captain::disableExternalMissionSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request>, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;

  // Check current state
  if (state_ != CaptainStates::ExternalMission)
  {
    res->message = "Impossible to disable external mission. Captain not in external mission state";
    res->success = false;
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
    return true;
  }

  // Disable external mission if stopped from somewhere else
  // if (external_mission_caller_name_ != event.getCallerName())
  //  callTriggerService(external_mission_caller_name_ + "/disable", 5.0, 1.0);

  // Set captain state
  state_ = CaptainStates::Idle;
  updateNoAltitudeGoesUpIdle();

  // Increment id
  ++external_mission_feedback_id_;

  res->message = "External mission disabled: " + external_mission_caller_name_;
  res->success = true;
  RCLCPP_INFO(this->get_logger(), res->message.c_str());
  mainIteration();
  return true;
}

bool Captain::disableAllAndSetIdleSrv(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;

  if (state_ == CaptainStates::Goto)
  {
    // disableGotoSrv(req, res);
    auto future = disable_goto_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    // if (future.valid())
    // {
    //   res = future.get();
    // }
  }
  else if (state_ == CaptainStates::Section)
  {
    // disableSectionSrv(req, res);
    auto future = disable_section_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    // if (future.valid())
    // {
    //   res = future.get();
    // }
  }
  else if (state_ == CaptainStates::Mission)
  {
    // Reuse disable mission, but adapt request and response

    auto mission_req = std::make_shared<cola2_msgs::srv::Mission::Request>();
    auto mission_res = std::make_shared<cola2_msgs::srv::Mission::Response>();
    disableMissionSrv(mission_req, mission_res);
    res->message = mission_res->message;
    res->success = mission_res->success;
  }
  else if (state_ == CaptainStates::KeepPosition)
  {
    // disableKeepPositionSrv(req, res);
    auto future = disable_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    // if (future.valid())
    // {
    //   res = future.get();
    // }
  }
  else if (state_ == CaptainStates::SafetyKeepPosition)
  {
    // disableSafetyKeepPositionSrv(req, res);
    auto future = disable_safety_keep_position_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    // if (future.valid())
    // {
    //   res = future.get();
    // }
  }
  else if (state_ == CaptainStates::ExternalMission)
  {
    // disableExternalMissionSrv(event);
    auto future = disable_external_mission_client_->async_send_request(req);
    // rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);
    // if (future.valid())
    // {
    //   res = future.get();
    // }
  }
  else
  {
    res->message = "Already in Idle state";
    res->success = true;
    RCLCPP_INFO(this->get_logger(), res->message.c_str());
  }

  // Disable all paused missions too
  while (!loaded_missions_.empty())
  {
    const std::string mission_name = loaded_missions_.begin()->first;
    executePendingActions(mission_name);
    deleteLoadedMission(mission_name);
  }

  return true;
}

bool Captain::reloadParamsCallback(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<std_srvs::srv::Trigger::Request> req, std::shared_ptr<std_srvs::srv::Trigger::Response> res)
{
  (void)request_header;
  (void)req;
  res->success = getConfig();
  if (res->success)
  {
    // Update no altitude goes up behavior if in idle
    if (state_ == CaptainStates::Idle)
    {
      updateNoAltitudeGoesUpIdle();
    }

    // Call publish params service
    // auto future = srv_publish_params_->async_send_request(req);
  }
  else
  {
    res->message = "Unable to successfully reload all params";
    RCLCPP_WARN(this->get_logger(), res->message.c_str());
  }
  return true;
}

bool Captain::getConfig()
{
  bool ok = true;
  // Load config from param server
  while (!controller_params_client_->wait_for_service(std::chrono::seconds(1)))
  {
    RCLCPP_INFO(this->get_logger(), "Waiting for controller get_parameters service to be available");
  }

  rcl_interfaces::srv::GetParameters::Request::SharedPtr request = std::make_shared<rcl_interfaces::srv::GetParameters::Request>();
  request->names.push_back("max_velocity_z");

  auto future = controller_params_client_->async_send_request(request);
  rclcpp::spin_until_future_complete(this->get_node_base_interface(), future);

  if (future.valid())
  {
    auto response = future.get();
    config_.controller_max_velocity_z = response->values[0].double_value;
  }
  else
  {
    ok = false;
    RCLCPP_ERROR(this->get_logger(), "Failed to get parameters from controller get_parameters");
  }

  while (!pilot_params_client_->wait_for_service(std::chrono::seconds(1)))
  {
    RCLCPP_INFO(this->get_logger(), "Waiting for pilot get_parameters service to be available");
  }

  rcl_interfaces::srv::GetParameters::Request::SharedPtr request_pilot = std::make_shared<rcl_interfaces::srv::GetParameters::Request>();
  request_pilot->names.push_back("section/max_surge_velocity");

  auto future_pilot = pilot_params_client_->async_send_request(request_pilot);
  rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_pilot);

  if (future_pilot.valid())
  {
    auto response = future_pilot.get();
    config_.pilot_section_max_surge_velocity = response->values[0].double_value;
  }
  else
  {
    ok = false;
    RCLCPP_ERROR(this->get_logger(), "Failed to get parameters from controller get_parameters");
  }

  this->declare_parameter<double>("max_distance_to_waypoint", 1.0);
  this->declare_parameter<double>("safety_keep_position_depth", 1.0);
  this->declare_parameter<bool>("safety_keep_position_goes_to_ned_origin", false);
  this->declare_parameter<bool>("reset_keep_position_on_navigation_jump", false);
  this->declare_parameter<std::string>("vehicle_config_launch_mission_package", "default_package");
  this->declare_parameter<bool>("idle_no_altitude_goes_up", false);
  this->declare_parameter<std::string>("enable_no_altitude_goes_up_service", "default_service");
  this->declare_parameter<std::string>("disable_no_altitude_goes_up_service", "default_service");

  ok &= this->get_parameter("max_distance_to_waypoint", config_.max_distance_to_waypoint);
  ok &= this->get_parameter("safety_keep_position_depth", config_.safety_keep_position_depth);
  ok &= this->get_parameter("safety_keep_position_goes_to_ned_origin", config_.safety_keep_position_goes_to_ned_origin);
  ok &= this->get_parameter("reset_keep_position_on_navigation_jump", config_.reset_keep_position_on_navigation_jump);
  ok &= this->get_parameter("vehicle_config_launch_mission_package", config_.vehicle_config_launch_mission_package);
  ok &= this->get_parameter("idle_no_altitude_goes_up", config_.idle_no_altitude_goes_up);
  ok &= this->get_parameter("enable_no_altitude_goes_up_service", config_.enable_no_altitude_goes_up_service);
  ok &= this->get_parameter("disable_no_altitude_goes_up_service", config_.disable_no_altitude_goes_up_service);
  return ok;
}

int main(int argc, char **argv)
{

  rclcpp::init(argc, argv);
  auto captain = std::make_shared<Captain>();
  captain->init();
  rclcpp::spin(captain);
  rclcpp::shutdown();
  return 0;
}
