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


#ifndef __CHANGE_STATE_EVENT_ARGS_H_
#define __CHANGE_STATE_EVENT_ARGS_H_

#include "qvIChangeStateEventArgs.h"

namespace qv
{
    namespace events
    {
        class ChangeStateEventArgs: public IChangeStateEventArgs
        {
		private:
			const ET_EVENT_TYPE* mEventType;
			const gaming::S_STATE_TYPE* mStateType;

        public:
            ChangeStateEventArgs(const ET_EVENT_TYPE* eventType, const gaming::S_STATE_TYPE* state );
			virtual ~ChangeStateEventArgs();

            virtual const ET_EVENT_TYPE* getEventType( void ) const
			{
				return mEventType;
			}

			virtual u32 getTypeID( void ) const
			{
				return mEventType->HashedText;
			}

			virtual const stringc& getTypeName( void ) const
			{
				return mEventType->Text;
			}
            
			virtual const gaming::S_STATE_TYPE* getState( void ) const
			{
				return mStateType;
			}

	        //! Writes attributes of the object.
	        /** Implement this to expose the attributes of your scene node animator for
	        scripting languages, editors, debuggers or xml serialization purposes. */
			virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const{}

	        //! Reads attributes of the object.
	        /** Implement this to set the attributes of your scene node animator for
	        scripting languages, editors, debuggers or xml deserialization purposes. */
			virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0){}

        };
    }
}

#endif

