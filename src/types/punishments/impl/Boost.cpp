#pragma once

#include <math.h>

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

    static void movePlayer(PunishmentContext context, float offset) {
        context.player->setPositionX(context.player->getPositionX() + offset);
    }

    void apply(PunishmentContext context) override {
        movePlayer(context, this->offset);
    }

    unsigned int maxOffTicks() override {
        return 120;
    }

    float easeOffset(unsigned int offTicks) {
        float t = (float) offTicks / maxOffTicks();
        float eased = 1.0f - std::pow(1.0f - t, 3);
        return offset - (eased * offset);
    }

    void afterBuffer(PunishmentContext context, unsigned int offTicks) override {
        movePlayer(context, easeOffset(offTicks));
    }

    bool isEnabled() override {
        return this->offset > 0.0f;
    }

    bool isContinuous() override {
        return true;
    }

    static float getSettingsOffset() {
        return Mod::get()->getSettingValue<double>("boost-strength");
    }
};
