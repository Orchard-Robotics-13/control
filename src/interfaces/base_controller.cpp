#include "control/interfaces/base_controller.hpp"

#include <cmath>
#include <functional>

namespace control
{

BaseController::BaseController()
: rclcpp::Node("Base_contrller")
{
}

void BaseController::odometry_callback(const nav_msgs::msg::Odometry::SharedPtr message)
{
  // const auto & pose = message->pose.pose;
  // const auto & twist = message->twist.twist;

  // robot_state_.x = pose.position.x;
  // robot_state_.y = pose.position.y;
  // robot_state_.heading = std::atan2(
  //   2.0 * (pose.orientation.w * pose.orientation.z +
  //   pose.orientation.x * pose.orientation.y),
  //   1.0 - 2.0 * (pose.orientation.y * pose.orientation.y +
  //   pose.orientation.z * pose.orientation.z));
  // robot_state_.linear_velocity = twist.linear.x;
  // robot_state_.angular_velocity = twist.angular.z;

  // publish_velocity_command(compute_command(robot_state_));
}

void BaseController::publish_velocity_command(const RobotState & command)
{
  // geometry_msgs::msg::Twist velocity_message;
  // velocity_message.linear.x = command.linear_velocity;
  // velocity_message.angular.z = command.angular_velocity;
  // velocity_publisher_->publish(velocity_message);
}

}  // namespace control
