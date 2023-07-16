//
// Created by Samuel on 16/06/2023.
//

#include <iostream>
#include "Structures.hpp"

using namespace icarus;

State State::eigen_to_state(const Eigen::VectorXd &vect) {
	State state{};

	if(vect.size() != State::STATE_LENGTH){
		std::cout << "[WARNING] " << "IC_COMMONS::eigen_to_state input is not the right length !" << std::endl;
		return state;
	}

	state.pos_ned << vect.segment<3>(0);
	state.vel_ned << vect.segment<3>(3);
	state.q_nb.coeffs() << vect.segment<3>(7), vect(6); //x, y, z, w

	return state;
}

Control Control::eigen_to_control(const Eigen::VectorXd &vect) {
	Control control{};

	if(vect.size() != Control::CONTROL_LENGTH){
		std::cout << "[WARNING] " << "IC_COMMONS::eigen_to_control input is not the right length !" << std::endl;
		return control;
	}

	control.roll = vect(0);
	control.pitch = vect(1);
	control.mean_thrust = vect(2);
	control.diff_thrust = vect(3);

	return control;
}