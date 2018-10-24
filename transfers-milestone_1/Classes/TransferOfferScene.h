#pragma once
#include "BasicOfferScene.h"

namespace transfers
{
class TransferOfferTableViewDataSource : public BasicOfferTableViewDataSource
{
};

class TransferOfferTableViewDelegate : public BasicOfferTableViewDelegate
{
public:
    void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell) override;
};

class TransferOfferScene : public BasicOfferScene
{
public:
    bool init() override;
	CREATE_FUNC(TransferOfferScene);
    static void backClicked();
};

}
