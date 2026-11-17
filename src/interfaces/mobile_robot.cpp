#include "control/interfaces/mobile_robot.hpp"

namespace control
{

  MobileRobot::MobileRobot(const RobotState &initial_state)
      : state_(initial_state)
  {
  }

  const RobotState &MobileRobot::state() const
  {
    return state_;
  }

  void MobileRobot::set_state(const RobotState &state)
  {
    state_ = state;
  }

  void MobileRobot::apply_command(double linear_velocity, double angular_velocity)
  {
    state_.linear_velocity = linear_velocity;
    state_.angular_velocity = angular_velocity;
  }

  void MobileRobot::stop()
  {
    apply_command(0.0, 0.0);
  }

} // namespace control