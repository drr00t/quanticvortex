
#ifndef __IPROCESS_H_
#define __IPROCESS_H_

#include "qvPrerequisites.h"

#include "IReferenceCounted.h"

namespace qv
{
    namespace runtime
    {
        enum E_PROCESS_STATUS
        {
			EPS_READY,
            EPS_STOPPED,
            EPS_RUNNING,
            EPS_COMPLETED,
            EPS_FAILED,
        };


		const c8* const ProcessStatusNames[] =
		{
			"Ready",
			"Stopped",
			"Running",
			"Completed",
			"Failed",
			0
		};

		class IProcess: public irr::IReferenceCounted
        {
        public:

			IProcess();
			virtual ~IProcess();

			virtual E_PROCESS_STATUS update(u32 elapsedTime)=0;

			virtual void setStatus(E_PROCESS_STATUS processStatus)=0;

			virtual E_PROCESS_STATUS getStatus()=0;

//			virtual const list<IProcess*>& getChildren() const =0;

        };

		//typedef list<IProcess*> ProcessList;
    }
}
#endif

