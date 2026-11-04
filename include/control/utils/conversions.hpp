#pragma once

#include "control/interfaces/robot_state.hpp"

namespace control
{
namespace conversions
{

double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);
RobotState zero_state();

}  // namespace conversions
}  // namespace control