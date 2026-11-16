#include "control/robots/husky/husky_controller.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv); // Initialize ROS 2

  // create a node for the HuskyController
  auto controller = std::make_shared<control::husky::HuskyController>();

  // create planner node 
  // auto planner = std::make_shared<control::planner>(); -- to be intiated once planner is ready - node 
  // rclcpp::spin(planner); 

  // when running 2 nodes
  //   // Create an executor
  // rclcpp::executors::MultiThreadedExecutor executor;

  // // Add nodes to the executor
  // executor.add_node(node1);
  // executor.add_node(node2);

  // // Spin the executor
  // executor.spin();

  // // Shutdown ROS 2
  // rclcpp::shutdown();

  // return 0;


  // currently on 1 node 

  rclcpp::spin(controller); // Spin the node to process callbacks
  rclcpp::shutdown();
  return 0;
}