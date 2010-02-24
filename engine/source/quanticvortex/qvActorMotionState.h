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


#ifndef __ACTOR_MOTION_STATE_H_
#define __ACTOR_MOTION_STATE_H_

#include "qvPrerequisites.h"
#include "qvActorTypes.h"

#include "LinearMath/btQuaternion.h"
#include "LinearMath/btDefaultMotionState.h"


namespace
{
	void quaternionToEuler(const btQuaternion &TQuat, btVector3 &TEuler) 
	{
		btScalar W = TQuat.getW();
		btScalar X = TQuat.getX();
		btScalar Y = TQuat.getY();
		btScalar Z = TQuat.getZ();

		f32 WSquared = W * W;
		f32 XSquared = X * X;
		f32 YSquared = Y * Y;
		f32 ZSquared = Z * Z;

		TEuler.setX(atan2f(2.0f * (Y * Z + X * W), -XSquared - YSquared + ZSquared + WSquared));
		TEuler.setY(asinf(-2.0f * (X * Z - Y * W)));
		TEuler.setZ(atan2f(2.0f * (X * Y + Z * W), XSquared - YSquared - ZSquared + WSquared));
		
		TEuler *= core::RADTODEG;
	}
}


namespace qv
{
    namespace physics
    {
        struct ActorMotionState: public btDefaultMotionState
        {
        private:
	        scene::ISceneNode* mSceneNode;
            const gaming::AI_ACTOR_ID* mActorId;

        public: 
			
            ActorMotionState(const gaming::AI_ACTOR_ID* actorId, scene::ISceneNode* sceneNode)
                :mSceneNode(sceneNode), mActorId(actorId)
            {
            }

            ///synchronizes world transform from user to physics
	        virtual void getWorldTransform(btTransform& centerOfMassWorldTrans ) const 
	        {
		        centerOfMassWorldTrans = m_graphicsWorldTrans;
	        }

	        ///synchronizes world transform from physics to user
	        ///Bullet only calls the update of worldtransform for active objects
	        virtual void setWorldTransform(const btTransform& centerOfMassWorldTrans)
	        {
		        //numUpdatedBodies++;  //profilling
		        m_startWorldTrans = centerOfMassWorldTrans;
		        m_graphicsWorldTrans = centerOfMassWorldTrans;

		        const btVector3& Point = centerOfMassWorldTrans.getOrigin();
                mSceneNode->setPosition(core::vector3df(Point[0], Point[1], Point[2])); //is possible scale mesh here

		        // Set rotation
		        btVector3 EulerRotation;
		        quaternionToEuler(centerOfMassWorldTrans.getRotation(), EulerRotation);
		        mSceneNode->setRotation(core::vector3df(EulerRotation[0], EulerRotation[1], EulerRotation[2]));
	        }

            // return actor ID
            u32 getActorId() const
            {
                return mActorId->HashedText;
            }
        };
    }
}
#endif

