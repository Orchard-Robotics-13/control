#ifndef MOBILE_ROBOT_H
#define MOBILE_ROBOT_H


#include "control/interfaces/robot_state.hpp"

/**
 * @file mobile_robot.hpp
 * @brief Defines the data model for one mobile robot.
 *
 * @details MobileRobot owns an independent RobotState and provides methods for
 * reading and updating it. It does not communicate with ROS or implement a
 * control algorithm.
 *
 * Integrate one MobileRobot instance into a controller or maintain a collection
 * of instances, one per physical robot:
 *
 * @code
 * control::MobileRobot robot;
 * robot.set_state(current_odometry_state);
 *
 * control::RobotState command =
 *   controller.compute_command(robot.state());
 *
 * robot.apply_command(
 *   command.linear_velocity,
 *   command.angular_velocity);
 * @endcode
 *
 * The ROS controller should convert odometry into a RobotState and call
 * set_state(). It should pass robot.state() to a control algorithm, apply the
 * returned velocities with apply_command(), and publish those values through
 * the controller's ROS publisher.
 *
 *  \author    Adesh Grewal
 *  \version   1.01
 *  \date      16-11-2026
 *  \bug       none reported as of 16-11-2026
 */

namespace control
{

  /**
   * @brief Stores and updates the state of one mobile robot.
   *
   * @details This class is a lightweight wrapper around RobotState. Position,
   * heading, and velocity data are stored in the private state_ member.
   * ROS-specific types and communication should remain in the controller or
   * its ROS callbacks, while control algorithms should use the returned
   * RobotState.
   */
  class MobileRobot
  {
  public:
    /**
     * @brief Constructs a robot using the default RobotState values.
     */
    MobileRobot() = default;

    /**
     * @brief Constructs a robot with an initial state.
     *
     * @param initial_state Initial position, heading, and velocity values.
     *
     * @details The supplied state is copied into the robot's independent
     * private state_ member.
     */
    MobileRobot(const RobotState &initial_state);

    /**
     * @brief Gets the robot's current state.
     *
     * @return A const reference to the privately stored RobotState.
     *
     * @details The reference prevents callers from modifying the state directly.
     * Call set_state() to replace the complete state.
     */
    const RobotState &state() const;

    /**
     * @brief Replaces the robot's current state.
     *
     * @param state New position, heading, and velocity values.
     *
     * @details This should normally be called after converting ROS odometry or
     * another sensor measurement into a RobotState.
     */
    void set_state(const RobotState &state);

    /**
     * @brief Applies linear and angular velocity values to this robot.
     *
     * @param linear_velocity Desired forward velocity.
     * @param angular_velocity Desired rotational velocity.
     *
     * @details This updates only the velocity fields in state_. It does not
     * directly publish values through ROS.
     */
    void apply_command(double linear_velocity, double angular_velocity);

    /**
     * @brief Stops this robot.
     *
     * @details Sets both linear_velocity and angular_velocity in state_ to zero.
     * It does not directly publish a stop command.
     */
    void stop();

  private:
    RobotState state_{};
  };

} // namespace control
#endif //MOBILE_ROBOT_H
