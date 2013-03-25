#include "../res.h"
#include "../mm/singleton.h"
#ifndef GLOBALTIME_H
#define GLOBALTIME_H

//Global Time Class (singleton)
class GlobalTime : public Singleton<GlobalTime>
{
	private:
	
	//# of Frames
	unsigned long frames;
	
	//Start Time of Engine
	long startTime;
	
	//Start Time of Frame
	long frameStartTime;
	
	//Time Variables
	timeval *start;
	timeval *end;
	
	public:
	//Time per frame (ms)
	long frameTime;
	
	//Time per frame (s)
	long double frameSec;
	
	//Frames per second
	double fps;
	
	//Constructor
	GlobalTime();
	
	//Destructor
	~GlobalTime();
	
	long getFrames();
	
	//Return current time in seconds
	long getSeconds();
	
	//Start a frame (as in graphics)
	void startFrame();
	
	//Calculate the time per frame
	void calcDelta();
};

#endif
