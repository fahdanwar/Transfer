#pragma once
#include <cocos2d.h>
#include <extensions/cocos-ext.h>
#include "UiUtils.h"

namespace transfers
{
    class MainTransferScene : public cocos2d::Scene
    {
    public:
        MainTransferScene() : mButtonsLayout(this)
        {
        }

        static cocos2d::Scene* createScene();
        virtual bool init();
        void menuCloseCallback(cocos2d::Ref* sender);
        CREATE_FUNC(MainTransferScene);

        static void makeOfferTouchEvent();
        static void recieveRequestTouchEvent();
        static void backTouchEvent();
    private:
        gui::VerticalLayoutWithButtons mButtonsLayout;
    };
}
