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

#include <vector>

#include "qvTypes.h"
#include "qvSHashedString.h"


namespace qv
{
    namespace events
    {
		typedef SHashedString ET_EVENT_TYPE;

		typedef std::vector<u32> EventHashTypesArray;

        //game application events
        static const ET_EVENT_TYPE EET_GAME_LOAD = HASH_STRING("EET_GAME_LOAD");
        static const ET_EVENT_TYPE EET_GAME_NEW = HASH_STRING("EET_GAME_NEW");
        static const ET_EVENT_TYPE EET_GAME_OPTIONS = HASH_STRING("EET_GAME_OPTIONS");
        static const ET_EVENT_TYPE EET_GAME_PAUSE = HASH_STRING("EET_GAME_PAUSE");
        static const ET_EVENT_TYPE EET_GAME_QUIT = HASH_STRING("EET_GAME_QUIT");
        static const ET_EVENT_TYPE EET_GAME_SAVE = HASH_STRING("EET_GAME_SAVE");
        static const ET_EVENT_TYPE EET_GAME_STATE_CHANGE = HASH_STRING("EET_GAME_STATE_CHANGE");
        static const ET_EVENT_TYPE EET_GAME_UNPAUSE = HASH_STRING("EET_GAME_PAUSE");

        //game logic events
        static const ET_EVENT_TYPE EET_GAME_LOGIC_INITIALIZATING = HASH_STRING("EET_GAME_LOGIC_INITIALIZATING");
        static const ET_EVENT_TYPE EET_GAME_LOGIC_MENU = HASH_STRING("EET_GAME_LOGIC_MENU");
        static const ET_EVENT_TYPE EET_GAME_LOGIC_LOADING = HASH_STRING("EET_GAME_LOGIC_LOADING");
        static const ET_EVENT_TYPE EET_GAME_LOGIC_WAITING_PLAYER = HASH_STRING("EET_GAME_LOGIC_WAITING_PLAYER");
        static const ET_EVENT_TYPE EET_GAME_LOGIC_RUNNING = HASH_STRING("EET_GAME_LOGIC_RUNNING");
        static const ET_EVENT_TYPE EET_GAME_TICK_UPDATE = HASH_STRING("EET_GAME_TICK_UPDATE");
        

		static const ET_EVENT_TYPE EET_CAMERA_ACTOR_ADDED = HASH_STRING("EET_CAMERA_ACTOR_ADDED");

        static const ET_EVENT_TYPE EET_ACTOR_CREATED = HASH_STRING("EET_ACTOR_CREATED");
        static const ET_EVENT_TYPE EET_ACTOR_DESTROYED = HASH_STRING("EET_ACTOR_DESTROYED");
        static const ET_EVENT_TYPE EET_ACTOR_MOVE = HASH_STRING("EET_ACTOR_MOVE");
        static const ET_EVENT_TYPE EET_ACTOR_COLLIDE = HASH_STRING("EET_ACTOR_COLLIDE");

        static const ET_EVENT_TYPE EET_ACTOR_PLAYER_DIE = HASH_STRING("EET_ACTOR_PLAYER_DIE");
        static const ET_EVENT_TYPE EET_ACTOR_PLAYER_JUMP = HASH_STRING("EET_ACTOR_PLAYER_JUMP");
        static const ET_EVENT_TYPE EET_ACTOR_PLAYER_MOVE = HASH_STRING("EET_ACTOR_PLAYER_MOVE");
        static const ET_EVENT_TYPE EET_ACTOR_PLAYER_NEW = HASH_STRING("EET_ACTOR_PLAYER_NEW");
        static const ET_EVENT_TYPE EET_ACTOR_PLAYER_TURN = HASH_STRING("EET_ACTOR_PLAYER_TURN");
        static const ET_EVENT_TYPE EET_ACTOR_PLAYER_COLLIDE = HASH_STRING("EET_ACTOR_PLAYER_COLLIDE");
    }
}

#endif

