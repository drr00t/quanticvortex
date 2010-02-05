
#ifndef __PROCESSMANAGER_H_
#define __PROCESSMANAGER_H_

#include "qvPrerequisites.h"
#include "qvIProcess.h"
#include "qvIProcessManager.h"

#include "tbb/task_scheduler_init.h"

using namespace tbb;

namespace qv
{
    namespace runtime
    {
		class ProcessManager: public IProcessManager
        {
        public:
            ProcessManager();
			~ProcessManager();

			void attach( IProcess* process );
			bool hasProcesses();
			E_PROCESS_STATUS update( u32 elapsedTime);
			
		private:
			void detach( IProcess* process );
			void updateTask(IProcess* process, u32 elapsedTimeMs);

			u32 numTasks;
			bool isRunning;
			ProcessList mProcessing;
			
			//tbb scheduler initialization
			task_scheduler_init init;
        };
    }
}
#endif

