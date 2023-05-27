#pragma once

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "../BufferData.cpp"

/**
 * 
 */
struct PunishmentContext {
    PlayerObject* player;
    BufferData* buffers;
    float delta;
};

/**
 * An object that can apply negative effects to the player
 * while they are buffering.
 */
class Punishment {

public:
    /**
     * Applies a negative effect to the specified player.
     * This is called each frame the player is buffering.
     * 
     * @param[in] player the player to act on
     * @param[in] delta the tick delta
     */
    virtual void apply(PunishmentContext context) = 0;

    /**
     * @return whether the punishment would be able to apply to the player
     */
    virtual bool isEnabled() = 0;
};
