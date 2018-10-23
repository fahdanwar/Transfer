#include "ContractScene.h"
#include "ui/UIListView.h"
#include "MainContractScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
namespace
{
    ui::Layout* CreatePriceSelector()
    {
        auto price_selector_layout = ui::Layout::create();
        price_selector_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
        auto plus_button = gui::CreateButton("+");
        plus_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::ENDED:
                // TODO: update values
                ContractScene::pricesChanged(100, std::string{ "test" });
                break;
            default:
                break;
            }
        });
        price_selector_layout->addChild(plus_button);

        // TODO: correct size
        // TODO: get only numbers
        // TODO: deprecated
        auto price_edit = EditBox::create(Size(300, 150), "edit_box.png");
        price_selector_layout->addChild(price_edit);

        auto minus_button = gui::CreateButton("-");
        minus_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case ui::Widget::TouchEventType::ENDED:
                // TODO: update values
                ContractScene::pricesChanged(100, std::string{ "test" });
                break;
            default:
                break;
            }
        });
        price_selector_layout->addChild(minus_button);
        return price_selector_layout;
    }

    ui::Layout* CreatePricesBlock(const std::string& label)
    {
        auto block_label = Label::create();
        block_label->setString(label);
        auto block_layout = ui::Layout::create();
        block_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
        block_layout->addChild(block_label);
        block_layout->addChild(CreatePriceSelector());
        return block_layout;
    }
} // anonymous namespace
cocos2d::Scene* ContractScene::createScene()
{
    return ContractScene::create();
}

bool ContractScene::init()
{
    if (!Scene::init())
        return false;

    auto director = Director::getInstance();
    Size visible_size = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto main_layout = ui::Layout::create();
    auto player_info_layout = ui::Layout::create();
    auto prices_layout = ui::Layout::create();
    auto quick_prices_layout = ui::Layout::create();
    auto controls_layout = cocos2d::ui::Layout::create();
    main_layout->setLayoutType(ui::Layout::Type::VERTICAL);
    main_layout->addChild(player_info_layout);
    main_layout->addChild(prices_layout);
    main_layout->addChild(quick_prices_layout);
    main_layout->addChild(controls_layout);

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

    prices_layout->setLayoutType(ui::Layout::Type::VERTICAL);
    prices_layout->addChild(CreatePricesBlock("Salary"));
    prices_layout->addChild(CreatePricesBlock("Years"));
    prices_layout->addChild(CreatePricesBlock("Bonus"));
    prices_layout->addChild(CreatePricesBlock("Goal bonus"));

    // Set quick prices layout
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

void ContractScene::menuCloseCallback(cocos2d::Ref* /* sender */)
{
}

void ContractScene::pricesChanged(int /* value */, const std::string& /* widget_name */)
{
    // TODO read prices widget values
}

void ContractScene::offerTouched()
{
}

void ContractScene::backTouched()
{
    auto director = Director::getInstance();
    director->replaceScene(MainContractScene::create());
}
} // namespace transfers
