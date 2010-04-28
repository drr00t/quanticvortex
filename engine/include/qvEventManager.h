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


#ifndef __EVENT_MANAGER_H_
#define __EVENT_MANAGER_H_

#include "qvCompileConfig.h"
#include "qvEventTypes.h"
#include "qvIEventCommand.h"

//#include "qvIEventArgsFactory.h"

#include "qvRAIIFactoryImp.h"
#include "Poco/AtomicCounter.h"

namespace qv
{
namespace events
{
class _QUANTICVORTEX_API_ EventManager
    /// event manager class class to raised event and execute all 
    /// command associated to each one. EventCommand are listeners
{
public:
    EventManager();
    virtual ~EventManager();

    bool registerCommandEvent ( qv::events::IEventCommand* command);
    /// register an event command on command collection

    bool unregisterCommandEvent ( qv::events::IEventCommand* command);
    /// remove desired command from command collection

    template <class T> T* createEventArgs( u32 eventArgsHashType);
    /// create an EventArgs of specific type if this type 
    /// is registred on event args factory.

//    void registerEventArgsFactory(IEventArgsFactory * factory);
    /// register a new event args to the factory collection

    void registerEventType( u32 eventHashType);
    /// register a new event type to valid event types list

    void unregisterEventType( u32 eventHashType);
    /// remove an event type from event type list

    bool abortEvent ( u32 eventHashType);
    /// cancel the execution of an next event or all event from this type

    bool enqueueEvent (qv::events::EventArgs* args);
    /// post the event args to the raise queue

    bool processReadyEvents();
    /// raise all event enqueue on this game tick

    bool trigger ( qv::events::EventArgs* args );
    /// raise this event right now

    bool validateType(u32 eventHashType);
    /// check this event if it is valid

private:
    EventManager( const EventManager&);
    EventManager operator = ( const EventManager&);
    
    static const s32 QueueEventsLenght = 2; // double buffer event queue
    qv::events::EventHashTypesArray mValidEventTypes; // registred valid event types
    qv::events::EventCommandMap mRegistredCommandsMap; //
    qv::events::EventArgsArray mReadyEvents[QueueEventsLenght]; //to event lists to double buffering
    //	ConcurrentEventList mRealtimeReadyEvents; //this get high priority than mRadyEvents;
    //  qv::events::EventArgsFactoryVector mEventArgsFactories;
    RaiiFactoryImp<qv::events::EventArgs> mEventArgs; // created event args
    Poco::AtomicCounter mActiveReadyEventList;
};
}
}
#endif

