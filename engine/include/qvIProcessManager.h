
#ifndef __IPROCESSMANAGER_H_
#define __IPROCESSMANAGER_H_

#include "qvPrerequisites.h"

//naemspace
#include "IReferenceCounted.h"

namespace qv
{
    namespace runtime
    {
		class IProcess;

		class IProcessManager: public irr::IReferenceCounted
        {
        public:
   //         virtual IProcessManager()=0;
			//virtual ~IProcessManager()=0;

			virtual void attach( IProcess* process )=0;
			virtual void detach( IProcess* process )=0;

			virtual bool hasProcesses()=0;

			virtual E_PROCESS_STATUS update( u32 elapsedTime)=0;
        };
    }
}
#endif

