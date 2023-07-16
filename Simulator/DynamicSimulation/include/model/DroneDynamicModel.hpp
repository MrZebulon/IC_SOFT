//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_DRONEDYNAMICMODEL_HPP
#define IC_SOFT_DRONEDYNAMICMODEL_HPP

#include "DynamicModelBase.hpp"

namespace icarus::simulator::model::drone {

	class TcvDroneParams : public virtual DynamicModelParamsBase{
		void load_params_form_yml(std::string& params_path) override {

		}
	};

	class DroneDynamicModel : public virtual DynamicModelBase, public virtual TcvDroneParams {

	};
}
#endif //IC_SOFT_DRONEDYNAMICMODEL_HPP
