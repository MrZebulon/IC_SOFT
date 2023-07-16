//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_TCVDRONEDYNAMICMODEL_HPP
#define IC_SOFT_TCVDRONEDYNAMICMODEL_HPP

#include "DynamicModelBase.hpp"

namespace icarus::simulator::model::hopper {

	class TcvHopperParams : public virtual DynamicModelParamsBase{
		void load_params_form_yml(std::string& params_path) override {

		}
	};

	class TcvHopperDynamicModel : public virtual DynamicModelBase, public virtual TcvHopperParams {

	};
}
#endif //IC_SOFT_TCVDRONEDYNAMICMODEL_HPP
