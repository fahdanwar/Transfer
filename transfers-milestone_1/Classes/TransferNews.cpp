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

	Size visible_size = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto cell_layout = ui::Layout::create();
	//cell_layout->setSize(cocos2d::Size(400, 150));
   cell_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
	cell_layout->setAnchorPoint(Vec2(0, 0));
	//cell_layout->setPosition(Vec2(50, visible_size.height/2));
    auto price_label = Label::create();
	price_label->setColor(cocos2d::Color3B::BLACK);
	price_label->enableBold();
	price_label->setString("price here");
	price_label->setPosition(Vec2(50, 0));
    cell_layout->addChild(price_label);

    auto team_name_label = Label::create();
	team_name_label->setPosition(Vec2(130, 0));
    team_name_label->setString("Team name here");
	team_name_label->setColor(cocos2d::Color3B::BLACK);
	team_name_label->enableBold();
    cell_layout->addChild(team_name_label);

    auto buttons_layout = ui::Layout::create();
    buttons_layout->setLayoutType(ui::Layout::Type::VERTICAL);
	//buttons_layout->setSize(cocos2d::Size(50, 150));
	//buttons_layout->setAnchorPoint(Vec2(1, 1));
	auto accept_button = gui::CreateTextButton("Accept");
	//accept_button->setSize(Size(50, 50));// (Vec2(200, 100));
	auto reject_button = gui::CreateTextButton("Reject");
    auto negotiate_button = gui::CreateTextButton("Negotiate");
    buttons_layout->addChild(accept_button);
    buttons_layout->addChild(reject_button);
    buttons_layout->addChild(negotiate_button);
	//buttons_layout->setSize(Size(50, 50));
	//buttons_layout->setAnchorPoint(Vec2(1, 1));
	buttons_layout->setPosition(Vec2(200,10 ));

    cell->addChild(buttons_layout);
//	cell_layout->setPosition(Vec2(400, 70));
    cell->addChild(cell_layout);
    
	
	return cell;
}

ssize_t TransferNewsTableViewDataSource::numberOfCellsInTableView(cocos2d::extension::TableView* table)
{
    // TODO:
    return 5;
}

cocos2d::Size TransferNewsTableViewDataSource::tableCellSizeForIndex(cocos2d::extension::TableView * table, ssize_t idx)
{
	return cocos2d::Size(600,400);
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
    auto tb = TableView::create(&mDataSource, Size{ visible_size.width - 20, 200 });
	//tb->setAnchorPoint(Vec2(0.5, 0.5));
	//tb->setPosition(Vec2(0, 0));
    
	tb->setDelegate(&mTableViewDelegate);
    main_scroll->addChild(tb);
    // end for
    main_layout->addChild(main_scroll);

    auto done_button = gui::CreateButton("Done");
	//done_button->setPosition(Vec2(visible_size.width / 10 + origin.x, visible_size.height / 4 + origin.y));
    done_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
    {
        if(type == ui::Widget::TouchEventType::ENDED)
            Director::getInstance()->replaceScene(StartScreenScene::create());
    });
    main_layout->addChild(done_button);
   main_layout->setPosition(Vec2{ visible_size.width / 4 + origin.x, visible_size.height / 4 + origin.y });
    this->addChild(main_layout);
    return true;
}

void TransferNewsScene::menuCloseCallback(cocos2d::Ref* sender)
{
}
}
