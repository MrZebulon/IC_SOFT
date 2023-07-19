//
// Created by Samuel on 16/06/2023.
//

#include "FlightSimulatorBase.hpp"
using namespace icarus::simulator;

template<typename DynamicsModel>
void FlightSimulatorBase::init_simulator(std::string& params_path) {
	/**
	 * Called at the beginning of execution\n
	 * Sets up Simulation Engine, rates, default values (env, state, ...), ...
	 */
	// Creating engine
	const auto engine = std::make_unique<SimulationEngine<DynamicsModel>>();
	engine->plant->load_model_params(params_path);
	_engine = engine;

	// Setting up rates
	_rates.set_now();
}

void FlightSimulatorBase::run() {
	/**
	 * RUN ENDPOINT\n
	 * Checks if the simulator should run & call run_once if necessary\n
	 * (run_once handles timings)
	 *
	 */
}

void FlightSimulatorBase::simulate_env() {
	/**
	 * Computes environment settings in each simulation tick
	 */

	/* WIND */
	_env.wind_velocity_ned.setZero();
	_env.wind_velocity_ned += _horizontal_wind.get_wind_direction_NED();
	_env.wind_velocity_ned += _gust.get_wind_direction_NED();

	// Add other models contributions here
}

void FlightSimulatorBase::simulate_step() {
	/**
	 * Calls the engine to compute the new state
	 */
}
