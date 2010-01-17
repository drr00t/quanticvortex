
#ifndef __FADEINOUTPROCESS_H_
#define __FADEINOUTPROCESS_H_

#include "runtime/qvProcess.h"

using namespace irr::scene;

using namespace qv::runtime;

namespace qv
{
    namespace runtime
    {
		class FadeInOutProcess: public Process
        {
		protected:
			IMeshManipulator* mManipulator;
			IMesh* mMesh;
			s32 mFactor;
			u32 mTotalElapsedTime;

        public:

			FadeInOutProcess(IMeshManipulator* manipulator, IMesh* mesh);
			virtual ~FadeInOutProcess();

			//! OnUpdate() is called by the TaskTree when the time has come to execute the task's code.
			/** OnUpdate is typically the most important function.  OnUpdate is only called when enough time has passed
				or every frame, depending upon what the priority of the task is.  If you want code to execute on a time-based
				basis, put that code here and add the task to the tree.		*/
			virtual ProcessStatus update(u32 elapsedTime);

        };
    }
}
#endif

