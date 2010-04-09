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

#include "qvIActor.h"


namespace qv
{
    namespace gaming
    {
        class Actor: public IActor
        {

        public: 
			
            Actor();
            Actor(const c8* actorName, u32 actorHashType);

            virtual ~Actor();

            virtual u32 getHashId() const { return mId.Hash;}
			
            virtual u32 getHashType() const { return mActorHashType;}

//            virtual const matrix4& getTransformation() const { return mTransformation;}

            virtual bool isVisible () const { return mVisible;}
            
//            virtual void setName( const c8* name){ if(!mId) mId = new AI_ACTOR_ID(name);}
            
//            virtual void setTransformation( const matrix4& transformation) { mTransformation = transformation;}

//            virtual void setType( const AT_ACTOR_TYPE* type) { mType = type;}

            virtual void update( u32 elapsedTimeMs);

		protected:
            const AI_ACTOR_ID& mId;
            u32 mActorHashType;
//            matrix4 mTransformation;
            bool mVisible;
        };
    }
}
#endif

