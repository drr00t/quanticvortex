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

#include "Poco/SharedPtr.h"
#include "irrArray.h"
#include "irrMap.h"
#include "irrList.h"


namespace qv
{
    namespace gaming
    {
		class IActor
        {
        public:

			virtual u32 getHashId() const = 0;

            virtual u32 getHashType() const = 0;

//			virtual const btTransform& getTransformation() const =0;

			virtual bool isVisible () const = 0;

            virtual void setType( u32 actorHashType) = 0;

//            virtual void setTransformation( const btTransform& transformation) = 0;

            virtual void update( u32 elapsedTimeMs) const = 0;
        };

		typedef Poco::SharedPtr<IActor> IActorSharedPtr;
        typedef irr::core::map<u32, IActorSharedPtr> ActorsMap;
        typedef irr::core::list<IActorSharedPtr> ActorsSharedPtrList;
        typedef irr::core::array<IActorSharedPtr> ActorsSharedPtrArray;
    }
}
#endif

