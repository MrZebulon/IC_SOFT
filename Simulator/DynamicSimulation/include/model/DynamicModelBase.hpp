//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_DYNAMICMODELBASE_HPP
#define IC_SOFT_DYNAMICMODELBASE_HPP

#include <iostream>
#include "Structures.hpp"

namespace icarus::simulator::model {

	class DynamicModelBase {
		virtual SimulationOutput compute_dynamics(const State& state, const Control& control, const Environment& env) {
			/**
			 * (subclass defined)\n
			 * Where all the math heavy-lifting is performed
			 */
			(void) state;
			(void) control;
			(void) env;
			std::cout << "DynamicModelBase::compute_dynamics" << " : "
					  << "override me!" << std::endl;

			return {};
		}

		virtual Eigen::VectorXd get_model_params() {
			/**
			 * (subclass defined)\n
			 * Every model inherits a subclass of DynamicModelParamsBase, this method must be overridden
			 * by the model and will be used to get relevant params
			 */
			std::cout << "DynamicModelBase::get_model_params" << " : "
					  << "override me!" << std::endl;

			return {};
		}

		virtual void set_model_params(const Eigen::VectorXd& params) {
			/**
			 * (subclass defined)\n
			 * Every model inherits a subclass of DynamicModelParamsBase, this method must be overridden
			 * by the model and will be used to set relevant params
			 */
			std::cout << "DynamicModelBase::set_model_params" << " : "
					  << "override me!" << std::endl;

		}
	};

	class DynamicModelParamsBase{
		virtual void load_params_form_yml(std::string& params_path) {
			(void) params_path;
			std::cout << "DynamicModelParamsBase::load_params_form_yml" << " : "
					  << "override me!" << std::endl;
		}
	};
}

#endif //IC_SOFT_DYNAMICMODELBASE_HPP
