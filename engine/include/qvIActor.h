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


#ifndef __IACTOR_H_
#define __IACTOR_H_

#include "qvPrerequisites.h"
#include "qvSUniqueID.h"


namespace qv
{
    namespace gaming
    {
		struct SActorParams;

        typedef UniqueID AI_ACTOR_ID;
		typedef UniqueID AT_ACTOR_TYPE;

        static const AI_ACTOR_ID AI_ACTOR_EMPTY("AI_ACTOR_EMPTY");


		class IActor: public IReferenceCounted
        {

        protected:
			AI_ACTOR_ID mActorID;
            AT_ACTOR_TYPE mActorType;
			bool mPhysics;
            matrix4 mTransformation;
            SActorParams* mActorParams;

        public:

			IActor( const SActorParams& params)
            {
            }

            IActor(const AI_ACTOR_ID& actorID, const AT_ACTOR_TYPE& actorType)
            {
            
            }

            virtual ~IActor();

            virtual const AI_ACTOR_ID& getActorID() const 
            {
                return mActorID;
            } 

            virtual void setActorID(const AI_ACTOR_ID& actorID)
            {
                mActorID = actorID;
            } 

            virtual const AT_ACTOR_TYPE& getType() const 
            {
                return mActorType;
            }

			virtual void setType(const AT_ACTOR_TYPE& actorType)
            {
                mActorType = actorType;
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
			
			virtual SActorParams* getParams() = 0;
			virtual void setParams(SActorParams* params)=0;

            virtual void update( u32 elapsedTimeMs)=0;
        };

        //typedef SharedPtr<IActor> ActorPtr;

		typedef map<u32, IActor*> ActorMap;
    }
}
#endif

