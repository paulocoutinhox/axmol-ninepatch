#pragma once

#include "axmol.h"
#include "FairyGUI.h"

class DemoDialogWindow : public fairygui::Window
{
public:
    public:
    CREATE_FUNC(DemoDialogWindow);

protected:
    virtual void onInit() override;
    virtual void onShown() override;
};
