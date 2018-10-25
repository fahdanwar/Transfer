#include "StartScreenScene.h"
#include "MainContractScene.h"
#include "MainTransferScene.h"
#include "TransferNews.h"

USING_NS_CC;
USING_NS_CC_EXT;


namespace transfers
{
cocos2d::Scene *StartScreenScene::createScene()
{
    return StartScreenScene::create();
}

bool StartScreenScene::init()
{
    if(!Scene::init())
        return false;
    mButtonsLayout.init();

    Director* director = Director::getInstance();
    Size visible_size = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();
	director->setClearColor(cocos2d::Color4F::BLACK);

    ui::Button* contractsButton = gui::CreateButton("Contracts");
	mButtonsLayout.addButton(contractsButton, [](){ contractsTouchEvent(); });
	
	//
	auto linear_Layout = cocos2d::ui::LinearLayoutParameter::create();
    ui::Button* transfersButton = gui::CreateButton("Transfers");
	mButtonsLayout.addButton(transfersButton, [](){ transfersTouchEvent(); });
	transfersButton->setLayoutParameter(linear_Layout);
	//layout->setGravity(cocos2d::ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
	linear_Layout->setMargin(cocos2d::ui::Margin(0.0f, 7.0f, 0.0f, 7.0f));



    ui::Button* updateButton = gui::CreateButton("Update");
    mButtonsLayout.addButton(updateButton, [](){ updatesTouchEvent(); });
    mButtonsLayout.setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height - visible_size.height / 10 });
    return true;
}

void StartScreenScene::menuCloseCallback(cocos2d::Ref* /*sender*/)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void contractsTouchEvent()
{
    Director::getInstance()->replaceScene(MainContractScene::create());
}

void transfersTouchEvent()
{
    Director::getInstance()->replaceScene(MainTransferScene::create());
}

void updatesTouchEvent()
{
    Director::getInstance()->replaceScene(TransferNewsScene::create());
}
} // namespace transfers
