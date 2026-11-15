#pragma once
#ifndef HUSKY_CONTROLLER
#define HUSKY_CONTROLLER

#include "control/interfaces/base_controller.hpp"

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
/**
 * @brief  Husky Communication interface
 *
 * */

//  CREATE SUB AND PUB

// USEFUL TOPICS:
// /a300_00000/cmd_vel   - publish vel commands - geometry_msg/TWIST_Stamped
// /a300_00000/platform/cmd_vel  - vel command - puiblished by system SUB to this for closed loop control
// /a300_00000/platform/emergency_stop - e-stop - imp  - BOOL -

// /a300_00000/platform/odom - odo subscribe - control node publishes
// /a300_00000/platform/odom/filtered - EKF filtered platform wheel odo plus IMU fused.
// /a300_00000/platform/safety_stop - another ESTOP ??

//   ROS 2 TOPIC LIST FOR HUSKY
// /a300_00000/controller_manager/activity
// /a300_00000/controller_manager/introspection_data/full
// /a300_00000/controller_manager/introspection_data/names
// /a300_00000/controller_manager/introspection_data/values
// /a300_00000/controller_manager/statistics/full
// /a300_00000/controller_manager/statistics/names
// /a300_00000/controller_manager/statistics/values
// /a300_00000/diagnostics
// /a300_00000/dynamic_joint_states
// /a300_00000/joint_state_broadcaster/transition_event
// /a300_00000/joy_teleop/bt_quality_stop
// /a300_00000/joy_teleop/cmd_vel
// /a300_00000/joy_teleop/joy
// /a300_00000/joy_teleop/joy/set_feedback
// /a300_00000/platform/joint_states
// /a300_00000/platform_velocity_controller/cmd_vel_out
// /a300_00000/platform_velocity_controller/transition_event
// /a300_00000/rc_teleop/cmd_vel
// /a300_00000/robot_description
// /a300_00000/sensors/camera_0/color/compressed
// /a300_00000/sensors/camera_0/color/compressedDepth
// /a300_00000/sensors/camera_0/color/image
// /a300_00000/sensors/camera_0/color/theora
// /a300_00000/sensors/camera_0/image/zstd
// /a300_00000/sensors/camera_1/color/compressed
// /a300_00000/sensors/camera_1/color/compressedDepth
// /a300_00000/sensors/camera_1/color/image
// /a300_00000/sensors/camera_1/color/theora
// /a300_00000/sensors/camera_1/image/zstd
// /a300_00000/sensors/imu_0/data
// /a300_00000/set_pose
// /a300_00000/tf
// /a300_00000/tf_static
// /a300_00000/twist_marker_server/cmd_vel  - what is this ? - marker sharing  ?
// /a300_00000/twist_marker_server/feedback
// /a300_00000/twist_marker_server/update
// /clock
// /parameter_events
// /rosout

namespace control::husky
{

  class HuskyController : public BaseController
  {
  public:
    /// @brief Constructor for the class
    HuskyController();

    /// @brief Destructor for the class
    ~HuskyController();

    void reset();
    void set_target(double target_x, double target_y);
    RobotState compute_command(const RobotState &state);
    void odomCallback(const nav_msgs::msg::Odometry &msg);
    void publishVelocity();
    //  subscriber callbacks:

  private:
    double target_x_{0.0};
    double target_y_{0.0};
    double vel_ = 0.0;
    double angular_vel_ = 0.0;
    nav_msgs::msg::Odometry odom_; //!< Used to store odom data
    std::mutex odoMtx_bar_;        //!< Mutex to protect the odometry data

    // PUBS
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr pubCmdVel_; ///< Publisher for velocity commands
                                                                        // rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr path_pub_;                     ///< Publisher for path poses
                                                                        // rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr markerArray_publisher_; ///< Publisher for visualization markers

    // SUBS
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odo_sub_; //!< Subscription to the odometry topic

    // Timer
    rclcpp::TimerBase::SharedPtr timer_;
  };

} 
#endif