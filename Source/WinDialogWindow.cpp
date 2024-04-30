#include "WinDialogWindow.h"

using namespace fairygui;

void WinDialogWindow::onInit()
{
    setContentPane(UIPackage::createObject("MainPackage", "Main")->as<GComponent>());
    center();
}

void WinDialogWindow::onShown()
{
    //
}
