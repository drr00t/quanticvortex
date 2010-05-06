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


#include "qvEventArgsFactory.h"

#include "qvEventArgs.h"
//#include "qvChangeStateEventArgs.h"

namespace qv
{
namespace events
{
//-----------------------------------------------------------------------------------------
EventArgsFactory::EventArgsFactory()
{
    // event args that get any arguments
    mSupportedEventArgsTypes.push_back(qv::events::EET_GAME_QUIT.Hash);
    mSupportedEventArgsTypes.push_back(qv::events::EET_GAME_NEW.Hash);
    mSupportedEventArgsTypes.push_back(qv::events::EET_GAME_LOGIC_STATE_CHANGE.Hash);
}
//-----------------------------------------------------------------------------------------
EventArgsFactory::~EventArgsFactory()
{
}
//-----------------------------------------------------------------------------------------------
template<class T> T* EventArgsFactory::createEventArgs( u32 eventArgsHashType)
{
    qv::events::EventArgs* eventArgs;

    if(getCreateableEventArgsType(eventArgsHashType))
        eventArgs = mEventArgs.keep(new T( eventArgsHashType));

    return static_cast<T*>(eventArgs);
}
//-----------------------------------------------------------------------------------------------
void EventArgsFactory::registerEventArgsType( u32 eventArgsHashType)
{
    if(!getCreateableEventArgsType(eventArgsHashType))
        mSupportedEventArgsTypes.push_back(eventArgsHashType);
}
//-----------------------------------------------------------------------------------------
u32 EventArgsFactory::getCreatableEventArgsTypeCount() const
{
    return mSupportedEventArgsTypes.size();
}
//-----------------------------------------------------------------------------------------
bool EventArgsFactory::getCreateableEventArgsType( u32 eventArgsHashType) const
{
    for (u32 i=0; i<mSupportedEventArgsTypes.size(); ++i)
        if (mSupportedEventArgsTypes[i] == eventArgsHashType)
            return true;

    return false;

}
//-----------------------------------------------------------------------------------------
}
}
