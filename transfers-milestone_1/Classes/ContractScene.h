#pragma once
#include <cocos2d.h>
#include "UiUtils.h"

namespace transfers
{
class ContractScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* sender);
    CREATE_FUNC(ContractScene);
    static void pricesChanged(int value, const std::string& widget_name);
private:
    static void offerTouched();
    static void backTouched();
};
}
