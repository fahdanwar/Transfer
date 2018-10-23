#include "TransferNews.h"
#include "StartScreenScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
cocos2d::extension::TableViewCell* TransferNewsTableViewDataSource::tableCellAtIndex(
    cocos2d::extension::TableView* table, ssize_t idx)
{
    auto cell = table->dequeueCell();
    cell = TableViewCell::create();

    auto cell_layout = ui::Layout::create();
    cell_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);

    auto price_label = Label::create();
    price_label->setString("price here");
    cell_layout->addChild(price_label);

    auto team_name_label = Label::create();
    team_name_label->setString("Team name here");
    cell_layout->addChild(team_name_label);

    auto buttons_layout = ui::Layout::create();
    buttons_layout->setLayoutType(ui::Layout::Type::VERTICAL);
    auto accept_button = gui::CreateButton("Accept");
    auto reject_button = gui::CreateButton("Reject");
    auto negotiate_button = gui::CreateButton("Negotiate");
    buttons_layout->addChild(accept_button);
    buttons_layout->addChild(reject_button);
    buttons_layout->addChild(negotiate_button);

    cell_layout->addChild(buttons_layout);

    cell->addChild(cell_layout);
    return cell;
}

ssize_t TransferNewsTableViewDataSource::numberOfCellsInTableView(cocos2d::extension::TableView* table)
{
    // TODO:
    return 5;
}

void TransferNewsTableViewDelegate::tableCellTouched(cocos2d::extension::TableView* table,
    cocos2d::extension::TableViewCell* cell)
{
}

 cocos2d::Scene* TransferNewsScene::createScene()
{
    return TransferNewsScene::create();
}

bool TransferNewsScene::init()
{
    if (!Scene::init())
        return false;

    Director* director = Director::getInstance();
    Size visible_size = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto main_layout = ui::Layout::create();
    main_layout->setLayoutType(ui::Layout::Type::VERTICAL);

    auto main_scroll = ScrollView::create();
    main_scroll->setDirection(ScrollView::Direction::VERTICAL);
    main_scroll->setContentSize(Size{ visible_size.width - 20, visible_size.height - 50 });
    // TODO: for player in players add table view
    auto tb = TableView::create(&mDataSource, Size{ visible_size.width - 20, 10 });
    tb->setDelegate(&mTableViewDelegate);
    main_scroll->addChild(tb);
    // end for
    main_layout->addChild(main_scroll);

    auto done_button = gui::CreateButton("Done");
    done_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
    {
        if(type == ui::Widget::TouchEventType::ENDED)
            Director::getInstance()->replaceScene(StartScreenScene::create());
    });
    main_layout->addChild(done_button);
    main_layout->setPosition(Vec2{ origin.x + visible_size.width / 4, origin.y + visible_size.height - visible_size.height / 10 });
    this->addChild(main_layout);
    return true;
}

void TransferNewsScene::menuCloseCallback(cocos2d::Ref* sender)
{
}
}
