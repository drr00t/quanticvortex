
#include "qvFadeInOutProcess.h"


namespace qv
{
    namespace runtime
    {
        FadeInOutProcess::FadeInOutProcess(IMeshManipulator* manipulator, IMesh* mesh)
			:mManipulator(manipulator), mMesh(mesh),mFactor(0),mTotalElapsedTime(0)
        {
			// set the alpha value of all vertices to 200
			manipulator->setVertexColorAlpha(mesh, 0);
			mProcessStatus = Process::Running;
        }

        FadeInOutProcess::~FadeInOutProcess()
        {
        }

		Process::ProcessStatus FadeInOutProcess::update(irr::u32 elapsedTime)
		{
			if(mFactor == 0)
				mFactor += 5;
			
			mTotalElapsedTime += elapsedTime;

			mManipulator->setVertexColorAlpha(mMesh,mFactor);

			if((mTotalElapsedTime >= 500) && (mFactor < 255))
			{
				mFactor += 50;
				mTotalElapsedTime = 0;
			}
			
			if(mFactor >= 255)
				mProcessStatus = Process::Completed;

			return mProcessStatus;
		}
    }
}

