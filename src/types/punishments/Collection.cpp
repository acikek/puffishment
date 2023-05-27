#pragma once

#include <Geode/Geode.hpp>

#include "Punishment.cpp"
#include "impl/Boost.cpp"
#include "impl/Popup.cpp"
#include "impl/Ding.cpp"

/**
 * A collection of all punishments that should
 * apply to a player while buffering.
 */
class Punishments {

private:

    /// The list of punishments to apply.
    std::vector<std::unique_ptr<Punishment>> list;

public:
    
    /**
     * Initializes all punishments by reading from
     * the mod settings.
     * 
     * Ideal when creating a player instance and
     * therefore starting a session.
     */
    Punishments() {
        list.push_back(std::unique_ptr<Punishment>(new BoostPunishment()));
        list.push_back(std::unique_ptr<Punishment>(new PopupPunishment()));
        list.push_back(std::unique_ptr<Punishment>(new DingPunishment()));
    }

    /**
     * Iterates through all punishments and applies
     * their effects to the player if enabled.
     * 
     * @param[in] context the application context
     * @param[in] hold whether the player is buffer holding as opposed to clicking
     */
    void apply(PunishmentContext context, bool hold) {
        for (auto const& p : this->list) {
            if (p->isEnabled() && (!hold || p->isContinuous())) {
                p->apply(context);
            }
        }
    }

    /**
     * Iterates through all punishments and calls their
     * 'afterBuffer' callbacks if the off tick amount is in range.
     * 
     * @param[in] context the application context
     * @param[in] offTicks the amount of ticks since the last hold
     */
    void afterBuffer(PunishmentContext context, unsigned int offTicks) {
        for (auto const& p : this->list) {
            if (p->isEnabled() && offTicks <= p->maxOffTicks()) {
                p->afterBuffer(context, offTicks);
            }
        }
    }
};
