//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_FAKEMAGNETOMETER_HPP
#define IC_SOFT_FAKEMAGNETOMETER_HPP

#include "FakeSensor.hpp"

namespace icarus::sensor {
	class FakeMagnetometer : public virtual FakeSensor<3, 1, 1> {

	};
}


#endif //IC_SOFT_FAKEMAGNETOMETER_HPP
