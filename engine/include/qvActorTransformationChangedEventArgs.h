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


#ifndef __ACTOR_TRANSFORMATION_CHANGED_EVENT_ARGS_H_
#define __ACTOR_TRANSFORMATION_CHANGED_EVENT_ARGS_H_

#include <vector>

#include "qvCommandArgs.h"
#include "qvTypes.h"

#include "LinearMath/btTransform.h"

namespace qv
{
namespace events
{
class _QUANTICVORTEX_API_ ActorTransformationChangedEventArgs: public qv::CommandArgs
{
public:

    ActorTransformationChangedEventArgs( const qv::CT_COMMAND_TYPE& commandType)
    :qv::CommandArgs(commandType)
    {
    
    }
    /// create a event argument with type

    virtual ~ActorTransformationChangedEventArgs();
    /// destroy game view tick

    qv::u32 getActorHashId() const;
    /// elapsed time since last game logic tick in miliseconds
    
    const btTransform& getTransform() const;
    
    void setTransform( const btTransform& tranformation);
    /// setup new elapsed time since last game logic tick in miliseconds    
private:

    btTransform mTransform; // actor transformation
};


//inlines 
inline const btTransform& ActorTransformationChangedEventArgs::getTransform() const 
{ 
    return mTransform; 
}

inline void ActorTransformationChangedEventArgs::setTransform( const btTransform& tranform)
{
    mTransform = tranform;
}

}
}

#endif

