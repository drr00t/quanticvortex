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


#ifndef __EVENT_TYPES_H_
#define __EVENT_TYPES_H_

#include "qvPrerequisites.h"
#include "qvSHashedString.h"


namespace qv
{
    namespace events
    {       
		typedef SHashedString ET_EVENT_TYPE;
        
        //engine sertvices events
        static const ET_EVENT_TYPE *ET_GRAPHICS_STARTED = new ET_EVENT_TYPE("ET_GRAPHICS_STARTED");
        static const ET_EVENT_TYPE *ET_GRAPHICS_STOPPED = new ET_EVENT_TYPE("ET_GRAPHICS_STOPPED");

        static const ET_EVENT_TYPE *ET_EVENT_SYSTEM_STARTED = new ET_EVENT_TYPE("ET_EVENT_SYSTEM_STARTED");
        static const ET_EVENT_TYPE *ET_EVENT_SYSTEM_STOPPED = new ET_EVENT_TYPE("ET_EVENT_SYSTEM_STOPPED");

        //game application events
        static const ET_EVENT_TYPE *ET_GAME_LOAD = new ET_EVENT_TYPE("ET_GAME_LOAD");
        static const ET_EVENT_TYPE *ET_GAME_NEW = new ET_EVENT_TYPE("ET_GAME_NEW");
        static const ET_EVENT_TYPE *ET_GAME_OPTIONS = new ET_EVENT_TYPE("ET_GAME_OPTIONS");
        static const ET_EVENT_TYPE *ET_GAME_PAUSE = new ET_EVENT_TYPE("ET_GAME_PAUSE");
        static const ET_EVENT_TYPE *ET_GAME_QUIT = new ET_EVENT_TYPE("ET_GAME_QUIT");
        static const ET_EVENT_TYPE *ET_GAME_SAVE = new ET_EVENT_TYPE("ET_GAME_SAVE");
        static const ET_EVENT_TYPE *ET_GAME_STATE_CHANGE = new ET_EVENT_TYPE("ET_GAME_STATE_CHANGE");
        static const ET_EVENT_TYPE *ET_GAME_UNPAUSE = new ET_EVENT_TYPE("ET_GAME_PAUSE");

        //game logic events
        static const ET_EVENT_TYPE *ET_GAME_LOGIC_STARTED = new ET_EVENT_TYPE("ET_GAME_LOGIC_STARTED");
        static const ET_EVENT_TYPE *ET_GAME_LOGIC_STOPPED = new ET_EVENT_TYPE("ET_GAME_LOGIC_STOPPED");
        static const ET_EVENT_TYPE *ET_GAME_LOGIC_TICK_UPDATE = new ET_EVENT_TYPE("ET_GAME_LOGIC_TICK");

        static const ET_EVENT_TYPE *ET_HUMAN_VIEW_ATTACHED = new ET_EVENT_TYPE("ET_HUMAN_VIEW_ATTACHED");
        static const ET_EVENT_TYPE *ET_HUMAN_VIEW_DETACHED = new ET_EVENT_TYPE("ET_HUMAN_VIEW_DETACHED");
        
        static const ET_EVENT_TYPE *ET_PHYSICS_STARTED = new ET_EVENT_TYPE("ET_PHYSICS_STARTED");
        static const ET_EVENT_TYPE *ET_PHYSICS_STOPPED = new ET_EVENT_TYPE("ET_PHYSICS_STOPPED");

        static const ET_EVENT_TYPE *ET_ACTOR_CREATED = new ET_EVENT_TYPE("ET_ACTOR_CREATED");
        static const ET_EVENT_TYPE *ET_ACTOR_DESTROYED = new ET_EVENT_TYPE("ET_ACTOR_DESTROYED");
        static const ET_EVENT_TYPE *ET_ACTOR_MOVE = new ET_EVENT_TYPE("ET_ACTOR_MOVE");
        static const ET_EVENT_TYPE *ET_ACTOR_COLLIDE = new ET_EVENT_TYPE("ET_ACTOR_COLLIDE");

        static const ET_EVENT_TYPE *ET_ACTOR_PLAYER_DIE = new ET_EVENT_TYPE("ET_ACTOR_PLAYER_DIE");
        static const ET_EVENT_TYPE *ET_ACTOR_PLAYER_JUMP = new ET_EVENT_TYPE("ET_ACTOR_PLAYER_JUMP");
        static const ET_EVENT_TYPE *ET_ACTOR_PLAYER_MOVE = new ET_EVENT_TYPE("ET_ACTOR_PLAYER_MOVE");
        static const ET_EVENT_TYPE *ET_ACTOR_PLAYER_NEW = new ET_EVENT_TYPE("ET_ACTOR_PLAYER_NEW");
        static const ET_EVENT_TYPE *ET_ACTOR_PLAYER_TURN = new ET_EVENT_TYPE("ET_ACTOR_PLAYER_TURN");
        static const ET_EVENT_TYPE *ET_ACTOR_PLAYER_COLLIDE = new ET_EVENT_TYPE("ET_ACTOR_PLAYER_COLLIDE");
        

        

        //game application events...
        //mEventManager->registerEventType(GraphicsStartedEventArgs::mEventType);
        //mEventManager->registerEventType(PhysicsStartedEventArgs::mEventType);
        //mEventManager->registerEventType(EventSystemStartedEventArgs::mEventType);
        //mEventManager->registerEventType(HumanViewAttachedEventArgs::mEventType);
        //mEventManager->registerEventType(GameLogicStartedEventArgs::mEventType);
        //mEventManager->registerEventType(DestroyActorEventArgs::mEventType);

		//game logic events...
		//mEventManager->registerEventType(UpdateTickEventArgs::mEventType);
  //      mEventManager->registerEventType(NewGameEventArgs::mEventType);
  //      mEventManager->registerEventType(GameStateEventArgs::mEventType);
    //	//General game events...
    //	m_pEventManager->RegisterCodeOnlyEvent( EvtData_Debug_String::sk_EventType );


		//game actors events
  //      mEventManager->registerEventType(NewActorEventArgs::mEventType);
  //      mEventManager->registerEventType(DestroyActorEventArgs::mEventType);
		//mEventManager->registerEventType(MoveActorEventArgs::mEventType);
    }
}

#endif

