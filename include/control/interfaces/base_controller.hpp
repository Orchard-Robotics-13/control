#pragma once

#include <memory>
#include <string>

#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"

#include "control/interfaces/robot_state.hpp"

namespace control
{

class BaseController : public rclcpp::Node
{
public:
  explicit BaseController(
    const std::string & node_name = "husky_controller",
    const std::string & odometry_topic = "/odometry/filtered",
    const std::string & velocity_topic = "/cmd_vel");

  ~BaseController() override = default;

  virtual void reset() = 0;
  virtual void set_target(double target_x, double target_y) = 0;
  virtual RobotState compute_command(const RobotState & state) = 0;

protected:
  void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr message);
  virtual void publish_velocity_command(const RobotState & command);

  RobotState robot_state_{};

private:
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_subscription_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
};

}  // namespace control
