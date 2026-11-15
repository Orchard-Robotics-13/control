#ifndef BASE_CONTROLLER
#define BASE_CONTROLLER

// types
#include <memory>
#include <string>

// ros includes
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"

// file includes
#include "control/interfaces/robot_state.hpp"

/*!
 * \brief Base controller interface
 *  \details
 *  This interface class is used to set all the methods that need to be embodies
 *  within any subsequent derived autonomous vehicle controller classes.
 *  The methods noted in interface class are the only methods that will be visible.
 *
 *  \author    Adesh Grewal
 *  \version   1.01
 *  \date      16-11-2026
 *  \bug       none reported as of 16-11-2026
 */

namespace control
{

  class BaseController : public rclcpp::Node
  {
  public:

    BaseController();
    ~BaseController() override = default;

    virtual void reset() = 0;
    virtual void set_target(double target_x, double target_y) = 0;
    virtual RobotState compute_command(const RobotState &state) = 0;

  protected:
    void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr message);
    virtual void publish_velocity_command(const RobotState &command);

    RobotState robot_state_{};

  private:
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odometry_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
  };

} // namespace control
#endif // BASE_CONTROLLER
