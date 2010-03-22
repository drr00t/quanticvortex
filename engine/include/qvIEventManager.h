/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009-2010 QuanticMinds Software Ltda.
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

**************************************************************************************************/


#ifndef __I_EVENT_MANAGER_H_
#define __I_EVENT_MANAGER_H_

//#include "qvPrerequisites.h"
#include "qvIEventCommand.h"
#include "qvIEventArgs.h"
//#include "qvEventTypes.h"
#include "qvStateTypes.h"


namespace qv
{
    namespace events
    {
//		class IChangeStateEventArgs;
		class ICameraActorAddedEventArgs;
//		class IEventCommand;
		class IEventArgs;
		class IEventArgsFactory;
//		class IDynamicActorAddedEventArgs;
//		class IStaticActorAddedEventArgs;


		class IEventManager: public IReferenceCounted
		{

		public:

			virtual bool registerCommandEvent ( IEventCommandSharedPtr command) = 0;

			virtual bool unregisterCommandEvent ( IEventCommandSharedPtr command) = 0;
			//virtual bool unregisterCommandEvent ( const CT_COMMAND_TYPE& commandType)=0;
			//event args
			virtual IEventArgsSharedPtr createEmptyEventArgs(const ET_EVENT_TYPE & type) = 0;
//			virtual IChangeStateEventArgs* createChangeStateEventArgs(const S_STATE* state)=0;

			virtual ICameraActorAddedEventArgs* createCameraActorAddedEventArgs(const c8 * name) = 0;
//			virtual IStaticActorAddedEventArgs* createStaticActorAddedEventArgs(const c8* name)=0;
//			virtual IDynamicActorAddedEventArgs* createDynamicActorAddedEventArgs(const c8* name)=0;

			virtual void registerEventArgsFactory(IEventArgsFactory * factory) = 0;

			virtual void registerEventType(const ET_EVENT_TYPE & type) = 0;

			virtual void unregisterEventType(const ET_EVENT_TYPE & type) = 0;

			virtual void registerEventType( u32 eventHashType) = 0;

			virtual void unregisterEventType( u32 eventHashType) = 0;

			virtual bool abortEvent ( const ET_EVENT_TYPE & type, bool all = false ) = 0;

			virtual bool abortEvent ( u32 eventHashType, bool all = false ) = 0;

			virtual bool enqueueEvent (IEventArgs * args) = 0;

			virtual bool enqueueEvent (IEventArgsSharedPtr args) = 0;

			virtual bool process ( f32 processingTime) = 0;

			virtual bool trigger ( IEventArgs * args ) = 0;

			virtual bool trigger ( IEventArgsSharedPtr args ) = 0;

			virtual bool validateType(const ET_EVENT_TYPE & type) = 0;

			virtual bool validateType( u32 eventHashType) = 0;

			//default event args
		};
	}
}
#endif

