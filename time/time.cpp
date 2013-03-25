#include "time.h"

//Constructor
GlobalTime::GlobalTime()
{
	std::cout <<"[Starting Global Timer]"<<std::endl;
	
	start = new timeval;
	end = new timeval;
	//Set startTime 
	startTime=SDL_GetTicks();
	
	//set number of frames to 0
	frames=0;
}

long GlobalTime::getFrames()
{
	return frames;
}

//Start a Frame
void GlobalTime::startFrame()
{
	//Set frame start time
	frameStartTime=SDL_GetTicks();
	gettimeofday(start, NULL);
	//Increment number of frames
	frames++;
}

//Calculate time values after frame ends
void GlobalTime::calcDelta()
{
	//Calculate time per frame
	frameTime=SDL_GetTicks()-frameStartTime;
	
	
	gettimeofday(end, NULL);
	
	
	
	
	//Convert to seconds
	//frameSec=((double)frameTime)*0.001f;
	frameSec=((((long double)end->tv_usec))-((long double)start->tv_usec))*0.000001f;
	if(frameSec<0)frameSec = ((long double)(1000000-start->tv_usec)+(long double)end->tv_usec)*0.000001f;

	//frameSec=(((((long double)end->tv_usec)+(long double)end->tv_sec*1000000.0f))-(((long double)start->tv_usec)+(long double)start->tv_sec*1000000.0f))*0.000001f;
	
	//Calculate FPS
	if(frameSec)
		fps=1.0f/frameSec;
}

long GlobalTime::getSeconds()
{
	timeval *current = new timeval;
	gettimeofday(current, NULL);
	return current->tv_sec;
	delete current;
}

//Destructor
GlobalTime::~GlobalTime()
{
	delete start;
	delete end;
	//Output average FPS
	std::cout<<"[Ending Global Timer] ["<<1000*(((float)frames)/(float)(SDL_GetTicks()-startTime))<<" FPS]"<<std::endl;
}
