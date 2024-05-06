#include "DemoDialogWindow.h"

using namespace fairygui;

void DemoDialogWindow::onInit()
{
    setContentPane(UIPackage::createObject("Main", "DemoDialog")->as<GComponent>());
    center();
}

void DemoDialogWindow::onShown()
{
    //
}
