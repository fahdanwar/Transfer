#pragma once
#include <cocos2d.h>
#include "GUI/CCScrollView/CCTableView.h"
#include "UiUtils.h"

namespace transfers
{
class BasicOfferTableViewDataSource : public cocos2d::extension::TableViewDataSource
{
public:
    cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView* table, ssize_t idx) override;
    ssize_t numberOfCellsInTableView(cocos2d::extension::TableView* table) override;
	cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView* table, ssize_t idx) override;
};

class BasicOfferTableViewDelegate : public cocos2d::extension::TableViewDelegate
{
public:
    void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell) override;
};

class BasicOfferScene : public cocos2d::Scene
{
public:
    BasicOfferScene() : mLayout(this)
    {
    }

    static cocos2d::Scene* createScene();
    bool init() override;
    void menuCloseCallback(cocos2d::Ref* sender);
    //CREATE_FUNC(BasicOfferScene);

protected:
    gui::VerticalLayoutWithButtons mLayout;
    BasicOfferTableViewDataSource mDataSource;
    BasicOfferTableViewDelegate mTableDelegate;
};
} // namespace transfers