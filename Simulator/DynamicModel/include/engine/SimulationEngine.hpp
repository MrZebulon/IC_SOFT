//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_SIMULATIONENGINE_HPP
#define IC_SOFT_SIMULATIONENGINE_HPP

#include <Eigen/Dense>

#include "SimulationEngineInterface.hpp"
#include "EnginePlant.hpp"

namespace icarus::simulator::engine {
	template<typename DynamicsModel>
	class SimulationEngine : public virtual SimulationEngineInterface, public virtual SimulationEngineParameters {
	public:
		State single_step(const State& state, const Control& control, const Environment& env, double dt) override;

	public:
		EnginePlant<DynamicsModel> plant;

	};
}
#endif //IC_SOFT_SIMULATIONENGINE_HPP
