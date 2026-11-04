#include "control/algorithms/pid.hpp"

#include "control/utils/math.hpp"

namespace control
{

Pid::Pid(double proportional_gain, double integral_gain, double derivative_gain)
{
  set_gains(proportional_gain, integral_gain, derivative_gain);
}

void Pid::set_gains(double proportional_gain, double integral_gain, double derivative_gain)
{
  proportional_gain_ = proportional_gain;
  integral_gain_ = integral_gain;
  derivative_gain_ = derivative_gain;
}

void Pid::set_output_limits(double minimum_output, double maximum_output)
{
  minimum_output_ = minimum_output;
  maximum_output_ = maximum_output;
}

void Pid::reset()
{
  integral_error_ = 0.0;
  previous_error_ = 0.0;
  has_previous_error_ = false;
}

double Pid::update(double error, double delta_time)
{
  if (delta_time <= 0.0) {
    return proportional_gain_ * error;
  }

  integral_error_ += error * delta_time;
  const double derivative_error =
    has_previous_error_ ? (error - previous_error_) / delta_time : 0.0;
  previous_error_ = error;
  has_previous_error_ = true;

  const double output = proportional_gain_ * error +
    integral_gain_ * integral_error_ +
    derivative_gain_ * derivative_error;
  return math::clamp(output, minimum_output_, maximum_output_);
}

}  // namespace control