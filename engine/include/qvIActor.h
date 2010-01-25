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


#ifndef __I_ACTOR_H_
#define __I_ACTOR_H_

#include "qvActorTypes.h"


namespace qv
{
    namespace gaming
    {
		struct SActorArgs;

		class IActor: public IReferenceCounted
        {

        protected:
			const AI_ACTOR_ID* mActorID;
            const AT_ACTOR_TYPE* mActorType;
			bool mPhysics;
            matrix4 mTransformation;
            //SActorArgs mActorParams;

        public:

			//IActor( const SActorArgs& args)
			//	:mActorID(0), mActorType(0)
   //         {
   //         }

			IActor(const AI_ACTOR_ID* actorID, const AT_ACTOR_TYPE* actorType)
				:mActorID(actorID),mActorType(actorType)
            {
            }

            virtual ~IActor();

			virtual u32 getID() const 
            {
				return mActorID->HashedText;
            } 
			virtual const stringc& getName() const 
            {
				return mActorID->Text;
            } 

            virtual u32 getTypeID() const 
            {
				return mActorType->HashedText;
            }
			
			virtual const c8* getTypeName() const 
            {
				return mActorType->Text.c_str();
            } 

			virtual bool isPhysical()
            {
                return mPhysics;
            }

            virtual const matrix4& getTransformation()
            {
                return mTransformation;
            }

            virtual void setTransformation(const matrix4& transformation)
            {
                mTransformation = transformation;
            }
			
			//virtual const SActorArgs& getParams() = 0;
			//virtual void setParams(const SActorArgs& args)=0;

            virtual void update( u32 elapsedTimeMs)=0;
        };

        //typedef SharedPtr<IActor> ActorPtr;

		typedef map<u32, IActor*> ActorMap;
    }
}
#endif

