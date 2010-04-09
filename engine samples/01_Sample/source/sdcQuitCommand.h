
#ifndef __SDC_CONTROLLER_QUIT_COMMAND_H_
#define __SDC_CONTROLLER_QUIT_COMMAND_H_

#include "qvIEventCommand.h"

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
        /**
         * \class QuitCommand
         * \author adriano.ribeiro
         * \date 04/08/10
         * \file sdcQuitCommand.h
         * \brief 
         */
		class QuitCommand: public qv::events::IEventCommand
		{
		private:
			qv::IEngineManager* mEngine;
			array<const qv::events::ET_EVENT_TYPE*> mEventTypes;

		public:
			QuitCommand(qv::IEngineManager* engine);
			virtual ~QuitCommand();

			virtual const array<const qv::events::ET_EVENT_TYPE*>& listenEventTypes() const
			{
				return mEventTypes;
			}

			virtual void executeCommand(const qv::events::IEventArgs* args);
		};
    }
}

#endif

