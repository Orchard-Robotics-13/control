#include "control/algorithms/pure_pursuit.hpp"

#include <cmath>

namespace control
{

PurePursuit::PurePursuit(double lookahead_distance)
: lookahead_distance_(lookahead_distance)
{
}

void PurePursuit::set_lookahead_distance(double lookahead_distance)
{
  lookahead_distance_ = lookahead_distance;
}

double PurePursuit::compute_steering(
  const RobotState & state, double target_x, double target_y) const
{
  const double target_angle = std::atan2(target_y - state.y, target_x - state.x);
  return target_angle - state.heading;
}

}  // namespace control