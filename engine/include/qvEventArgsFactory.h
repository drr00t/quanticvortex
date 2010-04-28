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


#ifndef __EVENT_ARGS_FACTORY_H_
#define __EVENT_ARGS_FACTORY_H_

#include "qvCompileConfig.h"
#include "qvEventTypes.h"
#include "qvIEventArgsFactory.h"

#include "qvRAIIFactoryImp.h"

namespace qv
{
namespace events
{

class _QUANTICVORTEX_API_ EventArgsFactory : public IEventArgsFactory
    /// default factory to create all event args to all events.
{

public:
    EventArgsFactory();

    virtual ~EventArgsFactory();

    template <class T>
    T* createEventArgs( u32 eventArgsHashType);
    /// create an EventArgs instance of an registred event type.
    
    virtual void registerEventArgsType( u32 eventArgsHashType);
    /// register a new type of event args to allow be managed 
    /// and createable by this factory.

    virtual u32 getCreatableEventArgsTypeCount() const;
    /// total event args createable type.
    
    virtual bool getCreateableEventArgsType( u32 eventArgsHashType) const;
    /// check if the desired type is createable by this factory.

private:
    qv::events::EventHashTypesArray mSupportedEventArgsTypes;  // event hash type id
    RaiiFactoryImp<qv::events::EventArgs> mEventArgs; // created event args
};

}

}

#endif

