//
// Created by Samuel on 15/06/2023.
//

#ifndef IC_SOFT_ORCHESTRATORBASE_HPP
#define IC_SOFT_ORCHESTRATORBASE_HPP

#include <iostream>
#include "OrchestratorMode.hpp"
#include "Structures.hpp"

namespace icarus::orchestrator {

	class OrchestratorBase {
	protected:
		OrchestratorMode _op_mode = IDLE;

	public:
		void run();
		virtual void run_once() {
			/**
			 * SINGLE CYCLE OF EXECUTION LOOP\n
			 *
			 * 1. Broadcast op_mode\n
			 * 2. Compute/Fetch sensor data\n
			 * 3. Fetch Targets\n
			 * 4. Fetch State\n
			 * 5. Compute commands\n
			 * 6. Move (wait for feedback)\n
			 * 7. Render\n
			 */
			std::cout << "OrchestratorBase::run" << " : " << "override me !" << std::endl;
		}

		void set_operation_mode(OrchestratorMode op_mode) {
			_op_mode = op_mode;
		}

		OrchestratorMode get_operation_mode() const {
			return _op_mode;
		}
	};

} // icarus

#endif //IC_SOFT_ORCHESTRATORBASE_HPP
