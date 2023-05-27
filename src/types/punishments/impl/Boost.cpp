#pragma once

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "../Punishment.cpp"

using namespace geode::prelude;

/**
 * Punishes the player by offsetting their position to the right
 * by a set distance per frame.
 */
class BoostPunishment : public virtual Punishment {

private:
    float offset;

public:

    BoostPunishment(float offset) {
        this->offset = offset;
    }

    BoostPunishment() : offset(getSettingsOffset())
    {}

    void apply(PunishmentContext context) override {
        context.player->setPositionX(context.player->getPositionX() + this->offset);
    }

    bool isEnabled() override {
        return this->offset > 0.0f;
    }

    static float getSettingsOffset() {
        return Mod::get()->getSettingValue<double>("boost-strength");
    }
};
