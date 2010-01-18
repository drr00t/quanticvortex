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


#ifndef __GAME_VIEW_TYPES_H_
#define __GAME_VIEW_TYPES_H_

#include "qvPrerequisites.h"
#include "qvSUniqueID.h"


namespace qv
{
    namespace views
    {        
        typedef UniqueID GVI_GAME_VIEW_ID;
		typedef UniqueID GVT_GAME_VIEW_TYPE;
        
        //engine sertvices events
        static const GVT_GAME_VIEW_TYPE GVT_GAME_VIEW_AI("GVT_GAME_VIEW_AI");               //decision makeing events, sensor system
        static const GVT_GAME_VIEW_TYPE GVT_GAME_VIEW_HUMAN("GVT_GAME_VIEW_HUMAN");         //local human player view
        static const GVT_GAME_VIEW_TYPE GVT_GAME_VIEW_NETWORK("GVT_GAME_VIEW_NETWORK");     //network player (proxy)
        static const GVT_GAME_VIEW_TYPE GVT_GAME_VIEW_PHYSICS("GVT_GAME_VIEW_PHYSICS");     //i will try use this for physics debuging
        static const GVT_GAME_VIEW_TYPE GVT_GAME_VIEW_RECORDER("GVT_GAME_VIEW_RECORDER");   //listen all events fired 


    }
}

#endif

