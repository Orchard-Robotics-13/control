#pragma once

#include "control/interfaces/robot_state.hpp"

namespace control
{

class Stanley
{
public:
  explicit Stanley(double cross_track_gain = 1.0);

  void set_cross_track_gain(double cross_track_gain);
  double compute_steering(
    const RobotState & state, double target_x, double target_y, double target_heading) const;

private:
  double cross_track_gain_{1.0};
};

}  // namespace control