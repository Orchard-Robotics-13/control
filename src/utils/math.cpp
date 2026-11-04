#include "control/utils/math.hpp"

#include <algorithm>
#include <cmath>

namespace control
{
namespace math
{

double clamp(double value, double minimum, double maximum)
{
  return std::max(minimum, std::min(value, maximum));
}

double normalize_angle(double angle)
{
  constexpr double pi = 3.14159265358979323846;
  constexpr double two_pi = 2.0 * pi;
  while (angle > pi) {
    angle -= two_pi;
  }
  while (angle < -pi) {
    angle += two_pi;
  }
  return angle;
}

double distance(double first_x, double first_y, double second_x, double second_y)
{
  return std::hypot(second_x - first_x, second_y - first_y);
}

}  // namespace math
}  // namespace control
