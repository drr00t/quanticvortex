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

#include "qvInputReceiver.h"

#include "qvIEngineManager.h"


namespace qv
{
	namespace input
	{
		//-----------------------------------------------------------------------
		InputReceiver::InputReceiver(IEngineManager* engineManager)
            :mCurrentGeneration(0),mEngineManager(engineManager)
		{
            for(u8 i = 0; i < C_KEY_GENERATIONS_COUNT; ++i)
                memset(mKeyPressed[i], 0, irr::KEY_KEY_CODES_COUNT);
		}
		//-----------------------------------------------------------------------
		InputReceiver::~InputReceiver()
		{
		}
		//-----------------------------------------------------------------------
        bool InputReceiver::OnEvent(const SEvent& event)
		{
            stringc log;

            switch(event.EventType)
            {
            case EET_GUI_EVENT:

                break;
            case EET_KEY_INPUT_EVENT:
                
                mKeyPressed[mCurrentGeneration][event.KeyInput.Key] = event.KeyInput.PressedDown; 
                
                log = L"Key: " + event.KeyInput.Key;
                log += L"   State: " + event.KeyInput.PressedDown;

                mEngineManager->getDevice()->getLogger()->log(log.c_str());

                //generation increment
                ++mCurrentGeneration;
                if(mCurrentGeneration == C_KEY_GENERATIONS_COUNT)
                    mCurrentGeneration = 0;

                break;
            case EET_JOYSTICK_INPUT_EVENT:

                break;
            case EET_MOUSE_INPUT_EVENT:

                log = L"Mouse position X x" + event.MouseInput.X;
                log = L" Y: " + event.MouseInput.Y;
                mEngineManager->getDevice()->getLogger()->log(log.c_str());

                log = L"";

                break;
            default:
                break;
            }
			return true;
		}
		//-----------------------------------------------------------------------
        void InputReceiver::registerInputTranslator(IInputTranslator* translator)
		{

		}
		//-----------------------------------------------------------------------
        void InputReceiver::unregisterInputTranslator(IInputTranslator* translator)
		{
		}
		//-----------------------------------------------------------------------
        void InputReceiver::unregisterInputTranslator(const IT_INPUT_TRANSLATOR_ID& translatorID)
		{
		}
		//-----------------------------------------------------------------------
	}
}
