
#ifndef __GAMEPARAMETERS_H_
#define __GAMEPARAMETERS_H_

#include "qvPrerequisites.h" 

using namespace irr::io;


namespace qv
{    
	class GameParameters :  public virtual IAttributeExchangingObject
    {

    protected:
        stringc mGameTitle;
        stringc mGameAppDirectory;
        stringc mUserHomeDirectory;

    public:

	    GameParameters();
        virtual ~GameParameters();

		stringc& gameAppDirectory();
        stringc& userHomeDirectory();

    	virtual bool loadGame() = 0;
        virtual void createGameAndView() = 0;


		/// serialization interface implementation
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const;
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0);

    };
}

#endif

