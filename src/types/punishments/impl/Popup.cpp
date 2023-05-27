#pragma once

#include <cstdlib>
#include <ctime>

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "../Punishment.cpp"

using namespace geode::prelude;

/**
 * Punishes the player by displaying an annoying popup at random
 * if they buffer click.
 */
class PopupPunishment : public virtual Punishment {

private:
    int baseChance;
    int chance;

public:

    PopupPunishment(int baseChance) {
        std::srand(std::time(nullptr));
        this->baseChance = baseChance;
    }
    
    PopupPunishment() : PopupPunishment(getSettingsChance())
    {}
    
    std::string getNotice() {
        return "Your BufferClick Pro(R) free trial has expired. Please renew your license.";
    }

    void apply(PunishmentContext context) override {
        if (std::rand() % 100 <= chance) {
            FLAlertLayer::create("Alert", getNotice(), "OK")->show();
            chance = baseChance;
            return;
        }
        chance += 5;
    }

    bool isEnabled() override {
        return baseChance > 0;
    }

    bool isContinuous() override {
        return false;
    }

    static int getSettingsChance() {
        return Mod::get()->getSettingValue<int64_t>("popup-chance");
    }
};
