#pragma once
#include "BasicOfferScene.h"

namespace transfers
{
class ContractOfferTableViewDataSource : public BasicOfferTableViewDataSource
{
};

class ContractOfferTableViewDelegate : public BasicOfferTableViewDelegate
{
public:
    void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell) override;
};

class ContractOfferScene : public BasicOfferScene
{
public:
    bool init() override;
    static void backClicked();
};
}
