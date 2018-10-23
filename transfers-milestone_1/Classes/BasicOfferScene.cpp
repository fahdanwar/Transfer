#include "BasicOfferScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

namespace transfers
{
cocos2d::extension::TableViewCell* BasicOfferTableViewDataSource::tableCellAtIndex(
    cocos2d::extension::TableView* table, ssize_t idx)
{
    auto cell = table->dequeueCell();
	
    cell = TableViewCell::create();
    auto background_color = Color3B(255, 255, 255);
    Sprite * bg = Sprite::create();
    //bg->setAnchorPoint(Point(0, 0));
    bg->setTextureRect(Rect(0, 0, Director::getInstance()->getWinSize().width, 24));
    bg->setColor(background_color);
    bg->setTag(100);
	bg->setAnchorPoint(Vec2(0, 1));
	bg->setPosition(Vec2(200, 0));
//    cell->addChild(bg);
	auto rectNode = DrawNode::create();
	
	Vec2 rectangle[4];
	rectangle[0] = Vec2(-100, -5);//bl,br,tl,tr
	rectangle[1] = Vec2(400, -5);
	rectangle[2] = Vec2(400, 20);
	rectangle[3] = Vec2(-100, 20);

	//Color4F white(1, 1, 1, 1);
	//rectNode->drawRect(Vec2(rect.origin.x,rect.origin.y), Vec2(rect.size.height,rect.size.width), Color4F::BLACK);
	rectNode->drawPolygon(rectangle, 4, Color4F::WHITE, 1, Color4F::BLACK);
	bg->addChild(rectNode);
	
	auto label = Label::create();
    // TODO: real player name
    label->setString("Player name");
	label->setColor(Color3B::BLACK);
	
	bg->addChild(label);
//	label->setAnchorPoint(Vec2(0, 1));
	label->setPosition(130, 10);
	//label->setAlignment(cocos2d::TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
  //  cell->addChild(label);
	
	cell->addChild(bg);

    return cell;
}

ssize_t BasicOfferTableViewDataSource::numberOfCellsInTableView(cocos2d::extension::TableView* table)
{
    // TODO:
    return 10;
}
cocos2d::Size BasicOfferTableViewDataSource::tableCellSizeForIndex(cocos2d::extension::TableView* table, ssize_t idx) {
	return Size(100, 30);
}
void BasicOfferTableViewDelegate::tableCellTouched(cocos2d::extension::TableView* table,
    cocos2d::extension::TableViewCell* cell)
{
}

    cocos2d::Scene* BasicOfferScene::createScene()
{
    return Scene::create();
}

bool BasicOfferScene::init()
{
    if (!Scene::init())
        return false;

    mLayout.init();
    auto director = Director::getInstance();
    Size visible_size = director->getVisibleSize();

    TableView* tb = TableView::create(&mDataSource, Size{ visible_size.width - 100, visible_size.height - 200 });
	tb->setPosition(Vec2(100, 100));
    tb->setDelegate(&mTableDelegate);
    mLayout.addChild(tb);

    return true;
}

void BasicOfferScene::menuCloseCallback(cocos2d::Ref* sender)
{
}
}
