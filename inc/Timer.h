/* *************************************************************************************************
 *
 * Class:	Timer
 * Purpose:	Time total program runtime and function calls.
 * Author:	Ryan Clement (RRCC)
 * Date:	March 10, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include <iostream>
#include <ctime>
#include <chrono>   // Sets high_resolution_clock to system_clock
#include <string>
    

// PRAGMA
#pragma once  

    
class Timer {
private:
	// Begining and ending system times (time stamps)
	std::string sTimeStampBegin, sTimeStampEnd;
	time_t timeStampBegin, timeStampEnd;
	// High resolution total program execution time
	std::chrono::system_clock::time_point startTime, endTime;
	std::chrono::duration<double> totalTime;
	// High resolution sub-program exection timers
	std::chrono::system_clock::time_point start, stop;
	std::chrono::duration<double> elapsed;

public:
	// Constructor
	Timer();

	// Member Function Declarations
	void begin();
	void end();
	std::string getTimeStampBegin();
	std::string getTimeStampEnd();
	double getTotalProgramDuration();
	void startTimer();
	double stopTimer();

	// Destructor
	~Timer();
};
    

