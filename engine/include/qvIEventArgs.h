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


#ifndef __I_EVENT_ARGS_H_
#define __I_EVENT_ARGS_H_

#include "qvEventTypes.h"


namespace qv
{
    namespace events
    {

		class IEventArgs //: public io::IAttributeExchangingObject
        {
		//protected:
		//	const ET_EVENT_TYPE* mEventType;

        public:
			//IEventArgs(const ET_EVENT_TYPE* eventType = 0)
			//	:mEventType(eventType)
			//{
			//}

			//virtual ~IEventArgs();
//			virtual const ET_EVENT_TYPE* getEventType( void ) const =0; // { return mEventType; }
            virtual u32 getHashType( ) const  = 0; //{ return mEventType->HashedText; }
//			virtual const c8* getTypeName( void ) const  =0; //{ return mEventType->Text; }

	        //! Writes attributes of the object.
	        /** Implement this to expose the attributes of your scene node animator for
	        scripting languages, editors, debuggers or xml serialization purposes. */
//			virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const = 0;

	        //! Reads attributes of the object.
	        /** Implement this to set the attributes of your scene node animator for
	        scripting languages, editors, debuggers or xml deserialization purposes. */
//			virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) = 0;

	        //virtual IEventData copy() const = 0;
        };

        typedef boost::shared_ptr<IEventArgs> IEventArgsSharedPtr;
        typedef list<IEventArgsSharedPtr> EventArgslist;
        typedef array<IEventArgsSharedPtr> EventArgsArray;
    }
}

#endif

