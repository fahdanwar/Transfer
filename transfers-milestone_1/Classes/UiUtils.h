#pragma once
#include <cocos2d.h>
#include "cocos-ext.h"
#include <ui/UILayout.h>

#include <functional>

namespace transfers
{
namespace gui
{
/**
 * @brief CreateButton Helper for buttons creating
 * @param text button label
 * @return pointer to cocos2d::Button created
 */
inline cocos2d::ui::Button* CreateButton(const std::string& text)
{
	auto button = cocos2d::ui::Button::create("button.png", "button_selected.png" );
    button->setScale(1.5f);
	button->setTitleFontSize(14.0f);
    button->setTitleText(text);
    return button;
}

/**
* @brief CreateTextButton Helper for buttons text button creating
* @param text button label
* @return pointer to cocos2d::Button created
*/
inline cocos2d::ui::Button* CreateTextButton(const std::string& text)
{
	auto button = cocos2d::ui::Button::create();
	// button->setScale(1.5f);
	button->setTitleFontSize(14.0f);
	button->setTitleColor(cocos2d::Color3B::BLACK);
	button->setTitleText(text);
	return button;
}



/**
 * @brief Helper for building buttons with vertical layout
 */
class VerticalLayoutWithButtons
{
public:
    VerticalLayoutWithButtons(cocos2d::Scene* scene) : scene(scene), layout(nullptr)
    {
    }

    ~VerticalLayoutWithButtons()= default;

    void init()
    {
        auto visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        layout = cocos2d::ui::Layout::create();
		layout->setLayoutType(cocos2d::ui::Layout::Type::VERTICAL);
		scene->addChild(layout);
    }

    /**
    * @brief addButtons Add button to vertical layout.
    * @param btn Button pointer
    * @param touch_callback Button press callback
    */
   void addButton(cocos2d::ui::Button* btn, std::function< void() > touch_callback)
   {
       btn->addTouchEventListener([touch_callback](cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type)
       {
           switch (type)
           {
           case cocos2d::ui::Widget::TouchEventType::ENDED:
               touch_callback();
               break;
           default:
               break;
           }
       });

       layout->addChild(btn);
   }

   void addChild(cocos2d::Node* child)
   {
       layout->addChild(child);
   }

   void setPosition(const cocos2d::Vec2& pos) { layout->setPosition(pos); }

private:
    // TODO: press events
    cocos2d::ui::Layout* layout;
    cocos2d::Scene* scene;
};
} // namespace gui
} // namespace transfers
