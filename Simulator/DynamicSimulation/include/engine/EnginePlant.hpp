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
		SimulationOutput eval_dynamical_model_output(const State &state, const Control &control,
									const Environment &env) {
			return DynamicsModel::template compute_dynamics(state, control, env);
		}

		void load_model_params(std::string &params_path) {
			return DynamicsModel::template load_params_form_yml(params_path);

		}
	};
}

#endif //IC_SOFT_ENGINEPLANT_HPP
