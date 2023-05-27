#pragma once

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "../Punishment.cpp"

using namespace geode::prelude;

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
        if (context.buffers->isBuffering) {
            return;
        }
        log::info("bruh");
        GameSoundManager::sharedManager()->playEffect("ding.ogg"_spr, 1, 1, 1);
    }

    bool isEnabled() override {
        return enabled;
    }

    static bool getSettingsEnabled() {
        return Mod::get()->getSettingValue<bool>("ding");
    }
};
