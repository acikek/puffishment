#include "BufferData.hpp"

bool BufferData::onUpdate(float delta) {
    accumulated += delta;
    if (accumulated >= TICK) {
        accumulated = 0.0f;
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
}

void BufferData::resetAttemptClicks() {
    attemptClicks = 0;
}
