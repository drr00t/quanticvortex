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


#ifndef __I_CAMERA_ACTOR_H_
#define __I_CAMERA_ACTOR_H_

#include "qvIActor.h"


namespace qv
{
    namespace gaming
    {
		class ICameraActor: public IActor
        {
        public:
			virtual f32 getAspectRatio () const =0;
			virtual f32 getFarValue () const =0;
			virtual f32 getFOV () const =0;
			virtual f32 getNearValue () const =0;
			virtual const core::vector3df& getTarget() const =0;
			virtual const core::vector3df& getUpVector () const =0;

			virtual void setAspectRatio (f32 aspect)=0;
			virtual void setFarValue (f32 zf)=0;
			virtual void setFOV (f32 fovy)=0;
			virtual void setNearValue (f32 zn)=0;
			virtual void setTarget (const core::vector3df &pos)=0;
			virtual void setUpVector (const core::vector3df &pos)=0;
        };
    }
}
#endif

