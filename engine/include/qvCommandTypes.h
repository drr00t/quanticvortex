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


#ifndef __COMMAND_TYPES_H_
#define __COMMAND_TYPES_H_

#include "qvSHashedString.h"


namespace qv
{
    typedef SHashedString CI_COMMAND_ID;
    typedef SHashedString CT_COMMAND_TYPE;

    //engine command types by subsystem
    static const CT_COMMAND_TYPE CT_COMMAND_EVENT = HASH_STRING("EVENT");
    static const CT_COMMAND_TYPE CT_COMMAND_INPUT = HASH_STRING("INPUT");
//	static const CI_COMMAND_ID CI_COMMAND_GAME_QUIT = new CI_COMMAND_ID("CI_COMMAND_GAME_QUIT");
//	static const CI_COMMAND_ID *CI_COMMAND_GAME_NEW = new CI_COMMAND_ID("CI_COMMAND_GAME_NEW");
//	static const CI_COMMAND_ID *CI_COMMAND_GAME_OPTIONS = new CI_COMMAND_ID("CI_COMMAND_GAME_OPTIONS");
//	static const CI_COMMAND_ID *CI_COMMAND_GAME_STATE_CHANGE = new CI_COMMAND_ID("CI_COMMAND_GAME_STATE_CHANGE");
//	static const CI_COMMAND_ID *CI_COMMAND_GAME_SAVE = new CI_COMMAND_ID("CI_COMMAND_GAME_SAVE");
//	static const CI_COMMAND_ID *CI_COMMAND_GAME_LOAD = new CI_COMMAND_ID("CI_COMMAND_GAME_LOAD");
//	static const CI_COMMAND_ID *CI_COMMAND_GAME_PAUSED = new CI_COMMAND_ID("CI_COMMAND_GAME_PAUSED");
}

#endif


