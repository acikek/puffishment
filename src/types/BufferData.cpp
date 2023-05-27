#include "BufferData.hpp"

bool BufferData::onUpdate(float delta) {
    accumulated += delta;
    if (accumulated >= TICK) {
        accumulated = 0.0f;
        if (!isBuffering) {
            offTicks++;
        }
        return true;
    }
    return false;
}

void BufferData::toggleBuffering() {
    isBuffering = !isBuffering;
}

void BufferData::addBufferClick() {
    isBuffering = true;
    sessionClicks++;
    attemptClicks++;
    offTicks = 0;
}

void BufferData::resetAttemptClicks() {
    attemptClicks = 0;
}
