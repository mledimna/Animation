#ifndef ANIMATION_ANIMATION_HPP_
#define ANIMATION_ANIMATION_HPP_


#ifdef __cplusplus
extern "C"{
#endif

typedef enum{
	ANIMATION_START,
	ANIMATION_RUNNING,
	ANIMATION_STOPPED,
	ANIMATION_PAUSED,
	ANIMATION_ENDED,
}Animation_State;

typedef enum{
	EXECUTED,
	NOT_EXECUTED,
}Execution_State;

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

class Animation{
public:
	Animation(){
		this->stop();
	}

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);
	void end(void);
	void worker(void);
	Animation_State get_state(void);

protected:
	virtual void run(void)=0;
	virtual void reset(void)=0;

private:
	Animation_State animation_state = ANIMATION_STOPPED;
};

#endif

#endif /* ANIMATION_ANIMATION_HPP_ */
