#include "control/robots/husky/husky_controller.hpp"

#include <algorithm>
#include <cmath>

namespace control
  {
    namespace husky
      {
        HuskyController::HuskyController()
        {
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

      }  // namespace husky
  }  // namespace control