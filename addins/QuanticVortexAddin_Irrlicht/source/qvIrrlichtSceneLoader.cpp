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


#include "qvIrrlichtSceneLoader.h"

//#include "EHardwareBufferFlags.h"
//#include "IMeshSceneNode.h"
//#include "IMesh.h"


namespace qv
{
namespace views
{
//---------------------------------------------------------------------
void IrrSceceLoader::OnCreateNode(irr::scene::ISceneNode* node) {}

//-------------------------------------------------------------------------
//                        O n R e a d U s e r D a t a
//-------------------------------------------------------------------------
void IrrSceceLoader::OnReadUserData(irr::scene::ISceneNode* forSceneNode, irr::io::IAttributes* userData)
{
    irr::core::stringc sname = forSceneNode->getName();
    static bool physicsEnabled = false;

    // save the root (scene) attributes.
    if(sname == "root")
    {
        physicsEnabled = userData->getAttributeAsBool("Physics.Enabled");
        //
        // turn gravity on
        //
        if(physicsEnabled)
        {
            if(userData->existsAttribute("Gravity"))
            {
//                m_gravity.Y = userData->getAttributeAsFloat("Gravity");
//                _setGravity(m_gravity.Y);
            }
        }

        return;
    }

    irr::scene::ESCENE_NODE_TYPE type = forSceneNode->getType();
    if(type == irr::scene::ESNT_MESH)
    {
        irr::scene::IMeshSceneNode* mnode = reinterpret_cast<irr::scene::IMeshSceneNode*>(forSceneNode);
        if(physicsEnabled)
        {
//            _addPhysicsObject(mnode, userData);
        }

        if(mnode && userData->existsAttribute("HWHint") &&
                !userData->getAttributeAsBool("Physics.Ghost"))
        {
            irr::scene::E_HARDWARE_MAPPING  mapping = irr::scene::EHM_NEVER;
            irr::scene::E_BUFFER_TYPE buffertype = irr::scene::EBT_NONE;

            irr::scene::IMesh* mesh = mnode->getMesh();

            irr::core::stringc smapping = userData->getAttributeAsString("HWHint");
            if(smapping == "static")
                mapping = irr::scene::EHM_STATIC;
            else if(smapping == "dynamic")
                mapping = irr::scene::EHM_DYNAMIC;
            else if(smapping == "stream")
                mapping = irr::scene::EHM_STREAM;

            irr::core::stringc sbuffertype = userData->getAttributeAsString("HWType");
            if(sbuffertype == "vertex")
                buffertype = irr::scene::EBT_VERTEX;
            else if(sbuffertype == "index")
                buffertype = irr::scene::EBT_INDEX;
            else if(sbuffertype == "vertexindex")
                buffertype = irr::scene::EBT_VERTEX_AND_INDEX;

            if((mapping != irr::scene::EHM_NEVER) && (buffertype != irr::scene::EBT_NONE))
                mesh->setHardwareMappingHint(mapping, buffertype);
        }
    }
    else if(type == irr::scene::ESNT_CAMERA)
    {
        /*
        PCamCharInfo    pci = new CamCharInfo;
        pci->camera = reinterpret_cast<ICameraSceneNode*>(forSceneNode);
        pci->width = getConfig()->getFloat("physics.characterWidth", 1.f);
        pci->height = getConfig()->getFloat("physics.characterHeight", 2.f);
        pci->stepHeight = getConfig()->getFloat("physics.characterStepHeight", 0.35f);
        pci->jumpSpeed = getConfig()->getFloat("physics.characterJumpSpeed", 0.3f);

        if(userData->existsAttribute("Character.Width"))
            pci->width = userData->getAttributeAsFloat("Character.Width");
        if(userData->existsAttribute("Character.Height"))
            pci->height = userData->getAttributeAsFloat("Character.Height");
        if(userData->existsAttribute("Character.JumpSpeed"))
            pci->jumpSpeed = userData->getAttributeAsFloat("Character.JumpSpeed");
        if(userData->existsAttribute("Character.StepHeight"))
            pci->stepHeight = userData->getAttributeAsFloat("Character.StepHeight");
        m_cameras.push_back(pci);
        */

    }

}

irr::io::IAttributes* IrrSceceLoader::createUserData(irr::scene::ISceneNode* forSceneNode)
{
    return 0;
}

//-------------------------------------------------------------------------
//                     _ s e t P h y s i c s A t t r i b u t e s
//-------------------------------------------------------------------------
//void IrrSceceLoader::_setPhysicsAttributes(irr::io::IAttributes* userData, struct PhysicsAttributes& attr)
//{
//    EShapeType bodyShape = stConcaveMesh;
//    EBodyType bodyType = btStatic;
//
//    core::stringc sBodyType = userData->getAttributeAsString("Physics.BodyType");
//    if(sBodyType == "none")
//        return;
//
//    core::stringc sBodyShape = userData->getAttributeAsString("Physics.BodyShape");
//    attr.visible = true;
//    if(userData->existsAttribute("Physics.Visible"))
//        attr.visible = userData->getAttributeAsBool("Physics.Visible");
//
//    attr.ghost = userData->getAttributeAsBool("Physics.Ghost");
//    attr.sensor = userData->getAttributeAsBool("Physics.Sensor"); // collision without response
//
//    attr.mass = userData->getAttributeAsFloat("Physics.Mass");
//    attr.friction = userData->getAttributeAsFloat("Physics.Friction");
//    attr.restitution = userData->getAttributeAsFloat("Physics.Restitution");
//    attr.radius = 0.f;
//    if(userData->existsAttribute("Physics.Radius"))
//        attr.radius = userData->getAttributeAsFloat("Physics.Radius");
//
//    if(sBodyShape.equals_ignore_case("box"))
//    {
//        attr.Shapetype = stBox;
//    }
//    else if(sBodyShape.equals_ignore_case("sphere"))
//    {
//        attr.Shapetype = stSphere;
//    }
//    else if(sBodyShape.equals_ignore_case("cylinder"))
//    {
//        attr.Shapetype = stCylinder;
//    }
//    else if(sBodyShape.equals_ignore_case("cone"))
//    {
//        attr.Shapetype = stCone;
//    }
//    else if(sBodyShape.equals_ignore_case("convexmesh"))
//    {
//        attr.Shapetype = stConvexMesh;
//    }
//    else if(sBodyShape.equals_ignore_case("concavemesh"))
//    {
//        attr.Shapetype = stConcaveMesh;
//    }
//
//    attr.BodyType = btStatic;
//    if(sBodyType == "rigid")
//        attr.BodyType = btKinematic;
//    else if(sBodyType == "dynamic")
//        attr.BodyType = btDynamic;
//    else if(sBodyType == "sensor")
//        attr.sensor = true;
//}
//-----------------------------------------------------------------------------------------------
}
}
