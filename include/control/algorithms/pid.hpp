#pragma once

namespace control
{

class Pid
{
public:
  Pid() = default;
  Pid(double proportional_gain, double integral_gain, double derivative_gain);

  void set_gains(double proportional_gain, double integral_gain, double derivative_gain);
  void set_output_limits(double minimum_output, double maximum_output);
  void reset();
  double update(double error, double delta_time);

private:
  double proportional_gain_{0.0};
  double integral_gain_{0.0};
  double derivative_gain_{0.0};
  double integral_error_{0.0};
  double previous_error_{0.0};
  double minimum_output_{-1.0};
  double maximum_output_{1.0};
  bool has_previous_error_{false};
};

}  // namespace control