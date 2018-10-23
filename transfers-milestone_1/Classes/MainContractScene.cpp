#include "MainContractScene.h"
#include "StartScreenScene.h"
#include "ContractOfferScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
cocos2d::Scene *MainContractScene::createScene()
{
    return MainContractScene::create();
}

bool MainContractScene::init()
{
    if( !Scene::init())
        return false;
    mButtonsLayout.init();

    Director* director = Director::getInstance();
    Size visible_size = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto make_contract_offer_btn = gui::CreateButton("Make contract offer");
    mButtonsLayout.addButton(make_contract_offer_btn, [](){ makeOfferTouchEvent(); });

    auto recieve_contract_request_btn = gui::CreateButton("Recieve contract request");
    mButtonsLayout.addButton(recieve_contract_request_btn, [](){ recieveContractRequestTouchEvent(); });
	auto linear_Layout = cocos2d::ui::LinearLayoutParameter::create();
	recieve_contract_request_btn->setLayoutParameter(linear_Layout);
	linear_Layout->setMargin(cocos2d::ui::Margin(0.0f, 7.0f, 0.0f, 7.0f));
    
	auto back_btn = gui::CreateButton("Back");
    mButtonsLayout.addButton(back_btn, [](){ backTouchEvent(); });

    // TODO: position layout correctly on each system
    mButtonsLayout.setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height - visible_size.height / 10 });
    return true;
}

void MainContractScene::makeOfferTouchEvent()
{
    Director::getInstance()->replaceScene(ContractOfferScene::create());
}

void MainContractScene::recieveContractRequestTouchEvent()
{
    Director::getInstance()->replaceScene(ContractOfferScene::create());
}

void MainContractScene::backTouchEvent()
{
    Director::getInstance()->replaceScene(StartScreenScene::create());
}
}
