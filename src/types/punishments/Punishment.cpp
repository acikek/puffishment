#pragma once

#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>

#include "../BufferData.cpp"

/**
 * A context structure to be passed into 'Punishment' functions.
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
     * 
     * @param[in] context the application context
     */
    virtual void apply(PunishmentContext context) = 0;

    /**
     * @return whether the punishment would be able to apply to the player
     */
    virtual bool isEnabled() = 0;

    /**
     * @return whether the punishment should be applied each buffer tick
     */
    virtual bool isContinuous() = 0;
};
