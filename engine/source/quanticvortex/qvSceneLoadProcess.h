
#ifndef __SCENELOADPROCESS_H_
#define __SCENELOADPROCESS_H_

#include "qvEngineManager.h"
#include "runtime/qvProcess.h"
//#include "scene/cqeSceneView.h"

using namespace irr::io;

using namespace qv::core;

namespace qv
{
    namespace runtime
    {
        class _QUANTICVORTEX_API SceneLoadProcess: public Process
        {
        public:
            SceneLoadProcess(EngineManager* engineManager, stringc& levelContent);
			virtual ~SceneLoadProcess();
			virtual ProcessStatus update(u32 elapsedTime);

			inline void setSceneContent(const stringc& levelContent){mLevelContent = levelContent;}

        private:
            void parseMeshActorArgs(IXMLReader* xmlReader, s32 parentActorID);
			void parseLightActorArgs(IXMLReader* xmlReader, s32 parentActorID);
			void parseCameraActorArgs(IXMLReader* xmlReader, s32 parentActorID);
			void parseSkyDomeActorArgs(IXMLReader* xmlReader, s32 parentActorID);

        private:
            EngineManager* mEngineManager;
			stringc mLevelContent;

			IReadFile* mReadFile;
			IXMLReader* mXmlReader;

            //SceneView* mScene;
            //IFileSystem* mFilesystem;

        };
    }
}
#endif

