#pragma once
#include <cocos2d.h>
#include <extensions/cocos-ext.h>
#include "UiUtils.h"

namespace transfers
{
    class MainContractScene : public cocos2d::Scene
    {
    public:
        MainContractScene() : mButtonsLayout(this)
        {
        }

        static cocos2d::Scene* createScene();
        virtual bool init();
        void menuCloseCallback(cocos2d::Ref* sender) {}
        CREATE_FUNC(MainContractScene);

        static void makeOfferTouchEvent();
        static void recieveContractRequestTouchEvent();
        static void backTouchEvent();
    private:
        gui::VerticalLayoutWithButtons mButtonsLayout;
    };
}
