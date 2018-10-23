#pragma once
#include <cocos2d.h>
#include "UiUtils.h"

namespace transfers
{
class TransferScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* sender);
    CREATE_FUNC(TransferScene);
    static void backTouched();
    static void plusTouched();
    static void minusTouched();
    static void offerTouched();
};
}
