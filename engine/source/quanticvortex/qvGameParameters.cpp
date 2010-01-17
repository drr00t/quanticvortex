
#include "qvGameParameters.h"


namespace qv
{


    GameParameters::GameParameters()
    {
    }
    //----------------------------------------------------------------------------- 	
    GameParameters::~GameParameters()
    {
    }
    //----------------------------------------------------------------------------- 	
	void GameParameters::serializeAttributes(irr::io::IAttributes *out, irr::io::SAttributeReadWriteOptions *options) const
	{
	//	//out->addInt("Id", ID );
	//	//out->addString("Caption", getText());
	//	//out->addRect("Rect", DesiredRect);
	//	//out->addPosition2d("MinSize", core::position2di(MinSize.Width, MinSize.Height));
	//	//out->addPosition2d("MaxSize", core::position2di(MaxSize.Width, MaxSize.Height));
	//	//out->addBool("NoClip", NoClip);
	//	//out->addEnum("LeftAlign", AlignLeft, GUIAlignmentNames);
	//	//out->addEnum("RightAlign", AlignRight, GUIAlignmentNames);
	//	//out->addEnum("TopAlign", AlignTop, GUIAlignmentNames);
	//	//out->addEnum("BottomAlign", AlignBottom, GUIAlignmentNames);
	//	//out->addBool("Visible", IsVisible);
	//	//out->addBool("Enabled", IsEnabled);
	//	//out->addBool("TabStop", IsTabStop);
	//	//out->addBool("TabGroup", IsTabGroup);
	//	//out->addInt("TabOrder", TabOrder);
	}
	//---------------------------------------------------------------------------------------------
    void GameParameters::deserializeAttributes(irr::io::IAttributes *in, irr::io::SAttributeReadWriteOptions *options)
	{
	//	//setID(in->getAttributeAsInt("Id"));
	//	//setText(in->getAttributeAsStringW("Caption").c_str());
	//	//setVisible(in->getAttributeAsBool("Visible"));
	//	//setEnabled(in->getAttributeAsBool("Enabled"));
	//	//IsTabStop = in->getAttributeAsBool("TabStop");
	//	//IsTabGroup = in->getAttributeAsBool("TabGroup");
	//	//TabOrder = in->getAttributeAsInt("TabOrder");

	//	//core::position2di p = in->getAttributeAsPosition2d("MaxSize");
	//	//setMaxSize(core::dimension2di(p.X,p.Y));

	//	//p = in->getAttributeAsPosition2d("MinSize");
	//	//setMinSize(core::dimension2di(p.X,p.Y));

	//	//setNotClipped(in->getAttributeAsBool("NoClip"));
	//	//setAlignment((EGUI_ALIGNMENT) in->getAttributeAsEnumeration("LeftAlign", GUIAlignmentNames),
	//	//	(EGUI_ALIGNMENT)in->getAttributeAsEnumeration("RightAlign", GUIAlignmentNames),
	//	//	(EGUI_ALIGNMENT)in->getAttributeAsEnumeration("TopAlign", GUIAlignmentNames),
	//	//	(EGUI_ALIGNMENT)in->getAttributeAsEnumeration("BottomAlign", GUIAlignmentNames));

	//	//setRelativePosition(in->getAttributeAsRect("Rect"));
	}
}
