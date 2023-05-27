#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

#include "../types/punishments/Collection.cpp"

using namespace geode::prelude;

class $modify(PuffishmentPlayer, PlayerObject) {

	/// The buffer state tracker.
	BufferData m_buffers = BufferData();
	/// The punishment container.
	Punishments m_punishments = Punishments();
	
	/**
	 * @return whether the player's current state permits buffer clicking
	 */
	bool canBuffer() {
		return !(m_isDashing || m_isShip || m_isDart || m_isSpider);
	}

	/**
	 * @return punishment context created from the player's update state
	 */
	PunishmentContext getContext(float delta) {
		return PunishmentContext { 
			.player = this, 
			.buffers = &m_fields->m_buffers,
			.delta = delta
		};
	}

	/**
	 * Called each frame the player is buffering.
	 * 
	 * May punish the player in some way dependent on the 'Punishments' container.
	 * Then, if this is the first frame the player has been buffering, increments the counters.
	 */
	void onBuffering(float delta) {
		m_fields->m_punishments.apply(getContext(delta));

		if (m_fields->m_buffers.isBuffering)
			return;

		m_fields->m_buffers.isBuffering = true;
		m_fields->m_buffers.addBufferClick();
	}

	/**
	 * Resets the 'm_isBuffering' field to false if necessary.
	 */
	void onBufferEnd() {
		if (m_fields->m_buffers.isBuffering)
			m_fields->m_buffers.toggleBuffering();
	}

	/**
	 * A hook to the update call that checks if the player is currently buffering
	 * and punishes the player if so.
 	 */
	void update(float delta) {
		if (this->canBuffer() && m_hasJustHeld)
			this->onBuffering(delta);
		else
			this->onBufferEnd();

		return PlayerObject::update(delta);
	}

	/**
	 * Retrieves a Puffishment player instance from a player object.
	 * @param[in] player the player object to cast
	 */
	static PuffishmentPlayer* get(PlayerObject* player) {
		return static_cast<PuffishmentPlayer*>(player);
	}
};
