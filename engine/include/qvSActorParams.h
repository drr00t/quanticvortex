
#ifndef __S_ACTOR_PARAMS_H_
#define __S_ACTOR_PARAMS_H_

#include "qvActorTypes.h"


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

		struct SActorArgs //: public IAttributeExchangingObject
        {

			SActorArgs(){}

			bool operator!=(const SActorArgs &other) const
			{
				return ((ID != other.ID) && (Type != other.Type));
			}

			bool operator==(const SActorArgs &other) const 
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

            AI_ACTOR_ID* ID;
            AT_ACTOR_TYPE* Type;			
		};
	}
}
#endif

