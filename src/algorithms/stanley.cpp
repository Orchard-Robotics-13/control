#include "control/algorithms/stanley.hpp"

#include <algorithm>
#include <cmath>

#include "control/utils/math.hpp"

namespace control
{

Stanley::Stanley(double cross_track_gain)
: cross_track_gain_(cross_track_gain)
{
}

void Stanley::set_cross_track_gain(double cross_track_gain)
{
  cross_track_gain_ = cross_track_gain;
}

double Stanley::compute_steering(
  const RobotState & state, double target_x, double target_y, double target_heading) const
{
  const double heading_error = math::normalize_angle(target_heading - state.heading);
  const double cross_track_error =
    std::sin(state.heading) * (target_x - state.x) -
    std::cos(state.heading) * (target_y - state.y);
  const double speed = std::max(std::abs(state.linear_velocity), 0.01);
  return heading_error + std::atan2(cross_track_gain_ * cross_track_error, speed);
}

}  // namespace control