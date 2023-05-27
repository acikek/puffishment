#pragma once

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "../Punishment.cpp"

using namespace geode::prelude;

/**
 * Punishes the player by playing a 'ding' sound for each buffer click.
 */
class DingPunishment : public virtual Punishment {

private:
    bool enabled;

public:

    DingPunishment(bool enabled) {
        this->enabled = enabled;
    }

    DingPunishment() : enabled(getSettingsEnabled())
    {}

    void apply(PunishmentContext context) override {
        GameSoundManager::sharedManager()->playEffect("ding.ogg"_spr, 1, 1, 1);
    }

    bool isEnabled() override {
        return enabled;
    }

    bool isContinuous() override {
        return false;
    }

    static bool getSettingsEnabled() {
        return Mod::get()->getSettingValue<bool>("ding");
    }
};
