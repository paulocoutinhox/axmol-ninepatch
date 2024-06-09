#include "MainScene.h"
#include "ui/UIButton.h"
#include "ui/UIScale9Sprite.h"

#include <spine/spine-axmol.h>
// #include <spine/Extension.h>

USING_NS_AX;
using namespace spine;

bool MainScene::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    //    // demo dialog
    //    fairygui::UIConfig::registerFont("Poppins-SemiBold", "fonts/Poppins-SemiBold.ttf");
    //
    //    groot = fairygui::GRoot::create(this);
    //    groot->retain();
    //
    //    fairygui::UIPackage::addPackage("ui/fairy-gui/Main");
    //
    //    dialog = DemoDialogWindow::create();
    //    dialog->retain();
    //    dialog->show();
    //

    getPhysicsWorld()->setGravity(Vec2(0, -980));

//    const char* atlasPath = "spine/Pirate.atlas";
//    const char* skelPath  = "spine/Pirate.json";
    const char* atlasPath = "spine/goblins.atlas";
    const char* skelPath  = "spine/goblins-pro.json";

    // Carregar atlas
    //    spAtlas* atlas = spAtlas_createFromFile(atlasPath, 0);
    //    if (!atlas) {
    //        AXLOG("Erro ao carregar o atlas: %s", atlasPath);
    //        return false;
    //    }

    //
    //    // Carregar SkeletonBinary e SkeletonData
    //    SkeletonBinary* binary = new SkeletonBinary(atlas);
    //    binary->setScale(0.6f); // Ajuste a escala conforme necessário
    //    SkeletonData* skeletonData = binary->readSkeletonDataFile(skelPath);
    //    if (!skeletonData) {
    //        AXLOG("Erro ao carregar os dados do esqueleto: %s", skelPath);
    //        delete atlas;
    //        delete binary;
    //        return false;
    //    }
    //
    // Criar SkeletonAnimation
    SkeletonAnimation* skeletonNode = SkeletonAnimation::createWithJsonFile(skelPath, atlasPath);
    skeletonNode->setAnimation(0, "walk", true);
    skeletonNode->setPosition(Vec2(400, 300));  // Defina a posição conforme necessário
    skeletonNode->setScale(1.5f);
    skeletonNode->setSkin("goblin");
    addChild(skeletonNode);

    auto body = PhysicsBody::createBox(Size(50, 100));  // Ajuste o tamanho conforme necessário
    body->setDynamic(true);
    body->setRotationEnable(false);
    body->setMass(1);
    skeletonNode->setPhysicsBody(body);

    auto ground = Node::create();
    ground->setPosition(Vec2(400, 50));  // Ajuste a posição conforme necessário

    auto groundBody = PhysicsBody::createBox(Size(800, 20));  // Ajuste o tamanho conforme necessário
    groundBody->setDynamic(false);                            // Fazer o corpo ser estático

    ground->setPhysicsBody(groundBody);
    addChild(ground);

    // button
    ax::ui::Button* button = ax::ui::Button::create("ui/button.9.png");
    button->setScale9Enabled(true);
    button->setContentSize(Vec2(400, 240));
    button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.85));
    button->addClickEventListener([=](Ref* sender) {
        if (anim == "idle")
        {
            skeletonNode->setAnimation(0, "Attack_1", true);
            anim = "attack_1";
            body->applyImpulse(Vec2(0, 500));
        }
        else
        {
            skeletonNode->setAnimation(0, "Idle", true);
            anim = "idle";
        }
    });
    button->retain();
    addChild(button);

    scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{
    //
}
