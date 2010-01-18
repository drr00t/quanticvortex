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

#ifndef __IPHYSICSMANAGER_H_
#define __IPHYSICSMANAGER_H_

#include "qvPrerequisites.h"


namespace qv
{
    namespace physics    
	{
        class IPhysicsManager: public irr::IReferenceCounted
        {
        public:
			IPhysicsManager();
			~IPhysicsManager();

			virtual void update( u32 elapsedTimeMs)=0;

            bool initialize();

			//// Initialization of Physics Objects
			//virtual void VAddSphere(float radius, IActor *actor, float specificGravity, enum PhysicsMaterial mat)=0;
			//virtual void VAddBox(const Vec3& dimensions, IActor *gameActor, float specificGravity, enum PhysicsMaterial mat) = 0;
			//virtual void VAddPointCloud(Vec3 *verts, int numPoints, IActor *gameActor, float specificGravity, enum PhysicsMaterial mat)=0;
			//virtual void VRemoveActor(ActorId id)=0;

			//// Debugging
			//virtual void VRenderDiagnostics() = 0;

			//// Physics world modifiers
			//virtual void VCreateTrigger(const Vec3 &pos, const float dim, int triggerID)=0;
			//virtual void VApplyForce(const Vec3 &dir, float newtons, ActorId aid)=0;
			//virtual void VApplyTorque(const Vec3 &dir, float newtons, ActorId aid)=0;
			//virtual bool VKinematicMove(const Mat4x4 &mat, ActorId aid)=0;
			//
			//// Physics actor states
			//virtual void VRotateY(ActorId actorId, float angleRadians, float time) = 0;
			//virtual float VGetOrientationY(ActorId actorId) = 0;
			//virtual void VStopActor(ActorId actorId) = 0;
			//virtual void VSetVelocity(ActorId actorId, const Vec3& vel) = 0;
			//virtual void VTranslate(ActorId actorId, const Vec3& vec) = 0;
        };

        //typedef SharedPtr<IActor> ActorPtr;
    }
}
#endif

