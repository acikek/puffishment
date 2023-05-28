#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/EndLevelLayer.hpp>

using namespace geode::prelude;

class $modify(PuffishmentEndLayer, EndLevelLayer) {

    bool init(const char* title, float height) {
        auto winSize = CCDirector::get()->getWinSize();
        auto label = cocos2d::CCLabelBMFont::create("abcd", "bigFont.fnt");
        label->setPosition(winSize / 2);
        this->m_listLayer->addChild(label);

        EndLevelLayer::init(title, height);
    }
};
