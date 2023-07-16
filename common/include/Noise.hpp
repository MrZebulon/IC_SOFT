//
// Created by Samuel on 21/06/2023.
//

#ifndef IC_SOFT_NOISE_HPP
#define IC_SOFT_NOISE_HPP

#include <random>

namespace icarus {
	class WhiteNoise {
	public:
		explicit WhiteNoise() {
			distribution = std::normal_distribution<double>(0, 1);
		}

		double get_value() {
			/**
			 * Returns single RVS from normal distribution
			 */
			return distribution(generator);
		}
		double get_value_in_range(double lower, double upper) {
			/**
			 * Returns samples from the normal distribution,
			 * s.t. lower/higher match with -/+ 2 * standard error
			 */
			const double mean = 0.5 * (lower + upper);
			return mean + distribution(generator) * (upper - mean) / 2.0;
		}
	private:
		std::default_random_engine generator;
		std::normal_distribution<double> distribution;
	};

	class UniformNoise {
	public:
		explicit UniformNoise() {
			distribution = std::uniform_real_distribution<double>(0, 1);
		}

		double get_value() {
			/**
			 * Returns single RVS from normal distribution
			 */
			return distribution(generator);
		}

		double get_value_in_range(double lower, double upper) {
			/**
			 * Returns samples from the uniform distribution with lower/upper bounds
			 * given as parameters
			 */
			return lower + distribution(generator) * (upper - lower);
		}
	private:
		std::default_random_engine generator;
		std::uniform_real_distribution<double> distribution;
	};
}

#endif //IC_SOFT_NOISE_HPP
