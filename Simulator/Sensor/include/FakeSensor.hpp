//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_FAKESENSOR_HPP
#define IC_SOFT_FAKESENSOR_HPP

#include <Eigen/Core>
#include <iostream>
#include "Structures.hpp"
#include "Noise.hpp"

using namespace icarus;

namespace icarus::sensor {

	template<size_t n_bias, size_t n_noise, size_t n_drift>
	class FakeSensor : public virtual Sensor<n_bias, n_noise, n_drift> {
	public:
		typedef Sensor<n_bias, n_noise, n_drift> SensorType;

		explicit FakeSensor(const double bias[n_bias], const double noise[n_noise], const double drift[n_drift])
			: SensorType({.bias = bias, .noise = noise, .drift = drift}){}

		void generate_sensor_data(const double real_values[n_bias]);

	private:
		WhiteNoise white_noise;
	};

} // icarus::sensor

#endif //IC_SOFT_FAKESENSOR_HPP
