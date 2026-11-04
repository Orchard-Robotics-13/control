#include "control/robots/husky/husky_controller.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto controller = std::make_shared<control::husky::HuskyController>();
  rclcpp::spin(controller);
  rclcpp::shutdown();
  return 0;
}