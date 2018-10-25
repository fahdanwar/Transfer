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
	cell_layout->setContentSize(Size(300, 100));
	cell_layout->setBackGroundColor(Color3B::RED);
	cell_layout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
	//cell_layout->setPosition(Vec2(0, 100));
	cell_layout->setLayoutType(ui::Layout::Type::HORIZONTAL);
	auto price_label = Label::create();
	price_label->setColor(cocos2d::Color3B::BLACK);
	price_label->setPosition(Vec2(40, 80));
	price_label->setString("Price Here");
	price_label->enableBold();
	cell_layout->addChild(price_label);

    auto team_name_label = Label::create();
    team_name_label->setString("Team name here");
	team_name_label->setPosition(Vec2(120, 80));
	team_name_label->setColor(cocos2d::Color3B::BLACK);
	team_name_label->enableBold();
    cell_layout->addChild(team_name_label);

    auto buttons_layout = ui::Layout::create();
	buttons_layout->setContentSize(Size(150, 100));
    buttons_layout->setLayoutType(ui::Layout::Type::VERTICAL);
	buttons_layout->setBackGroundColor(Color3B::YELLOW);
	buttons_layout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);

	auto accept_button = gui::CreateTextButton("Accept");
	auto reject_button = gui::CreateTextButton("Reject");
    auto negotiate_button = gui::CreateTextButton("Negotiate");
    buttons_layout->addChild(accept_button);
    buttons_layout->addChild(reject_button);
    buttons_layout->addChild(negotiate_button);
	buttons_layout->setPosition(Vec2(300, 0));
	cell->addChild(buttons_layout);
	//buttons_layout->setAnchorPoint(Vec2(0, 1));
	
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
	return cocos2d::Size(300,100);
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
	main_layout->setContentSize(Size{ visible_size.width-20,visible_size.height-20 });
	main_layout->setAnchorPoint(Vec2(0, 0));
	main_layout->setPosition(Vec2(10, 10));
	main_layout->setBackGroundColor(Color3B::GRAY);
	main_layout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
 
	auto main_scroll = ui::ScrollView::create();

    main_scroll->setDirection(ui::ScrollView::Direction::VERTICAL);
    main_scroll->setContentSize(Size{ visible_size.width - 200, visible_size.height -200 });
	main_scroll->setInnerContainerSize(Size(visible_size.width - 210, visible_size.height - 210));
	main_scroll->setBackGroundColor(Color3B::WHITE);
	main_scroll->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
	//// TODO: for player in players add table view
		auto tb = TableView::create(&mDataSource, Size{ visible_size.width - 200, visible_size.height - 200 });
		tb->setDelegate(&mTableViewDelegate);
		main_scroll->addChild(tb);
	
 //   // end for
	main_layout->addChild(main_scroll);

    auto done_button = gui::CreateButton("Done");
	done_button->addTouchEventListener([](Ref* /* sender */, ui::Widget::TouchEventType type)
	 {
        if(type == ui::Widget::TouchEventType::ENDED)
            Director::getInstance()->replaceScene(StartScreenScene::create());
	   });

	
	main_layout->addChild(done_button);
	 // main_layout->setPosition(Vec2{ visible_size.width / 4 + origin.x, visible_size.height / 4 + origin.y });
	this->addChild(main_layout);
    return true;
}

void TransferNewsScene::menuCloseCallback(cocos2d::Ref* sender)
{
}
}
