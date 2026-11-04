#pragma once

#include "control/interfaces/robot_state.hpp"

namespace control
{

class Mpc
{
public:
  Mpc() = default;

  void set_horizon(int horizon);
  void set_time_step(double time_step);
  RobotState compute_command(
    const RobotState & state, double target_x, double target_y) const;

private:
  int horizon_{10};
  double time_step_{0.1};
};

}  // namespace control