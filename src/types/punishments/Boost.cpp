#pragma once

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "Punishment.cpp"

using namespace geode;

/**
 * Punishes the player by offsetting their position to the right
 * by a set distance per frame.
 */
class BoostPunishment : public virtual Punishment {

private:
    float offset;

public:

    static constexpr float MULTIPLIER = 10.0f;

    BoostPunishment(float offset) {
        this->offset = offset;
    }

    BoostPunishment() : offset(getSettingsOffset())
    {}

    float getOffset(float delta) {
        return this->offset * delta * MULTIPLIER;
    }

    void apply(PunishmentContext context) override {
        context.player->setPositionX(context.player->getPositionX() + getOffset(context.delta));
    }

    bool isEnabled() override {
        return this->offset > 0.0f;
    }

    static float getSettingsOffset() {
        return Mod::get()->getSettingValue<double>("boost-strength");
    }
};
