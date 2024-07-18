#pragma once

#include <Geode/c++stl/gdstdlib.hpp>
#include <Geode/cocos/base_nodes/CCNode.h>
#include <Geode/cocos/cocoa/CCObject.h>
#include <functional>
#include "../../../include/index.hpp"

using namespace geode::prelude;

namespace jukebox {

class IndexesPopup;

class IndexCell : public CCNode {
protected:
    IndexesPopup* m_parentPopup;
    IndexSource* m_index;
    std::function<void()> m_onDelete;

    CCMenuItemToggler* m_toggleButton;

    bool init(
        IndexesPopup* parentPopup,
        IndexSource* index,
        std::function<void()> onDelete,
        CCSize const& size
    );
public:
    static IndexCell* create(
        IndexesPopup* parentPopup,
        IndexSource* index,
        std::function<void()> onDelete,
        CCSize const& size
    );
    void updateUI();
    void onToggle(CCObject*);
    void onDelete(CCObject*);
};

}
