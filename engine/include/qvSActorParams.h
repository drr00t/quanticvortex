
#ifndef __SACTORARGS_H_
#define __SACTORARGS_H_

#include "qvPrerequisites.h"

#include "qvIActor.h"

using namespace irr::io;
using namespace irr::scene;


namespace qv
{
    namespace gaming
    {
      //<attributes>
      //   <string name="Name" value="PEDRA_Z01_83" />
      //   <int name="Id" value="-1"/>
      //   <vector3d name="Position" value="-7.016368, 1.493516, -10.309895" />
      //   <vector3d name="Rotation" value="0.000000, -0.000000, 0.000000" />
      //   <vector3d name="Scale" value="1.000000, 1.000000, 1.000000" />
      //   <bool name="Visible" value="true"/>
      //   <enum name="AutomaticCulling" value="1"/>
      //   <bool name="DebugDataVisible" value="false"/>
      //   <bool name="IsDebugObject" value="false"/>
      //   <bool name="ReadOnlyMaterials" value="false"/>
      //   <string name="Mesh" value="meshes/PEDRA_12.irrmesh" />
      //</attributes>
      //<userData>
      //   <attributes>
      //   </attributes>
      //</userData>

		struct SActorParams //: public IAttributeExchangingObject
        {

			SActorParams(){}

            AI_ACTOR_ID ID;
            AT_ACTOR_TYPE Type;

			bool operator!=(const SActorParams &other) const
			{
				return ((ID != other.ID) && (Type != other.Type));
			}

			bool operator==(const SActorParams &other) const 
			{
				return ((ID == other.ID) && (Type == other.Type));
			}
			
			//SActorParams* create();
			//
			//virtual void serializeAttributes(IAttributes* out, SAttributeReadWriteOptions* options=0) const
			//{
			//}

			//virtual void deserializeAttributes(IAttributes* in, SAttributeReadWriteOptions* options=0)
			//{
			//}
			
			//s32 mParentActorID;

			////! Name of the scene node.
			//stringc mName;

			//stringc mNodeType;

			////io::path mMeshName;

			////! Absolute transformation of the node.
			//matrix4 mAbsoluteTransformation;

			////! Relative translation of the scene node.
			//vector3df mRelativeTranslation;

			////! Relative rotation of the scene node.
			//vector3df mRelativeRotation;

			////! Relative scale of the scene node.
			//vector3df mRelativeScale;

			////! ID of the node.
			//s32 mID;

			////! Automatic culling state
			//E_CULLING_TYPE mAutomaticCullingState;

			////! Flag if debug data should be drawn, such as Bounding Boxes.
			//s32 mDebugDataVisible;

			////! Is the node visible?
			//bool mIsVisible;

			////! Is debug object?
			//bool mIsDebugObject;

        //public: 
            //ActorArgs();
            //virtual ~ActorArgs();



			//virtual ActorPtr createActor(GameLogicPtr gameLogic){return 0;}
			//virtual SceneNodePtr addSceneNode(SceneViewPtr sceneView){return 0;}


			//bool getVisible(){return mIsVisible;}
			//void setVisible(bool isVisible){mIsVisible = isVisible;}

			//E_CULLING_TYPE getAutomaticCulling(){return mAutomaticCullingState;}
			//void setAutomaticCulling(E_CULLING_TYPE automaticCullingState){ mAutomaticCullingState = automaticCullingState;}

			//const c8* getName() const { return mActorID.getName(); }
			////void setName(const c8* name){mName = name;}
			////void setName(const stringc& name){mName = name;}

			//void setNodeType(const stringc& nodeType){ mNodeType = nodeType;}
			//const stringc& getNodeType() const { return mNodeType; }

			//s32 getID() const{return mActorID.getHashedName();}
			//
			//const ActorID& getActorID() const{return mActorID;}

			//s32 getParentActorID() const{return mParentActorID;}
			//void setParentActorID(s32 parentActorID){mParentActorID = parentActorID;}

			//const vector3df& getScale() const{return mRelativeScale;}
			//void setScale(const vector3df& scale){mRelativeScale = scale;}

			//const vector3df& getPosition(){return mRelativeTranslation;}
			//void setPosition(const vector3df& position){mRelativeTranslation = position;}

			//const vector3df& getRotation() const{return mRelativeRotation;}
			//void setRotation(const vector3df& rotation){mRelativeRotation = rotation;}
		};

/*
		class LightActorArgs: public ActorArgs
		{
		private:
			irr::video::SColorf mAmbientColor;
			irr::video::SColorf mDiffuseColor;
			irr::video::SColorf mSpecularColor;
			vector3df mAttenuation;
			f32 mRadius;
			f32 mOuterCone;
			f32 mInnerCone;
			f32 mFalloff;
			bool mCastShadows;
			irr::video::E_LIGHT_TYPE mLightType;

		public:
			LightActorArgs();
			virtual ~LightActorArgs();

			irr::video::SColorf getAmbientColor() {return mAmbientColor;}
			void setAmbientColor( irr::video::SColorf ambientColor) { mAmbientColor = ambientColor;}
			
			irr::video::SColorf getDiffuseColor() {return mDiffuseColor;}
			void setDiffuseColor( irr::video::SColorf diffuseColor) { mDiffuseColor = diffuseColor;}
			
			irr::video::SColorf getSpecularColor() {return mSpecularColor;}
			void setSpecularColor( irr::video::SColorf specularColor) { mSpecularColor = specularColor;}

			vector3df& getAttenuation() {return mAttenuation;}
			void setAttenuation( vector3df attenuation) { mAttenuation = attenuation;}

			f32 getRadius() {return mRadius;};
			void setRadius( f32 radius) { mRadius = radius;}
			
			f32 getOuterCone() {return mOuterCone;};
			void setOuterCone( f32 outerCone) { mOuterCone = outerCone;}
			
			f32 getInnerCone() {return mInnerCone;};
			void setInnerCone( f32 innerCone) { mInnerCone = innerCone;}
			
			f32 getFalloff() {return mFalloff;};
			void setFalloff( f32 falloff) { mFalloff = falloff;}

			bool getCastShadows() {return mCastShadows;};
			void setCastShadows( bool castShadows) { mCastShadows = castShadows;}

			irr::video::E_LIGHT_TYPE getLightType() {return mLightType;};
			void setLightType(irr::video::E_LIGHT_TYPE lightType) { mLightType = lightType;}

			virtual void serializeAttributes(IAttributes* out, SAttributeReadWriteOptions* options=0) const;
			virtual void deserializeAttributes(IAttributes* in, SAttributeReadWriteOptions* options=0);
		};


		class MeshActorArgs: public ActorArgs
		{
		protected:
			io::path mMeshName;

		public:
			MeshActorArgs();
			virtual ~MeshActorArgs();

			const io::path& getMeshName() const { return mMeshName; }
			void setMeshName(const io::path& meshName){mMeshName = meshName;}

			virtual void serializeAttributes(IAttributes* out, SAttributeReadWriteOptions* options=0) const;
			virtual void deserializeAttributes(IAttributes* in, SAttributeReadWriteOptions* options=0);
		};


		class CameraActorArgs: public ActorArgs
		{
		protected:
			vector3df mTarget;
			vector3df mUpVector;
			f32 mFovy;
			f32 mAspect;
			f32 mZNear;
			f32 mZFar;
			bool mTargetAndRotationAreBound;

		public:
			CameraActorArgs();
			virtual ~CameraActorArgs();

			vector3df getTarget(){return mTarget;}
			void setTarget(vector3df target){mTarget = target;}
			
			vector3df getUpVector(){return mUpVector;}
			void setUpVector(vector3df upVector){mUpVector = upVector;}
			
			f32 getFovy(){return mFovy;};
			void setFovy(f32 fovy){mFovy = fovy;}

			f32 getAspect(){return mAspect;}
			void setAspect(f32 aspect){mAspect = aspect;}

			f32 getZNear(){return mZNear;}
			void setZNear(f32 zNear){mZNear = zNear;}

			f32 getZFar(){return mZFar;}
			void setZFar(f32 zFar){mZFar = zFar;}

			bool getTargetAndRotationAreBound(){return mTargetAndRotationAreBound;}
			void setTargetAndRotationAreBound(bool targetAndRotationAreBound){mTargetAndRotationAreBound = targetAndRotationAreBound;}

			virtual void serializeAttributes(IAttributes* out, SAttributeReadWriteOptions* options=0) const;
			virtual void deserializeAttributes(IAttributes* in, SAttributeReadWriteOptions* options=0);
		};
		
		class SkyDomeActorArgs: public ActorArgs
		{
		private:
			u32 mHorizontalResolution;
			u32 mVerticalResolution;
			f32 mRadius;
			f32 mSpherePercentage;
			f32 mTexturePercentage;

		public:
			SkyDomeActorArgs();
			virtual ~SkyDomeActorArgs();

			u32 getHorizontalResolution() {return mHorizontalResolution;}
			void setHorizontalResolution( u32 horizontalResolution) { mHorizontalResolution = horizontalResolution;}
			
			u32 getVerticalResolution() {return mVerticalResolution;}
			void setVerticalResolution( u32 verticalResolution) { mVerticalResolution = verticalResolution;}

			f32 getRadius() {return mRadius;};
			void setRadius( f32 radius) { mRadius = radius;}
			
			f32 getSpherePercentage() {return mSpherePercentage;};
			void setSpherePercentage( f32 spherePercentage) { mSpherePercentage = spherePercentage;}
			
			f32 getTexturePercentage() {return mTexturePercentage;};
			void setTexturePercentage( f32 texturePercentage) { mTexturePercentage = texturePercentage;}
			
			virtual void serializeAttributes(IAttributes* out, SAttributeReadWriteOptions* options=0) const;
			virtual void deserializeAttributes(IAttributes* in, SAttributeReadWriteOptions* options=0);
		};

		*/

	}
}
#endif

