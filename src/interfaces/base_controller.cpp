#include "control/interfaces/base_controller.hpp"

#include <cmath>
#include <functional>

namespace control
{

BaseController::BaseController(
  const std::string & node_name,
  const std::string & odometry_topic,
  const std::string & velocity_topic)
: Node(node_name)
{
  odometry_subscription_ = create_subscription<nav_msgs::msg::Odometry>(
    odometry_topic,
    rclcpp::SensorDataQoS(),
    std::bind(&BaseController::odometry_callback, this, std::placeholders::_1));

  velocity_publisher_ = create_publisher<geometry_msgs::msg::Twist>(
    velocity_topic,
    rclcpp::QoS(rclcpp::KeepLast(10)));

  RCLCPP_INFO(
    get_logger(),
    "Husky controller listening on '%s' and publishing on '%s'",
    odometry_topic.c_str(),
    velocity_topic.c_str());
}

void BaseController::odometry_callback(const nav_msgs::msg::Odometry::SharedPtr message)
{
  const auto & pose = message->pose.pose;
  const auto & twist = message->twist.twist;

  robot_state_.x = pose.position.x;
  robot_state_.y = pose.position.y;
  robot_state_.heading = std::atan2(
    2.0 * (pose.orientation.w * pose.orientation.z +
    pose.orientation.x * pose.orientation.y),
    1.0 - 2.0 * (pose.orientation.y * pose.orientation.y +
    pose.orientation.z * pose.orientation.z));
  robot_state_.linear_velocity = twist.linear.x;
  robot_state_.angular_velocity = twist.angular.z;

  publish_velocity_command(compute_command(robot_state_));
}

void BaseController::publish_velocity_command(const RobotState & command)
{
  geometry_msgs::msg::Twist velocity_message;
  velocity_message.linear.x = command.linear_velocity;
  velocity_message.angular.z = command.angular_velocity;
  velocity_publisher_->publish(velocity_message);
}

}  // namespace control
