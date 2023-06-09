#ifndef BUFFERDATA_H
#define BUFFERDATA_H

/**
 * Holds the buffer state of a player.
 */
class BufferData {

private:
    static constexpr float TICK = 0.25f;
    float accumulated = 0.0f;

public:
    /// Whether the player is currently performing a buffer hold
	bool isBuffering = false;
	/// The amount of buffer clicks the player has performed in the current session
	unsigned int sessionClicks = 0;
	/// The amount of buffer clicks the player has performed during the current attempt
	unsigned int attemptClicks = 0;
    /// The amount of buffer ticks since the end of the last buffer hold
    unsigned int offTicks = 0;

    /**
     * Should be called each update frame.
     * @return whether this frame is a buffer tick
     */
    bool onUpdate(float delta);

    /**
     * Sets the 'isBuffering' value to its opposite.
     */
    void toggleBuffering();

	/**
	 * Increments the buffer click counters by one.
	 */
	void addBufferClick();

    /**
     * Resets the attempt click counter to zero.
     * Should be called when the attempt ends.
     */
    void resetAttemptClicks();
};

#endif
