#pragma once

#include <Geode/modify/PlayLayer.hpp>

#include "PlayerObjectMod.cpp"

using namespace geode;

class $modify(PuffishmentPlayLayer, PlayLayer) {

	/**
	 * A hook to when a new attempt is created.
	 * Resets the player's buffer counter.
	 */
	void updateAttempts() {
		PuffishmentPlayer::get(m_player1)->m_buffers.resetAttemptClicks();
		PlayLayer::updateAttempts();
	}
};
