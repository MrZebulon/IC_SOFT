//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_SIMULATIONENGINEINTERFACE_HPP
#define IC_SOFT_SIMULATIONENGINEINTERFACE_HPP

#include <Eigen/Dense>
#include <iostream>

#include "Structures.hpp"

#include "EnginePlant.hpp"

namespace icarus::simulator::engine {
	struct SimulationEngineParameters {

	};

	class SimulationEngineInterface {

	public:
		virtual State single_step(const State& state, const Control& control, const Environment& env, double dt) {
			/**
			 * Computes the next state from current state, control & env\n
			 * Integration is preformed here\n
			 * Computing state changes ("x dot") is done by the plant\n
			 */
			(void) state;
			(void) control;
			(void) env;
			(void) dt;
			std::cout << "SimulationEngineInterface::single_step" << " : " << "override me!" << std::endl;
			return {};
		}
	};
}
#endif //IC_SOFT_SIMULATIONENGINEINTERFACE_HPP
