
#ifndef __SDC_CONTROLLER_QUIT_COMMAND_H_
#define __SDC_CONTROLLER_QUIT_COMMAND_H_

#include "qvICommandEvent.h"

namespace qv
{
	class IEngineManager;

	namespace events
	{
		class IEventArgs;
	}
}

namespace sdc
{
    namespace controller
    {
		class QuitCommand: public qv::events::ICommandEvent
		{
		private:
			qv::IEngineManager* mEngine;
			array<const qv::events::ET_EVENT_TYPE*> mEventTypes;

		public:
			QuitCommand(qv::IEngineManager* engine);
			virtual ~QuitCommand();

			//virtual const qv::CI_COMMAND_ID* getCommandID() const
			//{
			//	return mID;
			//}

			//virtual u32 getID() const
			//{
			//	return mType->HashedText;
			//}
			//
			//virtual const stringc& getName() const
			//{
			//	return mType->Text;
			//}

			virtual const array<const qv::events::ET_EVENT_TYPE*>& listenEventTypes() const
			{
				return mEventTypes;
			}

			virtual void executeCommand(const qv::events::IEventArgs* args);
		};
    }
}

#endif

