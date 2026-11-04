#pragma once

namespace control
{

struct RobotState
{
  double x{0.0};
  double y{0.0};
  double heading{0.0};
  double linear_velocity{0.0};
  double angular_velocity{0.0};
};

}  // namespace control