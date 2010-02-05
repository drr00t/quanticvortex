
#include "runtime/qvSceneLoadProcess.h"
#include "core/qvActorArgs.h"
#include "events/qvEngineEvents.h"
#include "events/qvEventManager.h"

using namespace qv::events;

namespace qv
{
    namespace runtime
    {
		//-----------------------------------------------------------------------------------------
		SceneLoadProcess::SceneLoadProcess(EngineManager* engineManager, stringc& levelContent)
			: mEngineManager(engineManager), mLevelContent(levelContent),mReadFile(0),mXmlReader(0)
        {
			//levelContent
			mEngineManager->getFileSystem()->addZipFileArchive(levelContent.c_str());
			mReadFile = mEngineManager->getFileSystem()->createAndOpenFile(L"Scene.irr");
			mXmlReader = mEngineManager->getFileSystem()->createXMLReader(mReadFile);
        }
		//-----------------------------------------------------------------------------------------
        SceneLoadProcess::~SceneLoadProcess()
        {
			mReadFile->drop();
			mXmlReader->drop();
        }
		//-----------------------------------------------------------------------------------------
		Process::ProcessStatus SceneLoadProcess::update(u32 elapsedTime)
		{
            bool endReached = false;

			if(mXmlReader->read() && !endReached)
			{
				if (stringw(L"irr_scene").equals_ignore_case(mXmlReader->getNodeName()))
				{
                    switch(mXmlReader->getNodeType())
                    {
                    case EXN_ELEMENT_END:
						mProcessStatus = Process::Completed;
						endReached = true;
						break;
					}
				}
				else if (stringw(L"node").equals_ignore_case(mXmlReader->getNodeName()))
				{
                    if(stringc(L"mesh").equals_ignore_case(mXmlReader->getAttributeValue(L"type")))
                    {
                        parseMeshActorArgs(mXmlReader, 0);
                    }
					else if(stringc(L"camera").equals_ignore_case(mXmlReader->getAttributeValue(L"type")))
					{
						parseCameraActorArgs(mXmlReader, 0);
					}
					else if(stringc(L"light").equals_ignore_case(mXmlReader->getAttributeValue(L"type")))
					{
						parseLightActorArgs(mXmlReader, 0);
					}
					else if(stringc(L"skyDome").equals_ignore_case(mXmlReader->getAttributeValue(L"type")))
					{
						parseSkyDomeActorArgs(mXmlReader, 0);
					}
				}
			}
			else
			{
				if(!endReached)
					mProcessStatus = Process::Failed;
				mProcessStatus = Process::Completed;
			}

			return mProcessStatus;
		}
		//-----------------------------------------------------------------------------------------
		void SceneLoadProcess::parseMeshActorArgs(IXMLReader* xmlReader, s32 parentActorID)
		{
            bool endReached = false;
            bool attributes = false;
			MeshActorArgs* args = new MeshActorArgs();
			args->grab();

			args->setParentActorID(parentActorID);
			args->setNodeType(mXmlReader->getAttributeValue(L"type"));

			while(xmlReader->read() && !endReached)
			{
                    switch(xmlReader->getNodeType())
                    {
                    case EXN_ELEMENT_END:
		                
                        if (stringw(L"node") == xmlReader->getNodeName())
						{
							//firing event new actor added
                            IEventArgs* newActor = 
								new NewActorEventArgs( ActorID(args->getName()), args);
							mEngineManager->getEventManager()->enqueueEvent(newActor);

							endReached = true;
						}

                        break;
	                case EXN_ELEMENT:
		                if (!attributes && stringw(L"attributes")==xmlReader->getNodeName())
		                {
			                // read attributes
			                IAttributes* attr = 
                                mEngineManager->getFileSystem()->createEmptyAttributes();
							
							attr->grab();
			                
							attr->read(xmlReader, true);
                      
                            args->deserializeAttributes(attr);
							
							//stringw logdata = L"[ACTORNAME]: ";
							//logdata += args.getName();
							//logdata += L"   "; 
							//logdata += L"[NODE]:  ";
							//logdata += xmlReader->getNodeName();

							//os::Printer::log("[NODE]: ", logdata);

                            attr->drop();

							attributes = true;
		                }
						else if (stringw(L"userData")==xmlReader->getNodeName())
		                {
							
			    //            // read attributes
			    //            IAttributes* attr = 
       //                         mGameApp->getFileSystem()->createEmptyAttributes();
			    //            attr->read(xmlReader, true);
       //               
       //                     args.deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

       //                     attr->drop();
		                }

						break;
                    default:
                        break;
					}
				//}
    		}
		}
		//-----------------------------------------------------------------------------------------
		void SceneLoadProcess::parseLightActorArgs(IXMLReader* xmlReader, s32 parentActorID)
		{
            bool endReached = false;
            bool attributes = false;
			LightActorArgs* args = new LightActorArgs();

			args->setParentActorID(parentActorID);
			args->setNodeType(mXmlReader->getAttributeValue(L"type"));

			while(xmlReader->read() && !endReached)
			{
    //            if (L"node" == xmlReader->getNodeName())
				//{
                    switch(xmlReader->getNodeType())
                    {
                    case EXN_ELEMENT_END:
		                
                        if (stringw(L"node") == xmlReader->getNodeName())
						{
							//firing event new actor added
                            IEventArgs* newActor = 
								new NewActorEventArgs( ActorID(args->getName()), args);
							mEngineManager->getEventManager()->enqueueEvent(newActor);

							endReached = true;
						}

                        break;
	                case EXN_ELEMENT:
		                if (!attributes && stringw(L"attributes")==xmlReader->getNodeName())
		                {
			                // read attributes
			                IAttributes* attr = 
                                mEngineManager->getFileSystem()->createEmptyAttributes();
			                attr->read(xmlReader, true);
							attr->grab();

                            args->deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

                            attr->drop();

							attributes = true;
		                }
						else if (stringw(L"userData")==xmlReader->getNodeName())
		                {
							
			    //            // read attributes
			    //            IAttributes* attr = 
       //                         mGameApp->getFileSystem()->createEmptyAttributes();
			    //            attr->read(xmlReader, true);
       //               
       //                     args.deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

       //                     attr->drop();
		                }
						//else if (stringw(L"node")==xmlReader->getNodeName())// ||
						//	//(IRR_XML_FORMAT_SCENE==reader->getNodeName()))
						//{
						//	stringc attrName = mXmlReader->getAttributeValue(L"type");

						//	if(stringc(L"mesh").equals_ignore_case(attrName))
						//	{
						//		parseMeshActorArgs(mXmlReader, args.getID());
						//	}
						//	else if(stringc(L"camera").equals_ignore_case(attrName))
						//	{
						//		//parseCameraActorArgs(mXmlReader, args.getID());
						//	}
						//	else if(stringc(L"light").equals_ignore_case(attrName))
						//	{
						//		parseLightActorArgs(mXmlReader, args.getID());
						//	}
						//}
						//else
						//{
						//	os::Printer::log("Found unknown element in irrlicht scene file",
						//			stringc(xmlReader->getNodeName()).c_str());
						//}
                        break;
                    default:
                        break;
					}
				//}
    		}
		}
		//-------------------------------------------------------------------------------------------------
		void SceneLoadProcess::parseCameraActorArgs(IXMLReader* xmlReader, s32 parentActorID)
		{
            bool endReached = false;
            bool attributes = false;
			CameraActorArgs* args = new CameraActorArgs();

			args->setParentActorID(parentActorID);
			args->setNodeType(mXmlReader->getAttributeValue(L"type"));

			while(xmlReader->read() && !endReached)
			{
                    switch(xmlReader->getNodeType())
                    {
                    case EXN_ELEMENT_END:
		                
                        if (stringw(L"node") == xmlReader->getNodeName())
						{
							//firing event new actor added
                            IEventArgs* newActor = 
								new NewActorEventArgs( ActorID(args->getName()), args);
							mEngineManager->getEventManager()->enqueueEvent(newActor);

							endReached = true;
						}

                        break;
	                case EXN_ELEMENT:
		                if (!attributes && stringw(L"attributes")==xmlReader->getNodeName())
		                {
			                // read attributes
			                IAttributes* attr = 
                                mEngineManager->getFileSystem()->createEmptyAttributes();
			                attr->read(xmlReader, true);
							attr->grab();
                      
                            args->deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

                            attr->drop();

							attributes = true;
		                }
						else if (stringw(L"userData")==xmlReader->getNodeName())
		                {
							
			    //            // read attributes
			    //            IAttributes* attr = 
       //                         mGameApp->getFileSystem()->createEmptyAttributes();
			    //            attr->read(xmlReader, true);
       //               
       //                     args.deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

       //                     attr->drop();
		                }
						//else if (stringw(L"node")==xmlReader->getNodeName())// ||
						//	//(IRR_XML_FORMAT_SCENE==reader->getNodeName()))
						//{
						//	//readSceneNode(reader, node, userDataSerializer);
						//	parseMeshActorArgs(mXmlReader, args.getID());
						//}
						//else
						//{
						//	os::Printer::log("Found unknown element in irrlicht scene file",
						//			stringc(xmlReader->getNodeName()).c_str());
						//}
                        break;
                    default:
                        break;
					}
				//}
    		}
		}
		//-------------------------------------------------------------------------------------------------
		void SceneLoadProcess::parseSkyDomeActorArgs(IXMLReader* xmlReader, s32 parentActorID)
		{
            bool endReached = false;
            bool attributes = false;
			SkyDomeActorArgs* args = new SkyDomeActorArgs();

			args->setParentActorID(parentActorID);
			args->setNodeType(mXmlReader->getAttributeValue(L"type"));

			while(xmlReader->read() && !endReached)
			{
    //            if (L"node" == xmlReader->getNodeName())
				//{
                    switch(xmlReader->getNodeType())
                    {
                    case EXN_ELEMENT_END:
		                
                        if (stringw(L"node") == xmlReader->getNodeName())
						{
							//firing event new actor added
                            IEventArgs* newActor = 
								new NewActorEventArgs( ActorID(args->getName()), args);
							mEngineManager->getEventManager()->enqueueEvent(newActor);

							endReached = true;
						}

                        break;
	                case EXN_ELEMENT:
		                if (!attributes && stringw(L"attributes")==xmlReader->getNodeName())
		                {
			                // read attributes
			                IAttributes* attr = 
                                mEngineManager->getFileSystem()->createEmptyAttributes();
			                attr->read(xmlReader, true);
							attr->grab();

                            args->deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

                            attr->drop();

							attributes = true;
		                }
						else if (stringw(L"userData")==xmlReader->getNodeName())
		                {
							
			    //            // read attributes
			    //            IAttributes* attr = 
       //                         mGameApp->getFileSystem()->createEmptyAttributes();
			    //            attr->read(xmlReader, true);
       //               
       //                     args.deserializeAttributes(attr);
			
							//os::Printer::log("[ACTORNAME]:", args.getName());

       //                     attr->drop();
		                }
						//else if (stringw(L"node")==xmlReader->getNodeName())// ||
						//	//(IRR_XML_FORMAT_SCENE==reader->getNodeName()))
						//{
						//	stringc attrName = mXmlReader->getAttributeValue(L"type");

						//	if(stringc(L"mesh").equals_ignore_case(attrName))
						//	{
						//		parseMeshActorArgs(mXmlReader, args.getID());
						//	}
						//	else if(stringc(L"camera").equals_ignore_case(attrName))
						//	{
						//		//parseCameraActorArgs(mXmlReader, args.getID());
						//	}
						//	else if(stringc(L"light").equals_ignore_case(attrName))
						//	{
						//		parseLightActorArgs(mXmlReader, args.getID());
						//	}
						//}
						//else
						//{
						//	os::Printer::log("Found unknown element in irrlicht scene file",
						//			stringc(xmlReader->getNodeName()).c_str());
						//}
                        break;
                    default:
                        break;
					}
				//}
    		}
		}
		//-------------------------------------------------------------------------------------------------
	}
}

