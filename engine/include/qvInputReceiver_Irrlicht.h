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

#if QUANTICVORTEX_RENDER == QUANTICVORTEX_RENDER_IRRLICHT

#if QUANTICVORTEX_INPUT == QUANTICVORTEX_INPUT_IRRLICHT

/*
#include "qvSingleKeyInputTranslator.h"
#include "qvAnyKeyInputTranslator.h"

#include "qvIInputTranslator.h"
#include "qvIInputTranslatorFactory.h"
*/

#include "qvInputReceiver.h"

// irrlicht input receiver driver
#include "IEventReceiver.h"


namespace qv
{
namespace input
{


class _QUANTICVORTEX_API_ InputReceiverImpl : public qv::input::InputReceiver
	//base implementation released by Seven on Irrlicht forums:
	//http://irrlicht.sourceforge.net/phpBB2/viewtopic.php?t=34052&highlight=irreventhandler
{


	public:

		InputReceiverImpl()
		{

			for (s32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i) mKeyState[i] = EKS_RELEASED;

			mMouse.X = 0;
			mMouse.Y = 0;
			mMouse.Wheel = 0.0f;
			mMouse.WheelDelta = 0.0f;
			mMouse.LButtonDown = false;
			mMouse.RButtonDown = false;
			mMouse.MButtonDown = false;
		};

		virtual ~InputReceiverImpl(void)
		{
			InputReceiver::InputReceiver();
		}


		//context
		virtual bool keyPressed(irr::EKEY_CODE keycode)
		{
			return (mKeyState[keycode] == EKS_PRESSED);
		};
		
		virtual bool keyDown(irr::EKEY_CODE keycode)
		{
			return (mKeyState[keycode] == EKS_DOWN || mKeyState[keycode] == EKS_PRESSED);
		};
		
		virtual bool keyUp(irr::EKEY_CODE keycode)
		{
			return (mKeyState[keycode] == EKS_UP || mKeyState[keycode] == EKS_RELEASED);
		};
		
		virtual bool keyReleased(irr::EKEY_CODE keycode)
		{
			return (mKeyState[keycode] == EKS_RELEASED);
		};

		// keyboard events
		virtual bool OnKeyInputEvent(const irr::SEvent& e)
		{
			//update input state of keyboard
			//mContextInput.update(e);

			//command for keyboard event registred by InputTranslators can executed here
			for(u32 i = 0; i < mInputTranslators.size(); ++i)
				return mInputTranslators[i]->translate(this);

			return false;
		}

		// guievents
		virtual bool OnButtonClicked(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnScrollBarChanged(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnCheckBoxChanged(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnListBoxChanged(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnListBoxSelectedAgain(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnFileSelected(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMessageBoxYes(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMessageBoxNo(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMessageBoxOk(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMessageBoxCancel(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnEditBoxEnter(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnTabChanged(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnComboBoxChanged(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnSpinBoxChanged(const irr::SEvent& e)
		{
			return false;
		}

		// mouse events
		virtual bool OnLMousePressedDown(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnRMousePressedDown(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMMousePressedDown(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnLMouseLeftUp(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnRMouseLeftUp(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMMouseLeftUp(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMouseMoved(const irr::SEvent& e)
		{
			return false;
		}
		
		virtual bool OnMouseWheel(const irr::SEvent& e)
		{
			return false;
		}

		// user events
		virtual bool OnUserEvent(const irr::SEvent& e)
		{
			return false;
		}

		virtual bool OnEvent(const irr::SEvent& e)
		{
			switch (e.EventType)
			{
			case irr::EET_KEY_INPUT_EVENT :
			{
				if (e.KeyInput.PressedDown == true)
				{
					if (e.KeyInput.PressedDown)
					{
						if (mKeyState[e.KeyInput.Key] != EKS_DOWN)
							mKeyState[e.KeyInput.Key] = EKS_PRESSED;
						else 
							mKeyState[e.KeyInput.Key] = EKS_DOWN;
					}
					else if (mKeyState[e.KeyInput.Key] != EKS_UP)
					{
						mKeyState[e.KeyInput.Key] = EKS_RELEASED;
					}
				}
				
				//if (e.KeyInput.PressedDown == true) return OnKeyInputEvent(e);
				if (e.KeyInput.PressedDown) 
					return OnKeyInputEvent(e);
			}
			
			break;

			case irr::EET_GUI_EVENT :
			{
				switch (e.GUIEvent.EventType)
				{
				case irr::gui::EGET_BUTTON_CLICKED         :
					return OnButtonClicked(e);
					
				case irr::gui::EGET_SCROLL_BAR_CHANGED      :
					return OnScrollBarChanged(e);
					
				case irr::gui::EGET_CHECKBOX_CHANGED         :
					return OnCheckBoxChanged(e);
					
				case irr::gui::EGET_LISTBOX_CHANGED         :
					return OnListBoxChanged(e);
					
				case irr::gui::EGET_LISTBOX_SELECTED_AGAIN   :
					return OnListBoxSelectedAgain(e);
					
				case irr::gui::EGET_FILE_SELECTED            :
					return OnFileSelected(e);
					
				case irr::gui::EGET_MESSAGEBOX_YES         :
					return OnMessageBoxYes(e);
					
				case irr::gui::EGET_MESSAGEBOX_NO            :
					return OnMessageBoxNo(e);
					
				case irr::gui::EGET_MESSAGEBOX_OK            :
					return OnMessageBoxOk(e);
					
				case irr::gui::EGET_MESSAGEBOX_CANCEL         :
					return OnMessageBoxCancel(e);
					
				case irr::gui::EGET_EDITBOX_ENTER            :
					return OnEditBoxEnter(e);
					
				case irr::gui::EGET_TAB_CHANGED            :
					return OnTabChanged(e);
					
				case irr::gui::EGET_COMBO_BOX_CHANGED         :
					return OnComboBoxChanged(e);
					
				case irr::gui::EGET_SPINBOX_CHANGED         :
					return OnSpinBoxChanged(e);
					
				default :
					return false;
				}
			}
			break;

			case irr::EET_MOUSE_INPUT_EVENT :
			{
				mMouse.X = e.MouseInput.X;
				mMouse.Y = e.MouseInput.Y;

				switch (e.MouseInput.Event)
				{
				case irr::EMIE_LMOUSE_PRESSED_DOWN   :
					mMouse.LButtonDown = true;
					return OnLMousePressedDown(e);
				case irr::EMIE_RMOUSE_PRESSED_DOWN   :
					mMouse.RButtonDown = true;
					return OnRMousePressedDown(e);
				case irr::EMIE_MMOUSE_PRESSED_DOWN   :
					mMouse.MButtonDown = true;
					return OnMMousePressedDown(e);
				case irr::EMIE_LMOUSE_LEFT_UP      :
					mMouse.LButtonDown = false;
					return OnLMouseLeftUp(e);
				case irr::EMIE_RMOUSE_LEFT_UP      :
					mMouse.RButtonDown = false;
					return OnRMouseLeftUp(e);
				case irr::EMIE_MMOUSE_LEFT_UP      :
					mMouse.MButtonDown = false;
					return OnMMouseLeftUp(e);
				case irr::EMIE_MOUSE_MOVED         :
					return OnMouseMoved(e);
				case irr::EMIE_MOUSE_WHEEL         :
				{
					mMouse.WheelDelta = mMouse.Wheel - e.MouseInput.Wheel;
					mMouse.Wheel += e.MouseInput.Wheel;
					return OnMouseWheel(e);
				}
				default :
					return false;
				}
			}
			break;

			case irr::EET_USER_EVENT :
			{
				return OnUserEvent(e);
				default :
					return false;
				}
				break;
			}

			//translate input event here
			
			return false;
		}

	private:
		// Mouse data.
		struct SMouseData
		{
			s32 X;
			s32 Y;
			bool LButtonDown;
			bool RButtonDown;
			bool MButtonDown;
			real Wheel;
			real WheelDelta;
		};

		struct SMouseData mMouse;

		s32 mouseX()
		{
			return mMouse.X;
		}
		s32 mouseY()
		{
			return mMouse.Y;
		}
		real mouseWheel()
		{
			return mMouse.Wheel;
		}
		real mouseWheelDelta()
		{
			return mMouse.WheelDelta;
		}

		EKEY_STATE mKeyState[irr::KEY_KEY_CODES_COUNT];

};

}

}

#endif

#endif

#endif
