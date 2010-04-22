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


#ifndef __ACTOR_H_
#define __ACTOR_H_

// system headers
#include <vector>

// engine headers
#include "qvActorTypes.h"

// external headers
#include "irrMap.h"

#include "LinearMath/btTransform.h"


namespace qv
{
namespace gaming
{

/**
 * \class IActor
 * \author adriano
 * \date 04/11/10
 * \file qvIActor.h
 * \brief
 */
class Actor
{
public:

    Actor()
    :mActorHashId(0), mActorHashType(0),mDefence(0),
     mMaxLife(0), mLife(0), mSpeed(0.0f, 0.0f, 0.0f),
     mExperience(0), mVisible(true)
    {


    }

    u32 getHashId() const;
    /// actor id

    u32 getHashType() const;
    /// type of actor

    s32 getMaxLife() const;
    /// max life of the actor

    void updateMaxLife(s32 value);
    /// update max life of the actor addin or reducing
    /// max life with value passed by user

    s32 getLife() const;
    /// current life of the actor

    void updateLife(s32 value);
    /// update life of the actor addin or reducing
    /// life of the actor with value passed by user

    s32 getExperience() const;
    /// current experience level of actor

    void updateExperience(s32 value);
    /// update experience of the actor addin or reducing
    /// experience of the actor with value passed by user

    s32 getDefence() const;
    /// current defence level of the actor

    void updateDefence(s32 value);
    /// update defence of the actor addin or reducing
    /// defence of the actor with value passed by user

    btVector3 getSpeed() const;
    /// speed of the actor

    void updateSpeed( btVector3 newSpeed);
    /// update speed of the actor

    bool visible () const;
    /// visibility of the actor

    void updateVisibility ( bool visible);
    /// update visibility of the actor

private:

    Actor(const Actor&);
    Actor& operator = (const Actor&);

    s32 mMaxLife;
    s32 mLife;
    s32 mExperience;
    s32 mDefence;
    u32 mActorHashType;
    u32 mActorHashId;
    bool mVisible;
    btVector3 mSpeed;

};

typedef irr::core::map<u32, Actor*> ActorsMap;
typedef std::vector<Actor*> ActorsArray;


//inlines
inline u32 Actor::getHashId() const
{
    return mActorHashId;
}

inline u32 Actor::getHashType() const
{
    return mActorHashType;
}

inline s32 Actor::getMaxLife() const
{
    return mMaxLife;
}

inline void Actor::updateMaxLife( s32 value)
{
    mMaxLife += value;
}

inline s32 Actor::getLife() const
{
    return mLife;
}

inline void Actor::updateLife(s32 value)
{
    mLife += value;
}

inline s32 Actor::getExperience() const
{
    return mExperience;
}

inline void Actor::updateExperience( s32 value)
{
    mExperience += value;
}

inline s32 Actor::getDefence() const
{
    return mDefence;
}

inline void Actor::updateDefence( s32 value)
{
    mDefence += value;
}

inline btVector3 Actor::getSpeed() const
{
    return mSpeed;
}

inline void Actor::updateSpeed(btVector3 newSpeed)
{
    mSpeed = newSpeed;
}

inline bool Actor::visible () const
{
    return mVisible;
}

inline void Actor::updateVisibility(bool visible)
{
    mVisible = visible;
}


}


}
#endif

