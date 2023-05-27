/**
 * Holds the buffer state of a player.
 */
class BufferData {

public:
    /// Whether the player is currently performing a buffer hold
	bool isBuffering = false;
	/// The amount of buffer clicks the player has performed in the current session
	unsigned int sessionClicks = 0;
	/// The amount of buffer clicks the player has performed during the current attempt
	unsigned int attemptClicks = 0;

    /**
     * Sets the 'isBuffering' value to its opposite.
     */
    void toggleBuffering() {
        isBuffering = !isBuffering;
    }

	/**
	 * Increments the buffer click counters by one.
	 */
	void addBufferClick() {
		sessionClicks++;
		attemptClicks++;
	}

    /**
     * Resets the attempt click counter to zero.
     * Should be called when the attempt ends.
     */
    void resetAttemptClicks() {
        attemptClicks = 0;
    }
};
