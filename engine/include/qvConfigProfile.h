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

//avaible operation systems plataforms
#define PLATAFORM_WINDOWS	1
#define PLATAFORM_LINUX		2 //not implemented yet
#define PLATAFORM_MACOS		3 //not implemented yet
#define PLATAFORM_PS3		4 //not implemented yet
#define PLATAFORM_XBOX		5 //not implemented yet

//Physics engines avaible to use, just only one physics can be enable at time.
#define PHYSICS_BULLET 1
#define PHYSICS_NEWTON 2 //not implemented yet
#define PHYSICS_PHYSX  3 //not implemented yet
#define PHYSICS_HAVOK  4 //not implemented yet

//Redering engines avaible to use, just only one render system can be enable at time.
#define RENDER_IRRLICHT 1
#define RENDER_OGRE3D 2 //not implemented yet



#endif