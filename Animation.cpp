#include "Animation.hpp"

/**
 * @brief Set animation state to ANIMATION_START
*/
void Animation::start(void) {
	this->animation_state = ANIMATION_START;
}

/**
 * @brief Set animation state to ANIMATION_STOPPED
*/
void Animation::stop(void) {
	this->animation_state = ANIMATION_STOPPED;
}

/**
 * @brief Set animation state to ANIMATION_PAUSED
*/
void Animation::pause(void) {
	this->animation_state = ANIMATION_PAUSED;
}

/**
 * @brief Set animation state to ANIMATION_RUNNING
*/
void Animation::resume(void) {
	this->animation_state = ANIMATION_RUNNING;
}

/**
 * @brief Set animation state to ANIMATION_ENDED
*/
void Animation::end(void) {
	this->animation_state = ANIMATION_ENDED;
}

/**
 * @brief Returns the actual animation state
 * @retval Animation_State type
*/
Animation_State Animation::get_state(void){
	return this->animation_state;
}

/**
 * @brief Run associated methods to animation state
*/
void Animation::worker(void) {
	switch (this->animation_state) {
	case ANIMATION_START:
		this->reset();
		this->animation_state = ANIMATION_RUNNING;
	case ANIMATION_RUNNING:
		this->run();
		break;

	case ANIMATION_STOPPED:
		this->pause();
		this->reset();
		break;

	case ANIMATION_PAUSED:
		// Do nothing
		break;

	case ANIMATION_ENDED:
		// Do nothing
		break;
	}
}
