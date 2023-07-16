//
// Created by Samuel on 16/06/2023.
//

#ifndef IC_SOFT_FAKEIMU_HPP
#define IC_SOFT_FAKEIMU_HPP

#include "FakeSensor.hpp"

namespace icarus::sensor {

	class FakeIMU : public virtual FakeSensor<6, 2, 2> {

	};
}

#endif //IC_SOFT_FAKEIMU_HPP
