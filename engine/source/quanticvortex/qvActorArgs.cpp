
#include "qvActorArgs.h"

namespace qv
{
    namespace core
    {
        //-----------------------------------------------------------------------------------------
		ActorArgs::ActorArgs()
			//:mActorID(0)
        {
        }
        //-----------------------------------------------------------------------------------------
        ActorArgs::~ActorArgs()
        {
        }
        //-----------------------------------------------------------------------------------------
		void ActorArgs::deserializeAttributes(irr::io::IAttributes *in, irr::io::SAttributeReadWriteOptions *options)
        {
			if (!in)
				return;

			//mID = in->getAttributeAsInt("Id");
			//mName = in->getAttributeAsString("Name");
			mActorID.createUniqueID(in->getAttributeAsString("Name"));
            mRelativeTranslation = in->getAttributeAsVector3d("Position");
            mRelativeRotation = in->getAttributeAsVector3d("Rotation");
            mRelativeScale = in->getAttributeAsVector3d("Scale");
			mIsVisible = in->getAttributeAsBool("Visible");
			mAutomaticCullingState = 
				(E_CULLING_TYPE) in->getAttributeAsEnumeration("AutomaticCulling", 
				AutomaticCullingNames);
			mDebugDataVisible = in->getAttributeAsInt("DebugDataVisible");
			mIsDebugObject = in->getAttributeAsBool("IsDebugObject");
        }
        //-----------------------------------------------------------------------------------------
		void ActorArgs::serializeAttributes(irr::io::IAttributes *out, irr::io::SAttributeReadWriteOptions *options) const
		{
			if (!out)
				return;

			out->addString	("Name", mActorID.getName());
			out->addInt	("Id", mActorID.getHashedName() );
            out->addVector3d("Position", mRelativeTranslation );
            out->addVector3d("Rotation", mRelativeRotation );
            out->addVector3d("Scale", mRelativeScale );
			out->addBool	("Visible", mIsVisible );
			out->addEnum	("AutomaticCulling", mAutomaticCullingState, AutomaticCullingNames);
			out->addInt	("DebugDataVisible", mDebugDataVisible );
			out->addBool	("IsDebugObject", mIsDebugObject );
		}
		//-----------------------------------------------------------------------------------------
		//Light actor
        //-----------------------------------------------------------------------------------------
		LightActorArgs::LightActorArgs()
			//:mActorID(0)
        {
        }
        //-----------------------------------------------------------------------------------------
        LightActorArgs::~LightActorArgs()
        {
        }
        //-----------------------------------------------------------------------------------------
		void LightActorArgs::deserializeAttributes(irr::io::IAttributes *in, irr::io::SAttributeReadWriteOptions *options)
        {
			ActorArgs::deserializeAttributes(in, options);
			
			mAmbientColor =		in->getAttributeAsColorf("AmbientColor");
			mDiffuseColor =		in->getAttributeAsColorf("DiffuseColor");
			mSpecularColor =	in->getAttributeAsColorf("SpecularColor");

		//	//TODO: clearify Radius and Linear Attenuation
		//#if 0
		//	setRadius ( in->getAttributeAsFloat("Radius") );
		//#else
			mRadius = in->getAttributeAsFloat("Radius");
		//#endif

			if (in->existsAttribute("Attenuation")) // might not exist in older files
				mAttenuation =	in->getAttributeAsVector3d("Attenuation");

			if (in->existsAttribute("OuterCone")) // might not exist in older files
				mOuterCone =	in->getAttributeAsFloat("OuterCone");
			else
				mOuterCone = 0.0f;

			if (in->existsAttribute("InnerCone")) // might not exist in older files
				mInnerCone =	in->getAttributeAsFloat("InnerCone");
			else
				mInnerCone = 0.0f;

			if (in->existsAttribute("Falloff")) // might not exist in older files
				mFalloff =	in->getAttributeAsFloat("Falloff");
			else
				mFalloff = 0.0f;

			mCastShadows =		in->getAttributeAsBool("CastShadows");
			mLightType =		(irr::video::E_LIGHT_TYPE)in->getAttributeAsEnumeration("LightType", irr::video::LightTypeNames);
        }
        //-----------------------------------------------------------------------------------------
		void LightActorArgs::serializeAttributes(irr::io::IAttributes *out, irr::io::SAttributeReadWriteOptions *options) const
		{
			ActorArgs::serializeAttributes(out, options);

			out->addColorf	("AmbientColor", mAmbientColor);
			out->addColorf	("DiffuseColor", mDiffuseColor);
			out->addColorf	("SpecularColor", mSpecularColor);
			out->addVector3d("Attenuation", mAttenuation);
			out->addFloat	("Radius", mRadius);
			out->addFloat	("OuterCone", mOuterCone);
			out->addFloat	("InnerCone", mInnerCone);
			out->addFloat	("Falloff", mFalloff);
			out->addBool	("CastShadows", mCastShadows);
			out->addEnum	("LightType", mLightType, irr::video::LightTypeNames);
		}
		//-----------------------------------------------------------------------------------------
		//Mesh actor
        //-----------------------------------------------------------------------------------------
		MeshActorArgs::MeshActorArgs()
			//:mActorID(0)
        {
        }
        //-----------------------------------------------------------------------------------------
        MeshActorArgs::~MeshActorArgs()
        {
        }
        //-----------------------------------------------------------------------------------------
		void MeshActorArgs::deserializeAttributes(irr::io::IAttributes *in, irr::io::SAttributeReadWriteOptions *options)
        {
			ActorArgs::deserializeAttributes(in,options);

			mMeshName = in->getAttributeAsString("Mesh");
		}
        //-----------------------------------------------------------------------------------------
		void MeshActorArgs::serializeAttributes(irr::io::IAttributes *out, irr::io::SAttributeReadWriteOptions *options) const
		{
			ActorArgs::serializeAttributes(out,options);

			out->addString("Mesh", mMeshName.c_str());
		}
		//-----------------------------------------------------------------------------------------
		//CameraActorArgs actor
        //-----------------------------------------------------------------------------------------
		CameraActorArgs::CameraActorArgs()
			//:mActorID(0)
        {
        }
        //-----------------------------------------------------------------------------------------
        CameraActorArgs::~CameraActorArgs()
        {
        }
        //-----------------------------------------------------------------------------------------
		void CameraActorArgs::deserializeAttributes(irr::io::IAttributes *in, irr::io::SAttributeReadWriteOptions *options)
        {
			ActorArgs::deserializeAttributes(in,options);

			mTarget = in->getAttributeAsVector3d("Target");
			mUpVector = in->getAttributeAsVector3d("UpVector");
			mFovy = in->getAttributeAsFloat("Fovy");
			mAspect = in->getAttributeAsFloat("Aspect");
			mZNear = in->getAttributeAsFloat("ZNear");
			mZFar = in->getAttributeAsFloat("ZFar");
			mTargetAndRotationAreBound = in->getAttributeAsBool("Binding");
        }
        //-----------------------------------------------------------------------------------------
		void CameraActorArgs::serializeAttributes(irr::io::IAttributes *out, irr::io::SAttributeReadWriteOptions *options) const
		{
			ActorArgs::serializeAttributes(out,options);

			//out->addVector3d("Target", Target);
			//out->addVector3d("UpVector", UpVector);
			//out->addFloat("Fovy", Fovy);
			//out->addFloat("Aspect", Aspect);
			//out->addFloat("ZNear", ZNear);
			//out->addFloat("ZFar", ZFar);
			//out->addBool("Binding", TargetAndRotationAreBound);
		} 
		//-----------------------------------------------------------------------------------------
		//SkyDome actor
        //-----------------------------------------------------------------------------------------
		SkyDomeActorArgs::SkyDomeActorArgs()
			//:mActorID(0)
        {
        }
        //-----------------------------------------------------------------------------------------
        SkyDomeActorArgs::~SkyDomeActorArgs()
        {
        }
        //-----------------------------------------------------------------------------------------
		void SkyDomeActorArgs::deserializeAttributes(irr::io::IAttributes *in, irr::io::SAttributeReadWriteOptions *options)
        {
			ActorArgs::deserializeAttributes(in, options);
			mHorizontalResolution = in->getAttributeAsInt  ("HorizontalResolution");
			mVerticalResolution   = in->getAttributeAsInt  ("VerticalResolution");
			mTexturePercentage    = in->getAttributeAsFloat("TexturePercentage");
			mSpherePercentage     = in->getAttributeAsFloat("SpherePercentage");
			mRadius               = in->getAttributeAsFloat("Radius");
        }
        //-----------------------------------------------------------------------------------------
		void SkyDomeActorArgs::serializeAttributes(irr::io::IAttributes *out, irr::io::SAttributeReadWriteOptions *options) const
		{
			ActorArgs::serializeAttributes(out, options);

			out->addInt  ("HorizontalResolution", mHorizontalResolution);
			out->addInt  ("VerticalResolution",   mVerticalResolution);
			out->addFloat("TexturePercentage",    mTexturePercentage);
			out->addFloat("SpherePercentage",     mSpherePercentage);
			out->addFloat("Radius",               mRadius);
		}
	}
}

