//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_ENGINEPLANT_HPP
#define IC_SOFT_ENGINEPLANT_HPP

namespace icarus::simulator::engine {
	/**
	 * The EnginePlant is an interface used to communicate between the Engine and the Model\n
	 * It's only purpose is to "abstract away" the maths (jacobian, x_dot...)
	 */
	template<typename DynamicsModel>
	class EnginePlant : public virtual DynamicsModel {

	public:
		SimulationOutput eval_dynamical_model_output(const State& state, const Control& control, const Environment& env) {
			return DynamicsModel::template compute_dynamics(state, control, env);
		}
	};
}

#endif //IC_SOFT_ENGINEPLANT_HPP
