#pragma once
#include <cocos2d.h>
#include <extensions/cocos-ext.h>
#include "UiUtils.h"

namespace transfers
{
    class StartScreenScene : public cocos2d::Scene
    {
    public:
        StartScreenScene() : mButtonsLayout(this)
        {
        }

        static cocos2d::Scene* createScene();
        virtual bool init();
        void menuCloseCallback(cocos2d::Ref* sender);
        CREATE_FUNC(StartScreenScene);
    private:
        gui::VerticalLayoutWithButtons mButtonsLayout;
    };

    static void contractsTouchEvent();
    static void transfersTouchEvent();
    static void updatesTouchEvent();
}
