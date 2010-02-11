
#include "runtime/qvProcessManager.h"

namespace qv
{
    namespace runtime
    {
        //-----------------------------------------------------------------------------------------
        ProcessManager::ProcessManager()
        {
        }
        //-----------------------------------------------------------------------------------------
        ProcessManager::~ProcessManager()
        {
			ProcessList::Iterator itr = mProcessing.begin();

			while(itr != mProcessing.end())
			{
				(*itr)->drop();
				mProcessing.erase(itr);
			}
        }
        //-----------------------------------------------------------------------------------------
		void ProcessManager::attach(Process* process)
		{
			process->setStatus(Process::Running);
			mProcessing.push_back(process);
		}
        //-----------------------------------------------------------------------------------------
		void ProcessManager::detach(Process* process)
		{
			ProcessList::Iterator itr = mProcessing.begin();

			while(itr != mProcessing.end())
			{
				if(process == *itr)
				{
					(*itr)->drop();
					mProcessing.erase(itr);
					break;
				}

				++itr;
			}
		}
        //-----------------------------------------------------------------------------------------
		Process::ProcessStatus ProcessManager::update(u32 elapsedTime)
		{
            Process::ProcessStatus status = Process::Completed;
			ProcessList::Iterator itr = mProcessing.begin();
			while(itr != mProcessing.end())
			{
				Process::ProcessStatus satus = (*itr)->update(elapsedTime);

				if((status == Process::Completed) ||
					(status == Process::Failed))
				{
					(*itr)->drop();
					mProcessing.erase(itr);
				}
			}

            return status;
		}
        //-----------------------------------------------------------------------------------------
        void ProcessManager::updateTask(Process* process, u32 elapsedTimeMs)
        {
            //irr::u32 currentTime = irrlichtDevice->getTimer()->getTime();

	        irr::u32 taskPauseTime = 0 ;//process->getPauseUnpauseTime();
	        irr::u32 timeToStayPaused = 0 ;//process->getTimeToStayPaused();
	        irr::u32 timeToStayUnpaused = 0 ;//process->getTimeToStayUnpaused();
	        irr::u32 timeSincePause = 0 ;//currentTime - taskPauseTime; i will need change this, to timePaused and i will count de paused time of process shoud stay

	        if(!process->isPaused()) 
            {
		        //u32 delta = elapsedTimeMs; // task->GetDeltaTimer()->GetDelta();  will be replaced by elapsedTimeMs
                u32 priority = process->getPriority(); //run to run process again, like a execution frequency
		        u32 totalElapsedTime = process->GetTotalTimeDelta(); //totalElapsedTime += elapsedTime
                u32 lifetimeExecutions = process->GetLifetimeExecutions();
                u32 lifetimeMS = process->GetLifetimeMS();
				u32 numExecutions = process->GetExecutedTimes();
                bool executeMultiple = process->GetExecuteMultiple();

		        u32 timesToExecute = 1;

		        if(priority == 0 || totalElapsedTime > priority) 
                {
			        if(priority != 0 && executeMultiple) 
                    {
				        timesToExecute = elapsedTimeMs / priority;
			        }
        			
			        for(u32 i = 0; i < timesToExecute; i++) 
					{
						process->update(elapsedTimeMs);
						process->SetExecutedTimes(numExecutions + 1);
				        numExecutions++;
        				
				        if(lifetimeExecutions != 0 && lifetimeExecutions <= numExecutions) 
						{
							process->onLifetimeExpired();
					        //DestroyChildren(task);
					        //DestroyTask(task);
        					
					        break;
				        }
        				
				        totalElapsedTime += elapsedTimeMs;
				        process->SetTotalTimeDelta(totalElapsedTime);
				        //task->GetDeltaTimer()->ResetDelta(); //put current time to process elapsedTime
        				
				        if(lifetimeMS != 0 && totalElapsedTime >= lifetimeMS) {
							process->onLifetimeExpired();
					        //DestroyChildren(task);
					        //DestroyTask(task);
        					
					        break;
				        }
			        }
		        }
        		
		        // check to see if enough time has passed to pause the task
		        //if(timeToStayUnpaused != 0 && timeSincePause > timeToStayUnpaused) {
          //          PauseTask(task, timeToStayPaused, timeToStayUnpaused);
		        //}

				//UpdateChildren(process);
	        }
	        // if the task is paused, check to see if it should be automatically
	        // unpaused
	  //      else 
			//{
   //             if(timeToStayPaused != 0 && timeSincePause > timeToStayPaused) {
   //                 UnpauseTask(task, timeToStayUnpaused, timeToStayPaused);
   //             }
	  //      }
        }
        //-----------------------------------------------------------------------------------------
    }
}

