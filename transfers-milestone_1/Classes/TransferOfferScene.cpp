#include "TransferOfferScene.h"
#include "MainTransferScene.h"
#include "TransferScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
void TransferOfferTableViewDelegate::tableCellTouched(cocos2d::extension::TableView* table,
    cocos2d::extension::TableViewCell* cell)
{
     // TODO: info about what cell was touched
     Director::getInstance()->replaceScene(TransferScene::create());
}

bool TransferOfferScene::init()
{
    if(!BasicOfferScene::init())
        return false;

    Size visible_size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto back_button = gui::CreateButton("Back");
    mLayout.addButton(back_button, [](){ backClicked(); });
    mLayout.setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height - visible_size.height / 10 });

    return true;
}

void TransferOfferScene::backClicked()
{
    auto transfer_scene = MainTransferScene::create();
    Director::getInstance()->replaceScene(transfer_scene);
}

} // namespace transfers
