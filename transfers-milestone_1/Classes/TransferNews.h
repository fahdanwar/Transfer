#pragma once

#include <cocos2d.h>
#include "UiUtils.h"

namespace transfers
{
class TransferNewsTableViewDataSource : public cocos2d::extension::TableViewDataSource
{
public:
    cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView* table, ssize_t idx) override;
    ssize_t numberOfCellsInTableView(cocos2d::extension::TableView* table) override;
	cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView* table, ssize_t idx) override;
};

class TransferNewsTableViewDelegate : public cocos2d::extension::TableViewDelegate
{
public:
    void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell) override;
};

class TransferNewsScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* sender);
    CREATE_FUNC(TransferNewsScene);
private:
    // TODO: Maybe vector of sources
    TransferNewsTableViewDataSource mDataSource;
    TransferNewsTableViewDelegate mTableViewDelegate;
};
} // namespace transfers
