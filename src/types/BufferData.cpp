#include "BufferData.hpp"

void BufferData::toggleBuffering() {
    isBuffering = !isBuffering;
}

void BufferData::addBufferClick() {
    sessionClicks++;
    attemptClicks++;
}

void BufferData::resetAttemptClicks() {
    attemptClicks = 0;
}
