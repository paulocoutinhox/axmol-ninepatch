#include "MainScene.h"
#include "ui/UIButton.h"
#include "ui/UIScale9Sprite.h"

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

    // demo dialog
    fairygui::UIConfig::registerFont("Poppins-SemiBold", "fonts/Poppins-SemiBold.ttf");

    groot = fairygui::GRoot::create(this);
    groot->retain();

    fairygui::UIPackage::addPackage("ui/fairy-gui/Main");

    dialog = DemoDialogWindow::create();
    dialog->retain();
    dialog->show();

    // button
    ax::ui::Button *button = ax::ui::Button::create("ui/button.9.png");
    button->setScale9Enabled(true);
    button->setContentSize(Vec2(400, 240));
    button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.85));
    button->retain();
    addChild(button);

    scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{
    //
}
