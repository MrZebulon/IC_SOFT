//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_SIMULATIONRATES_HPP
#define IC_SOFT_SIMULATIONRATES_HPP

#include <cmath>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;

namespace icarus::simulator {
	class SimulationRates {
	protected:
		long _ref_duration = 1e6/100;
		steady_clock::time_point _ref_time;

		void set_rate_us(long ref_duration) {
			if(ref_duration < 0) {
				std::cerr << "SimulationRates::set_rates_us : " << "duration must be positive !" << std::endl;
				return;
			}
			_ref_duration = ref_duration;
		}

	public:

		void set_rate(double rate_hz) {
			set_rate_us( static_cast<long>(1e6/rate_hz));
		}

		double get_rates_hz() const {
			return floor(1e-6/static_cast<double>(_ref_duration));
		}

		void set_now(){
			_ref_time = steady_clock::now();
		}

		void sleep(){
			/**
			 * Ensures the simulator doesn't drift ahead by sleeping just the right amount
			 * at the ned of each loop
			 */
			const long delta_t = duration_cast<microseconds>(steady_clock::now() - _ref_time).count();
			//Check if a full cycle has been completed
			if(_ref_duration > delta_t)
				return; //Sim is either on time or falling behind. No sleep required.

			//Sleep until nominal cycle is achieved.
			std::this_thread::sleep_for(microseconds(_ref_duration - delta_t));

			//Set new ref time
			set_now();
		}
	};
}

#endif //IC_SOFT_SIMULATIONRATES_HPP
