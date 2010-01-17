/**************************************************************************************************

//This code is part of QuanticVortex for latest information, see http://www.quanticvortex.org
//
//Copyright (c) 2009 QuanticMinds Software Ltda.
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


#ifndef __EVENTTYPES_H_
#define __EVENTTYPES_H_

#include "qvPrerequisites.h"
#include "qvSUniqueID.h"


namespace qv
{
    namespace gaming
    {        
		typedef UniqueID ET_EVENT_TYPE;
        
        //engine sertvices events
        static const ET_EVENT_TYPE ET_GRAPHICS_STARTED("ET_GRAPHICS_STARTED");
        static const ET_EVENT_TYPE ET_GRAPHICS_STOPPED("ET_GRAPHICS_STOPPED");

        static const ET_EVENT_TYPE ET_EVENT_SYSTEM_STARTED("ET_EVENT_SYSTEM_STARTED");
        static const ET_EVENT_TYPE ET_EVENT_SYSTEM_STOPPED("ET_EVENT_SYSTEM_STOPPED");

        //game application events
        static const ET_EVENT_TYPE ET_GAME_LOAD("ET_GAME_LOAD");
        static const ET_EVENT_TYPE ET_GAME_NEW("ET_GAME_NEW");
        static const ET_EVENT_TYPE ET_GAME_OPTIONS("ET_GAME_OPTIONS");
        static const ET_EVENT_TYPE ET_GAME_PAUSE("ET_GAME_PAUSE");
        static const ET_EVENT_TYPE ET_GAME_QUIT("ET_GAME_SAVE");
        static const ET_EVENT_TYPE ET_GAME_SAVE("ET_GAME_SAVE");
        static const ET_EVENT_TYPE ET_GAME_STATE_CHANGE("ET_GAME_STATE_CHANGE");
        static const ET_EVENT_TYPE ET_GAME_UNPAUSE("ET_GAME_PAUSE");

        //game logic events
        static const ET_EVENT_TYPE ET_GAME_LOGIC_STARTED("ET_GAME_LOGIC_STARTED");
        static const ET_EVENT_TYPE ET_GAME_LOGIC_STOPPED("ET_GAME_LOGIC_STOPPED");
        static const ET_EVENT_TYPE ET_GAME_LOGIC_TICK_UPDATE("ET_GAME_LOGIC_TICK");

        static const ET_EVENT_TYPE ET_HUMAN_VIEW_ATTACHED("ET_HUMAN_VIEW_ATTACHED");
        static const ET_EVENT_TYPE ET_HUMAN_VIEW_DETACHED("ET_HUMAN_VIEW_DETACHED");
        
        static const ET_EVENT_TYPE ET_PHYSICS_STARTED("ET_PHYSICS_STARTED");
        static const ET_EVENT_TYPE ET_PHYSICS_STOPPED("ET_PHYSICS_STOPPED");

        static const ET_EVENT_TYPE ET_ACTOR_CREATED("ET_ACTOR_CREATED");
        static const ET_EVENT_TYPE ET_ACTOR_DESTROYED("ET_ACTOR_DESTROYED");
        static const ET_EVENT_TYPE ET_ACTOR_MOVE("ET_ACTOR_MOVE");
        static const ET_EVENT_TYPE ET_ACTOR_COLLIDE("ET_ACTOR_COLLIDE");

        static const ET_EVENT_TYPE ET_ACTOR_PLAYER_DIE("ET_ACTOR_PLAYER_DIE");
        static const ET_EVENT_TYPE ET_ACTOR_PLAYER_JUMP("ET_ACTOR_PLAYER_JUMP");
        static const ET_EVENT_TYPE ET_ACTOR_PLAYER_MOVE("ET_ACTOR_PLAYER_MOVE");
        static const ET_EVENT_TYPE ET_ACTOR_PLAYER_NEW("ET_ACTOR_PLAYER_NEW");
        static const ET_EVENT_TYPE ET_ACTOR_PLAYER_TURN("ET_ACTOR_PLAYER_TURN");
        static const ET_EVENT_TYPE ET_ACTOR_PLAYER_COLLIDE("ET_ACTOR_PLAYER_COLLIDE");
        

        

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

