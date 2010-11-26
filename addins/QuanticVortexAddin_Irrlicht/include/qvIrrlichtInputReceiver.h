/**************************************************************************************************
//
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
//
**************************************************************************************************/


#ifndef __INPUT_RECEIVER_IRRLICHT_H_
#define __INPUT_RECEIVER_IRRLICHT_H_

#include "qvAddinIrrlichtConfig.h"
//#include "IEventReceiver.h"

#include "qvInputReceiver.h"



namespace qv
{
namespace input
{


class _QUANTICVORTEX_API_ InputReceiverImpl : public irr::IEventReceiver
	//base implementation released by Seven on Irrlicht forums:
	//http://irrlicht.sourceforge.net/phpBB2/viewtopic.php?t=34052&highlight=irreventhandler
{


	public:

		InputReceiverImpl( qv::input::InputReceiver* inputReceiver);

		virtual ~InputReceiverImpl();

		// keyboard events
		virtual bool OnKeyInputEvent(const irr::SEvent& e);

		// guievents
		virtual bool OnButtonClicked(const irr::SEvent& e);

		virtual bool OnScrollBarChanged(const irr::SEvent& e);

		virtual bool OnCheckBoxChanged(const irr::SEvent& e);

		virtual bool OnListBoxChanged(const irr::SEvent& e);

		virtual bool OnListBoxSelectedAgain(const irr::SEvent& e);

		virtual bool OnFileSelected(const irr::SEvent& e);

		virtual bool OnMessageBoxYes(const irr::SEvent& e);

		virtual bool OnMessageBoxNo(const irr::SEvent& e);

		virtual bool OnMessageBoxOk(const irr::SEvent& e);

		virtual bool OnMessageBoxCancel(const irr::SEvent& e);

		virtual bool OnEditBoxEnter(const irr::SEvent& e);

		virtual bool OnTabChanged(const irr::SEvent& e);

		virtual bool OnComboBoxChanged(const irr::SEvent& e);

		virtual bool OnSpinBoxChanged(const irr::SEvent& e);

		// mouse events
		virtual bool OnLMousePressedDown(const irr::SEvent& e);

		virtual bool OnRMousePressedDown(const irr::SEvent& e);

		virtual bool OnMMousePressedDown(const irr::SEvent& e);

		virtual bool OnLMouseLeftUp(const irr::SEvent& e);

		virtual bool OnRMouseLeftUp(const irr::SEvent& e);

		virtual bool OnMMouseLeftUp(const irr::SEvent& e);

		virtual bool OnMouseMoved(const irr::SEvent& e);

		virtual bool OnMouseWheel(const irr::SEvent& e);

		// user events
		virtual bool OnUserEvent(const irr::SEvent& e);

		virtual bool OnEvent(const irr::SEvent& e);
};

}

}

#endif

#endif

#endif
