#pragma once
#ifndef HUSKY_CONTROLLER
#define HUSKY_CONTROLLER

#include "control/interfaces/base_controller.hpp"
/** 
 * @brief  Husky Communication interface 
 * 
 * */

//   ROS 2 TOPIC LIST FOR HUSKY
// /a300_00000/cmd_vel   - publish vel commands
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
// /a300_00000/platform/cmd_vel  - vel command
// /a300_00000/platform/emergency_stop - e-stop - imp 
// /a300_00000/platform/joint_states
// /a300_00000/platform/odom - odo subscribe 
// /a300_00000/platform/odom/filtered - whats the difference - subscribe to this what is being filtered 
// /a300_00000/platform/safety_stop - another ESTOP ??
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


namespace control
  {
    namespace husky
      {

        class HuskyController : public BaseController
        {
        public:

        /// @brief Constructor for the class 
        HuskyController(); 

        /// @brief Destructor for the class
        ~HuskyController();

          void reset() ;
          void set_target(double target_x, double target_y) ;
          RobotState compute_command(const RobotState & state) ;
          

          //  subscriber callbacks:

        private:
          double target_x_{0.0};
          double target_y_{0.0};
        };

      }  // namespace husky
  }  // namespace control
#endif