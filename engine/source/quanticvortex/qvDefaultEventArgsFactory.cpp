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


#include "qvDefaultEventArgsFactory.h"

#include "qvEventArgs.h"
#include "qvCameraActorAddedEventArgs.h"
//#include "qvChangeStateEventArgs.h"

namespace qv
{
    namespace events
    {
        //-----------------------------------------------------------------------------------------
        DefaultEventArgsFactory::DefaultEventArgsFactory()
        {
			mSupportedEventArgsTypes.push_back(ET_GAME_QUIT.Hash);
			mSupportedEventArgsTypes.push_back(ET_GAME_NEW.Hash);
			mSupportedEventArgsTypes.push_back(ET_GAME_STATE_CHANGE.Hash);
			mSupportedEventArgsTypes.push_back(ET_CAMERA_ACTOR_ADDED.Hash);
        }
        //-----------------------------------------------------------------------------------------
        DefaultEventArgsFactory::~DefaultEventArgsFactory()
        {
        }
		//-----------------------------------------------------------------------------------------------
		IEventArgsSharedPtr DefaultEventArgsFactory::addEmptyEventArgs( const ET_EVENT_TYPE& type)
		{
			IEventArgsSharedPtr eventArgs;

			if(getCreateableEventArgsType(type))
			{
				if((ET_GAME_QUIT.Hash == type.Hash) ||
					(ET_GAME_NEW.Hash == type.Hash))
					eventArgs = IEventArgsSharedPtr(new EventArgs(type));
			}

			return eventArgs;
		}
		//-----------------------------------------------------------------------------------------------
		ICameraActorAddedEventArgs* DefaultEventArgsFactory::addCameraActorAddedEventArgs( const c8* actorName)
		{
			ICameraActorAddedEventArgs* eventArgs(0);
//				new CameraActorAddedEventArgs(ET_CAMERA_ACTOR_ADDED.Hash, new gaming::AI_ACTOR_ID(actorName));

			return eventArgs;
		}
		//-----------------------------------------------------------------------------------------
		u32 DefaultEventArgsFactory::getCreatableEventArgsTypeCount() const
        {
			return mSupportedEventArgsTypes.size();
        }
        //-----------------------------------------------------------------------------------------
		bool DefaultEventArgsFactory::getCreateableEventArgsType(const ET_EVENT_TYPE& type) const
        {
	        for (u32 i=0; i<mSupportedEventArgsTypes.size(); ++i)
				if (mSupportedEventArgsTypes[i] == type.Hash)
			        return true;

            return false;

        }
        //-----------------------------------------------------------------------------------------
    }
}
