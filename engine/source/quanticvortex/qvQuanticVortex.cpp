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

#include "qvQuanticVortex.h"

#include "qvEngineManager.h"

namespace qv
{
	_QUANTICVORTEX_API_ IEngineManager* QUANTICVORTEX_CALLCONV createEngineManager( bool fullscreen,
	                                                                                bool vsync,
	                                                                                u8 bits,
	                                                                                irr::core::dimension2du windowSize,
                                                                                    irr::core::stringc title,
                                                                                    bool hostGame,
                                                                                    u8 localPlayers,
                                                                                    u8 aIPlayers,
                                                                                    u8 remotePlayers)
	{
        SGameParams params;
        params.Fullscreen = fullscreen;
        params.Vsync = vsync;
        params.Bits = bits;
        params.WindowSize = windowSize;
        params.Title = title;
        params.HostGame = hostGame;
        params.LocalPlayers = localPlayers;
        params.AIPlayers = aIPlayers;
        params.RemotePlayers = remotePlayers;

		return createEngineManagerEx(params);
	};

    //grab must be called after get the engine instance, and drop must be called be before finish game
    _QUANTICVORTEX_API_ IEngineManager* QUANTICVORTEX_CALLCONV createEngineManagerEx(const SGameParams& params)
	{
        IEngineManager* engineManager = new EngineManager(params);
		return engineManager;
	};
}


