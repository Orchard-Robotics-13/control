#include "control/robots/husky/husky_controller.hpp"

#include <algorithm>
#include <cmath>

namespace control
  {
    namespace husky
      {
        HuskyController::HuskyController()
        {
          pubCmdVel_ = this->create_publisher<geometry_msgs::msg::Twist>("/a300_00000/cmd_vel", 3);

          odo_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "a300_00000/platform/odom", 10, std::bind(&HuskyController::odomCallback, this, std::placeholders::_1));


        }

        HuskyController::~HuskyController()
        {
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

        RobotState HuskyController::compute_command(const RobotState & state)
        {
          RobotState command = state;
          const double dx = target_x_ - state.x;
          const double dy = target_y_ - state.y;
          return command;
        }

        void HuskyController::odomCallback(const nav_msgs::msg::Odometry &msg)
        {
            std::lock_guard<std::mutex> lock(odoMtx_bar_);
            odom_ = msg;
        }

      }  // namespace husky
  }  // namespace control