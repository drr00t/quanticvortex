
#include "qvSceneElementView.h"
#include "qvCommandManager.h"
#include "qvGame.h"


namespace qv
{
namespace views
{
//---------------------------------------------------------------------
SceneElementView::SceneElementView(const qv::views::EVI_ELEMENT_VIEW_ID& elementViewId, qv::Game* game)
        : qv::views::AbstractElementView(elementViewId, qv::views::EVT_ELEMENT_VIEW_SCENE, 1),
        mCommandManager(game->getCommandManager())
{

}
//---------------------------------------------------------------------
SceneElementView::~SceneElementView()
{
    mElementViews.clear();
}
//-----------------------------------------------------------------------------------------------
}
}
