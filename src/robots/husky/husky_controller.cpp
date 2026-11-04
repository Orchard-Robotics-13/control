#include "control/robots/husky/husky_controller.hpp"

#include <algorithm>
#include <cmath>

namespace control
{
namespace husky
{

HuskyController::HuskyController(const HuskyParameters & parameters)
: parameters_(parameters)
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
  command.linear_velocity = std::min(
    parameters_.maximum_linear_velocity, std::hypot(dx, dy));
  command.angular_velocity = std::max(
    -parameters_.maximum_angular_velocity,
    std::min(parameters_.maximum_angular_velocity, std::atan2(dy, dx) - state.heading));
  return command;
}

}  // namespace husky
}  // namespace control