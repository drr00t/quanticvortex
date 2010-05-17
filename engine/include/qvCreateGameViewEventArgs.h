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


#ifndef __CREATE_GAME_VIEW_EVENT_ARGS_H_
#define __CREATE_GAME_VIEW_EVENT_ARGS_H_


#include "qvEventArgs.h"
#include "qvEventTypes.h"

#include "irrTypes.h"
#include "irrString.h"

namespace qv
{
namespace events
{
    static const qv::events::ET_EVENT_TYPE ET_CREATE_GAME_VIEW = HASH_STRING("ET_CREATE_GAME_VIEW");
    
class _QUANTICVORTEX_API_ CreateGameViewEventArgs: public qv::events::EventArgs
{
public:

    CreateGameViewEventArgs()
    :qv::events::EventArgs(qv::events::ET_CREATE_GAME_VIEW.Hash)
    {
    
    }
    /// create a event argument with type

    virtual ~CreateGameViewEventArgs()
    {
        
    }

    qv::c8* getSceneFile() const;
    /// scene file to be displayed by human view
    
    void setSceneFile(qv::c8* sceneFile);
    
    qv::c8* getGameViewName() const;
    /// human view name
    
    void setGameViewName(qv::c8* gameViewName);
    /// set human view name

    qv::u32 getGameViewType() const;
    /// human view name
    
    void setGameViewType(qv::u32 gameViewHashType);
    /// set human view name
    
private:

    qv::c8* mGameViewName; // human view name
    qv::u32 mGameViewHashType; // human view name
    qv::c8* mSceneFile; // scene file
};


//inlines 
inline qv::c8* CreateGameViewEventArgs::getGameViewName() const 
{ 
    return mGameViewName; 
}

inline void CreateGameViewEventArgs::setGameViewName( qv::c8* gameViewName)
{ 
    mGameViewName = gameViewName; 
}

inline qv::c8* CreateGameViewEventArgs::getSceneFile() const 
{ 
    return mSceneFile; 
}

inline void CreateGameViewEventArgs::setSceneFile( qv::c8* sceneFile)
{ 
    mSceneFile = sceneFile; 
}

inline qv::u32 CreateGameViewEventArgs::getGameViewType() const 
{ 
    return mGameViewHashType; 
}

inline void CreateGameViewEventArgs::setGameViewType( qv::u32  gameViewHashType)
{ 
    mGameViewHashType = gameViewHashType; 
}

}
}

#endif

