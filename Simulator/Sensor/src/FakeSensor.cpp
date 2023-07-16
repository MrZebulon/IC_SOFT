//
// Created by Samuel on 21/06/2023.
//

#include "FakeSensor.hpp"

using namespace icarus::sensor;

template<size_t n_bias, size_t n_noise, size_t n_drift>
void FakeSensor<n_bias, n_noise, n_drift>::generate_sensor_data(const double real_values[n_bias]) {
	this->data << real_values + this->noise * white_noise.get_value() + this->bias;
}