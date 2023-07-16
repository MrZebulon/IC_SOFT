//
// Created by Samuel on 15/06/2023.
//

#include "OrchestratorBase.hpp"

using namespace icarus::orchestrator;

void OrchestratorBase::run() {
	/**
	 * RUN ENDPOINT\n
	 *
	 * Calls run_once if orchestrator is not IDLE
	 */

	if(_op_mode == IDLE)
		return;

	run_once();
}
