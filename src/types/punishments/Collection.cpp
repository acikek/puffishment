#pragma once

#include <Geode/Geode.hpp>

#include "Punishment.cpp"
#include "impl/Boost.cpp"
#include "impl/Popup.cpp"

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
    }

    /**
     * Iterates through all punishments and applies
     * their effects to the player if enabled.
     * 
     * @param[in] context the application context
     */
    void apply(PunishmentContext context) {
        for (auto const& p : this->list) {
            if (p->isEnabled()) {
                p->apply(context);
            }
        }
    }
};
