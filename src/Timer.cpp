/* *************************************************************************************************
 *
 * Class:	Timer
 * Purpose:	Time total program runtime and function calls.
 * Author:	Ryan Clement (RRCC)
 * Date:	March 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "Timer.h"


// Constructor
Timer::Timer()
{

}

// Member Function Definitions
void Timer::begin()
{
	startTime = std::chrono::system_clock::now();
	timeStampBegin = std::chrono::system_clock::to_time_t(startTime);
	sTimeStampBegin = std::ctime(&timeStampBegin);
}

std::string Timer::getTimeStampBegin()
{
	return sTimeStampBegin;
}

void Timer::end()
{
	endTime = std::chrono::system_clock::now();
	timeStampEnd = std::chrono::system_clock::to_time_t(endTime);
	sTimeStampEnd = std::ctime(&timeStampEnd);
	totalTime = (endTime - startTime);
}

std::string Timer::getTimeStampEnd()
{
	return sTimeStampEnd;
}

double Timer::getTotalProgramDuration()
{
	return totalTime.count();
}

void Timer::startTimer()
{
	start = std::chrono::system_clock::now();
}

double Timer::stopTimer()
{
	stop = std::chrono::system_clock::now();
	elapsed = (stop - start);
	return elapsed.count();	// seconds
}

// Destructor
Timer::~Timer()
{

}
