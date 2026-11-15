#include "control/robots/husky/husky_controller.hpp"

#include <algorithm>
#include <cmath>

namespace control::husky
{
  HuskyController::HuskyController()
  {
    // velocity pub
    pubCmdVel_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("/a300_00000/cmd_vel", 3);

    // odo sub
    odo_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "a300_00000/platform/odom", 10, std::bind(&HuskyController::odomCallback, this, std::placeholders::_1));

    // timer
    timer_ = this->create_wall_timer(std::chrono::milliseconds(100),
                                     std::bind(&HuskyController::publishVelocity, this));
  }

  HuskyController::~HuskyController()
  {
  }

  // Callbacks
  void HuskyController::odomCallback(const nav_msgs::msg::Odometry &msg)
  {
    std::lock_guard<std::mutex> lock(odoMtx_bar_);
    odom_ = msg;
  }

  void HuskyController::reset()
  {
    target_x_ = 0.0;
    target_y_ = 0.0;
  }

  void HuskyController::set_target(double target_x, double target_y)
  {
    target_x_ = target_x;
    target_y_ = target_y;
  }

  RobotState HuskyController::compute_command(const RobotState &state)
  {
    RobotState command = state;
    const double dx = target_x_ - state.x;
    const double dy = target_y_ - state.y;
    return command;
  }

  // Publish desired velocity
void HuskyController::publishVelocity()
{
    geometry_msgs::msg::TwistStamped cmd;

    cmd.header.stamp = this->now();
    cmd.header.frame_id = "base_link";

    cmd.twist.linear.x = vel_;
    cmd.twist.linear.y = 0.0 ;
    cmd.twist.angular.z = angular_vel_;

    pubCmdVel_->publish(cmd);
}

}