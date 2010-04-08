
#ifndef __GAMEPARAMETERS_H_
#define __GAMEPARAMETERS_H_

#include "qvPrerequisites.h" 

#include "irrString.h" 
#include "IAttributeExchangingObject.h"

namespace qv
{    
	class GameParameters :  public virtual irr::io::IAttributeExchangingObject
    {

    protected:
        irr::core::stringc mGameTitle;
        irr::core::stringc mGameAppDirectory;
        irr::core::stringc mUserHomeDirectory;

    public:

	    GameParameters();
        virtual ~GameParameters();

		irr::core::stringc& gameAppDirectory();
        irr::core::stringc& userHomeDirectory();

    	virtual bool loadGame() = 0;
        virtual void createGameAndView() = 0;


		/// serialization interface implementation
		virtual void serializeAttributes(irr::io::IAttributes* out, irr::io::SAttributeReadWriteOptions* options=0) const;
		virtual void deserializeAttributes(irr::io::IAttributes* in, irr::io::SAttributeReadWriteOptions* options=0);

    };
}

#endif

