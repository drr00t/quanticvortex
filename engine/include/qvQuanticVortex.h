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


#ifndef __QUANTICVORTEX_ENGINE_H_
#define __QUANTICVORTEX_ENGINE_H_

#include "qvCompileConfig.h"

//gaming
#include "qvIActor.h"
#include "qvIEventManager.h"
#include "qvIGameLogic.h"
#include "qvIGameLogicFactory.h"

#include "qvSActorParams.h"

//input
#include "qvICommandInput.h"
#include "qvIInputReceiver.h"
#include "qvIInputTranslator.h"
#include "qvIInputTranslatorFactory.h"

//physics
//#include "qvIPhysicsActor.h"
//#include "qvIPhysicsManager.h"

//runtime
#include "qvIProcess.h"
#include "qvIProcessManager.h"

//views
#include "qvIElementView.h"
#include "qvIGameView.h"
#include "qvIGameViewFactory.h"
#include "qvIGuiView.h"
#include "qvIHumanView.h"
#include "qvISceneView.h"


//utils
#include "qvSingletonHolder.h"
#include "qvSUniqueID.h"

//qv
#include "qvIEngineManager.h"
#include "qvSGameParams.h"
//#include "qvSuperFastHash.h"


namespace qv
{
    extern "C" _QUANTICVORTEX_API_ IEngineManager* QUANTICVORTEX_CALLCONV createEngineManager( 
                                                                                        bool fullscreen = false,
		                                                                                bool vsync = false,
		                                                                                u8 bits = 16,
		                                                                                dimension2du windowSize = dimension2du(1024,768),
                                                                                        stringw title = "Quantic Vortex Game",
                                                                                        bool hostGame = true,
                                                                                        u8 localPlayers = 1,
                                                                                        u8 aIPlayers = 0,
                                                                                        u8 remotePlayers = 0);

	extern "C" _QUANTICVORTEX_API_ IEngineManager* QUANTICVORTEX_CALLCONV createEngineManagerEx(const SGameParams& params);
}



#endif

