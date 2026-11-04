#pragma once

namespace control
{
namespace husky
{

struct HuskyParameters
{
  double wheel_base{0.55};
  double maximum_linear_velocity{1.0};
  double maximum_angular_velocity{1.0};
};

}  // namespace husky
}  // namespace control