#include "control/utils/conversions.hpp"

namespace control
{
namespace conversions
{

double degrees_to_radians(double degrees)
{
  return degrees * 3.14159265358979323846 / 180.0;
}

double radians_to_degrees(double radians)
{
  return radians * 180.0 / 3.14159265358979323846;
}

RobotState zero_state()
{
  return RobotState{};
}

}  // namespace conversions
}  // namespace control
