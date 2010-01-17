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


#ifndef __SGAMEPARAMS_H_
#define __SGAMEPARAMS_H_

#include "qvPrerequisites.h"

namespace qv
{
	struct SGameParams
    {

		SGameParams():
			Title(L"Default Game Title"),
			WindowSize(dimension2du(1024, 768)),
			Bits(16),
			Fullscreen(false),
			Vsync(false),
            HostGame(false),
            LocalPlayers(1),
            AIPlayers(0),  //player vs computer games i can use this to test the ai and animation, maybe
            RemotePlayers(0)
		{
		}

		SGameParams(const SGameParams& other)
		{
			*this = other;
		}

		SGameParams& operator= (const SGameParams& other)
		{
			Title = other.Title;
			WindowSize = other.WindowSize;
			Bits = other.Bits;
			Fullscreen = other.Fullscreen;
			Vsync = other.Vsync;

            HostGame = other.HostGame;
            LocalPlayers = other.LocalPlayers;
            AIPlayers = other.AIPlayers;
            RemotePlayers = other.RemotePlayers;

            //input variables
            ShowCursor = other.ShowCursor;
            InputBuffered = other.InputBuffered;
            InputDebug = other.InputDebug;
            WindowSize = other.WindowSize;

			return *this;
		}
        
        dimension2du WindowSize;
        bool Fullscreen;
		bool Vsync;
		u8 Bits;        
		
        bool HostGame;
        u8 LocalPlayers;
        u8 AIPlayers;
        u8 RemotePlayers;

        bool ShowCursor;
        bool InputBuffered;
        bool InputDebug;

        stringw Title;
        //texture size
        //detail level
        //shadow maps
        //realtime shadows
	};
}
#endif

