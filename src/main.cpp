#include "control/robots/husky/husky_controller.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv); // Initialize ROS 2

  // create a node for the HuskyController
  auto controller = std::make_shared<control::husky::HuskyController>();
  rclcpp::spin(controller); // Spin the node to process callbacks
  rclcpp::shutdown();
  return 0;
}