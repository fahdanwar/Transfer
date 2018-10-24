#include "ContractOfferScene.h"
#include "MainContractScene.h"
#include "ContractScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
void ContractOfferTableViewDelegate::tableCellTouched(cocos2d::extension::TableView* table,
    cocos2d::extension::TableViewCell* cell)
{
    // TODO: info about what cell was touched
    Director::getInstance()->replaceScene(ContractScene::create());
}

bool ContractOfferScene::init()
{
    if(!BasicOfferScene::init())
        return false;

    Size visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto back_button = gui::CreateButton("Back");
    mLayout.addButton(back_button, [](){ backClicked(); });
    mLayout.setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height  / 4 });
//	mLayout.setPosition(Vec2{ 100, 80 });

    return true;
}

void ContractOfferScene::backClicked()
{
    Director::getInstance()->replaceScene(MainContractScene::create());
}
} // namespace transfers
