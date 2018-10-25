#include "TransferScene.h"
#include "cocos-ext.h"
#include "MainTransferScene.h"
#include <ui/UIListView.h>
#include <ui/UIEditBox/UIEditBox.h>

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{

cocos2d::Scene* TransferScene::createScene()
{
    return TransferScene::create();
}

bool TransferScene::init()
{
    if(!Scene::init())
        return false;

    auto director = Director::getInstance();
    Size visible_size = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();
    auto main_layout = cocos2d::ui::Layout::create();
    auto player_info_layout = cocos2d::ui::Layout::create();
    auto price_layout = cocos2d::ui::Layout::create();
    auto quick_prices_layout = cocos2d::ui::Layout::create();
    auto controls_layout = cocos2d::ui::Layout::create();

    // Set main vertical layout
    main_layout->setLayoutType(cocos2d::ui::Layout::Type::VERTICAL);
    main_layout->addChild(player_info_layout);
    main_layout->addChild(price_layout);
    main_layout->addChild(quick_prices_layout);
    main_layout->addChild(controls_layout);
    main_layout->setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height - visible_size.height / 10 });

    // Set player info layout
    player_info_layout->setLayoutType(cocos2d::ui::Layout::Type::VERTICAL);
    auto player_info_label = cocos2d::Label::create();
    // set default text string
    // TODO: change later basing on game logic
    player_info_label->setString("Player info");
    player_info_layout->addChild(player_info_label);

    auto player_name = cocos2d::Label::create();
    player_name->setString("Player name");
    player_info_layout->addChild(player_name);

    auto player_value = cocos2d::Label::create();
    player_value->setString("Player value");
    player_info_layout->addChild(player_value);

    // Set price layout
    price_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
    auto plus_button = gui::CreateTextButton("+");
    plus_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
    {
        switch(type)
        {
        case ui::Widget::TouchEventType::ENDED:
            plusTouched();
            break;
        default:
            break;
        }
    });
    price_layout->addChild(plus_button);

    // TODO: correct size
    // TODO: get only numbers
    // TODO: deprecated
    auto price_edit = EditBox::create(Size(300, 150), "edit_box.png");
    price_layout->addChild(price_edit);

    auto minus_button = gui::CreateTextButton("-");
    minus_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
    {
        switch (type)
        {
        case ui::Widget::TouchEventType::ENDED:
            minusTouched();
            break;
        default:
            break;
        }
    });
    price_layout->addChild(minus_button);

    // TODO: fill list view with buttons
    auto list_view = cocos2d::ui::ListView::create();
    quick_prices_layout->addChild(list_view);

    auto offer_button = gui::CreateButton("Offer");
    offer_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
    {
        switch (type)
        {
        case ui::Widget::TouchEventType::ENDED:
            offerTouched();
            break;
        default:
            break;
        }
    });
    controls_layout->addChild(offer_button);


    auto back_button = gui::CreateButton("back");
    back_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
    {
        switch (type)
        {
        case ui::Widget::TouchEventType::ENDED:
            backTouched();
            break;
        default:
            break;
        }
    });
    controls_layout->addChild(back_button);
    controls_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
    this->addChild(main_layout);
    return true;
}

void TransferScene::menuCloseCallback(cocos2d::Ref* /*sender*/)
{
}

void TransferScene::backTouched()
{
    auto director = Director::getInstance();
    director->replaceScene(MainTransferScene::create());
}

void TransferScene::plusTouched()
{
}

void TransferScene::minusTouched()
{
}

void TransferScene::offerTouched()
{
}
}
