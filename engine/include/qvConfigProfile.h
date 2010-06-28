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

#ifndef _QUANTICVORTEX_CONFIG_PROFILE_H_
#define _QUANTICVORTEX_CONFIG_PROFILE_H_

//Physics engines avaible to use, just only one physics can be enable at time.
#define QV_PHYSICS_BULLET 1 // Physics library

#define QV_PHYSICS_NEWTON 2 //not implemented yet
#define QV_PHYSICS_PHYSX  3 //not implemented yet
#define QV_PHYSICS_HAVOK  4 //not implemented yet

//Redering engines avaible to use, just only one render system can be enable at time.
#define QV_RENDER_IRRLICHT 1

#define QV_RENDER_OGRE3D 2 //not implemented yet

//Input engine to get event from mouse, keyboard, gamepad,etc
#define QV_INPUT_IRRLICHT 1 // Irrlicht builtin input receiver
#define QV_INPUT_OIS      2 //not implemented yet


//current profile selected
#define QV_RENDER       QV_RENDER_IRRLICHT
#define QV_PHYSICS      QV_PHYSICS_BULLET
#define QV_INPUT        QV_INPUT_IRRLICHT



#endif
