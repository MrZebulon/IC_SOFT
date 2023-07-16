//
// Created by Samuel on 16/06/2023.
//

#include <yaml-cpp/yaml.h>

#include "engine/SimulationEngine.hpp"

using namespace icarus;
using namespace icarus::simulator::engine;

template<typename DynamicsModel>
State SimulationEngine<DynamicsModel>::single_step(const State& state,
															  const Control& control,
															  const Environment& env,
															  double dt) {
	(void) state;
	(void) control;
	(void) env;
	(void) dt;

	return {};
}
