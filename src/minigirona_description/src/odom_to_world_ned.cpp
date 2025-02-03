#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

class OdomToTf : public rclcpp::Node
{
public:
    OdomToTf(): Node("odom_to_tf")
    {
        odom_subscription_ = this->create_subscription<nav_msgs::msg::Odometry>("girona500/dynamics/odometry",10,std::bind(&OdomToTf::odom_callback, this, std::placeholders::_1));
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
    }

private:
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        geometry_msgs::msg::TransformStamped transform;
        transform.header.stamp = this->now();
        transform.header.frame_id = "world_ned";  // Parent frame
        transform.child_frame_id = "girona500/base_link";  // Child frame

        // Translation from odometry
        transform.transform.translation.x = msg->pose.pose.position.x;
        transform.transform.translation.y = msg->pose.pose.position.y;
        transform.transform.translation.z = msg->pose.pose.position.z;

        // Orientation from odometry
        transform.transform.rotation = msg->pose.pose.orientation;

        tf_broadcaster_->sendTransform(transform);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscription_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdomToTf>());
    rclcpp::shutdown();
    return 0;
}
