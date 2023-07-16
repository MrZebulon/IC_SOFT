//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_FLIGHTSIMULATORBASE_HPP
#define IC_SOFT_FLIGHTSIMULATORBASE_HPP

#include <memory>

#include "SimulationRates.hpp"
#include "engine/SimulationEngine.hpp"
#include "environment/WindModels.hpp"

using namespace icarus::simulator::env;
using namespace icarus::simulator::engine;

namespace icarus::simulator {

	struct FlightSimulatorParameters {

		//TIME STEP
		double _dt = 0;

		//FUNDAMENTAL BLOCS
		State _state;
		Control _control;
		Target _target;
		Environment _env;
		SimulationOutput _output;

		//SENSORS
		Sensor<6, 2, 2> imu;
		Sensor<1, 1, 1> altimeter;
		Sensor<3, 1, 1> gps;
		Sensor<3, 1, 1> magnetometer;
	};

	class FlightSimulatorBase : public virtual FlightSimulatorParameters {
	public:
		template<typename DynamicsModel>
		void init_simulator(std::string& params_path);

		void run();
		virtual void run_once() {
			/**
			 * SINGLE CYCLE OF RUN (sublcass defined due to timings, ...) \n
			 * \ORDER
			 * > get_targets\n
			 * > simulate_env\n
			 * > get_state \n
			 * > get_control\n
			 * > simulate_step (compute next state)\n
			 * > output\n
			 *
			 * At the end of each loop, call SimulationRates::sleep (ensures the simulator doesn't drift ahead)
			 */
			std::cout << "FlightSimulatorBase::run_once" << " : " << "override me !" << std::endl;
		}

		virtual void get_targets() {
			/**
			 * Target ENDPOINT (subclass defined)
			 */
			std::cout << "FlightSimulatorBase::get_targets" << " : " << "override me !" << std::endl;
		}
		virtual void get_state() {
			/**
			 * State ENDPOINT (subclass defined)
			 */
			std::cout << "FlightSimulatorBase::get_state" << " : " << "override me !" << std::endl;
		}
		virtual void get_control() {
			/**
			 * Control ENDPOINT (subclass defined)
			 */
			std::cout << "FlightSimulatorBase::get_control" << " : " << "override me !" << std::endl;
		}
		virtual void output() {
			/**
			 * Output ENDPOINT (subclass defined)
			 */
			std::cout << "FlightSimulatorBase::output" << " : " << "override me !" << std::endl;
		}

		void simulate_env();
		void simulate_step();

		virtual bool ok() {
			/**
			 * Whether the simulator should run (subclass defined)
			 */
			std::cout << "FlightSimulatorBase::ok" << " : " << "override me !" << std::endl;
			return true;
		}
		void sleep() { _rates.sleep(); }

		void set_time_step(double dt) { _dt = dt; }
		double get_time_step() const { return _dt; }

		void set_sim_speed(double rates_hz){ _rates.set_rate(rates_hz); }
		double get_sim_speed() const {return _rates.get_rates_hz(); }

	protected:
		// Engine & clockwork
		std::unique_ptr<SimulationEngineInterface> _engine;
		SimulationRates _rates;

		// Environment simulation
		HorizontalWindModel _horizontal_wind;
		GustModel _gust;

	};
}


#endif //IC_SOFT_FLIGHTSIMULATORBASE_HPP
