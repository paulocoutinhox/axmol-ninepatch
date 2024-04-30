#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "axmol.h"
#include "FairyGUI.h"
#include "WinDialogWindow.h"


class MainScene : public ax::Scene
{
public:
    bool init() override;
    void update(float delta) override;
private:
    fairygui::GRoot* groot;
    WinDialogWindow* dialog;
};

#endif  // __MAIN_SCENE_H__
