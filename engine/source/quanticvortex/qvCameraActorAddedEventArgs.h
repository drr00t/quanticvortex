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


#ifndef __CAMERA_ACTOR_ADDED_EVENT_ARGS_H_
#define __CAMERA_ACTOR_ADDED_EVENT_ARGS_H_

#include "qvActorTypes.h"
#include "qvICameraActorAddedEventArgs.h"


namespace qv
{
    namespace events
    {

		class CameraActorAddedEventArgs: public ICameraActorAddedEventArgs
        {
		private:
			const ET_EVENT_TYPE* mEventType;
			const gaming::AI_ACTOR_ID* mActorID;

        public:
			CameraActorAddedEventArgs(const ET_EVENT_TYPE* eventType, const gaming::AI_ACTOR_ID* actorID);
			virtual ~CameraActorAddedEventArgs();
			
			virtual const ET_EVENT_TYPE* getEventType( void ) const  { return mEventType; }
			
			virtual u32 getTypeID( void ) const { return mEventType->HashedText; }

			virtual const c8* getTypeName( void ) const { return mEventType->Text.c_str(); }
			
			virtual u32 getCameraActorID() const { return mActorID->HashedText; }
			
			virtual const c8* getCameraActorName() const { return mActorID->Text.c_str(); }

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

