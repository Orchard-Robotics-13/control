#pragma once

#include "control/interfaces/robot_state.hpp"

namespace control
{

class MobileRobot
{
public:
  MobileRobot() = default;
  explicit MobileRobot(const RobotState & initial_state);

  const RobotState & state() const;
  void set_state(const RobotState & state);
  void apply_command(double linear_velocity, double angular_velocity);
  void stop();

private:
  RobotState state_{};
};

}  // namespace control