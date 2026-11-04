#pragma once

#include "control/interfaces/base_controller.hpp"
#include "control/robots/husky/husky_parameters.hpp"

namespace control
{
namespace husky
{

class HuskyController : public BaseController
{
public:
  explicit HuskyController(const HuskyParameters & parameters = HuskyParameters{});

  void reset() override;
  void set_target(double target_x, double target_y) override;
  RobotState compute_command(const RobotState & state) override;

private:
  HuskyParameters parameters_{};
  double target_x_{0.0};
  double target_y_{0.0};
};

}  // namespace husky
}  // namespace control