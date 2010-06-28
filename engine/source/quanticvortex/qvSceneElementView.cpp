
#include "qvSceneElementView.h"
#include "qvCommandManager.h"

#include "ISceneManager.h"
#include "IFileSystem.h"

// commands
#include "qvSceneLoadCommand.h"

//scene loaders
#include "qvIrrSceneLoader.h"

namespace qv
{
namespace views
{
//---------------------------------------------------------------------
SceneElementView::SceneElementView(const qv::c8* sceneElementViewName, qv::CommandManager* commandManager, irr::scene::ISceneManager* sceneManager)
        : qv::views::AbstractElementView(sceneElementViewName, qv::views::EVT_ELEMENT_VIEW_SCENE, 1), mSceneManager(sceneManager),
        mCommandManager(commandManager)
{
    mCommandManager->registerCommandType(qv::views::CT_SCENE_LOAD); 
    mCommandManager->createCommand<qv::gaming::SceneLoadCommand, qv::views::SceneElementView>("scene_load_command", qv::views::CT_SCENE_LOAD, this);
    mIrrSceneLoader = new qv::views::IrrSceceLoader();
}
//---------------------------------------------------------------------
SceneElementView::~SceneElementView()
{
    mElementViews.clear();
    delete mIrrSceneLoader;
}
//---------------------------------------------------------------------
void SceneElementView::loadScene(const qv::c8* sceneFile)
{
    mSceneManager->getFileSystem()->addZipFileArchive( sceneFile, true, false);
    mSceneManager->loadScene("scene.irr", mIrrSceneLoader);
}
//---------------------------------------------------------------------
void SceneElementView::render( qv::u32 currentTimeMs, qv::u32 elapsedTimeMs)
{
    mSceneManager->drawAll();
}
//---------------------------------------------------------------------
void SceneElementView::update( qv::u32 elapsedTimeMs)
{
    qv::views::ElementViewsList::iterator itr;
    for(itr = mElementViews.begin(); itr != mElementViews.end(); ++itr)
        (*itr)->update(elapsedTimeMs);
}
//-----------------------------------------------------------------------------------------------
}
}
