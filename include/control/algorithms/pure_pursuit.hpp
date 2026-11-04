#pragma once

#include "control/interfaces/robot_state.hpp"

namespace control
{

class PurePursuit
{
public:
  explicit PurePursuit(double lookahead_distance = 1.0);

  void set_lookahead_distance(double lookahead_distance);
  double compute_steering(const RobotState & state, double target_x, double target_y) const;

private:
  double lookahead_distance_{1.0};
};

}  // namespace control