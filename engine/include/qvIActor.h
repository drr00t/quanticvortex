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
		class IActor: public IReferenceCounted
        {
        public:

			virtual u32 getId() const = 0;
			
            virtual u32 getTypeId() const = 0;

			virtual const matrix4& getTransformation() const =0;

			virtual bool isVisible () const = 0;

            virtual void setName( const c8* name) = 0;

            virtual void setType( const AT_ACTOR_TYPE* type) = 0;

            virtual void setTransformation( const matrix4& transformation) = 0;
            
            virtual void update( u32 elapsedTimeMs) = 0;
        };

		typedef map<u32, IActor*> ActorsMap;

    }
}
#endif

