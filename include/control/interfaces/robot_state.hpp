#ifndef ROBOT_STATE_H
#define ROBOT_STATE_H

/**
 * @brief Stores the current position, orientation, and velocity of a robot.
 *
 * @details This state can represent measured odometry or a computed control
 * command, depending on the method that uses it.
 *
 * RobotState is an independent struct value.
 * copies need to be created to be used correctly.
 *
 *  \author    Adesh Grewal
 *  \version   1.01
 *  \date      16-11-2026
 *  \bug       none reported as of 16-11-2026
 */

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

} // namespace control
#endif // ROBOT_STATE_H