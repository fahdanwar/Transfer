#include "MainTransferScene.h"
#include "StartScreenScene.h"
#include "TransferOfferScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
cocos2d::Scene* MainTransferScene::createScene()
{
    return MainTransferScene::create();
}

bool MainTransferScene::init()
{
    if( !Scene::init())
        return false;
    mButtonsLayout.init();

    Director* director = Director::getInstance();
    Size visible_size = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

	auto make_offer_btn = gui::CreateButton("Make transfer offer");
	mButtonsLayout.addButton( make_offer_btn, [](){ makeOfferTouchEvent(); });

    auto recieve_request_btn = gui::CreateButton("Recieve transfer request");
    mButtonsLayout.addButton( recieve_request_btn, [](){ recieveRequestTouchEvent(); });

	auto linear_Layout = cocos2d::ui::LinearLayoutParameter::create();
	recieve_request_btn->setLayoutParameter(linear_Layout);
	linear_Layout->setMargin(cocos2d::ui::Margin(0.0f, 7.0f, 0.0f, 7.0f));



    auto back_btn = gui::CreateButton("Back");
    mButtonsLayout.addButton(back_btn, [](){ backTouchEvent(); });


    mButtonsLayout.setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height - visible_size.height / 10 });
    return true;
}

void MainTransferScene::menuCloseCallback(cocos2d::Ref* /*sender*/)
{
}


void MainTransferScene::makeOfferTouchEvent()
{
    Director::getInstance()->replaceScene(TransferOfferScene::create());
}

void MainTransferScene::recieveRequestTouchEvent()
{
    Director::getInstance()->replaceScene(TransferOfferScene::create());
}

void MainTransferScene::backTouchEvent()
{
    Director::getInstance()->replaceScene(StartScreenScene::create());
}
} // namespace transfers
