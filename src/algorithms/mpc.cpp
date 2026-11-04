#include "control/algorithms/mpc.hpp"

#include <cmath>

namespace control
{

void Mpc::set_horizon(int horizon)
{
  horizon_ = horizon > 0 ? horizon : 1;
}

void Mpc::set_time_step(double time_step)
{
  time_step_ = time_step > 0.0 ? time_step : 0.1;
}

RobotState Mpc::compute_command(
  const RobotState & state, double target_x, double target_y) const
{
  RobotState command = state;
  command.linear_velocity = std::hypot(target_x - state.x, target_y - state.y);
  command.angular_velocity = std::atan2(target_y - state.y, target_x - state.x) - state.heading;
  return command;
}

}  // namespace control