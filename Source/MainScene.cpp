#include "MainScene.h"

USING_NS_AX;


bool MainScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();
    auto safeArea = _director->getSafeAreaRect();
    auto safeOrigin = safeArea.origin;

    // win dialog
    fairygui::UIConfig::registerFont("Poppins-SemiBold", "fonts/Poppins-SemiBold.ttf");

    groot = fairygui::GRoot::create(this);
    groot->retain();

    fairygui::UIPackage::addPackage("ui/dialog/dialog");

    dialog = WinDialogWindow::create();
    dialog->retain();
    dialog->show();
    
    scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{
    //
}
