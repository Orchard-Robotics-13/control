#pragma once

namespace control
{
namespace math
{

double clamp(double value, double minimum, double maximum);
double normalize_angle(double angle);
double distance(double first_x, double first_y, double second_x, double second_y);

}  // namespace math
}  // namespace control