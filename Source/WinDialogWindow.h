#pragma once

#include "axmol.h"
#include "FairyGUI.h"

class WinDialogWindow : public fairygui::Window
{
public:
    public:
    CREATE_FUNC(WinDialogWindow);

protected:
    virtual void onInit() override;
    virtual void onShown() override;
};
