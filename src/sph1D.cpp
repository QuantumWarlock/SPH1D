 /* *************************************************************************************************
  *
  * Code:	    sph1D
  * Purpose:	1D Smooth Particle Hydrodynamics Simulation
  * Author:	    Ryan Clement (RRCC)
  * Date:	    March 10, 2020
  *
  ***************************************************************************************************/

// System INCLUDES
#include <cmath>		// C-library math functions
#include <iomanip>		// Parametric manipulators (formatting)
#include <iostream>		// Input/Output (streams)
#include <new>			// Dynamic storage
#include <string>		// Strings

// SPH Code Base INCLUDES
#include "Arrays.h"
#include "DataOut.h"
#include "init.h"
#include "gasEOS.h"
#include "SPH1DConfig.h"
#include "symFind.h"
#include "timeIntegrator.h"
#include "Timer.h"
#include "waterEOS.h"

// NAMESPACES

// MAIN
int main() 
{
    // BEGIN: Timing
    double timeElapsed;
    Timer *timer = new Timer;
    timer->begin();
    std::cout << "\nSPH1D BEGIN: " << timer->getTimeStampBegin() << std::endl;

    
    // Time Parameters
    double t = 0.0;                 // Time
    double dt = 0.0;                // Time Step
    double tMax = 0.0;              // Maximum Simulation Time (Simulation stop condition)
    
    // Simulation Arrays
    Arrays simArr;

    // Simulation Output
    DataOut *dOut = new DataOut;

    // Initialize Problem
    init(simArr);
    dOut->dump(t,simArr);
    
    // Time Integration
    timeIntegrator(tMax,dt,simArr);

	// Final Time Stamp
	timer->end();
	std::cout << "\n\nSPH1D END: " << timer->getTimeStampEnd();
	// Total Run Time
	timeElapsed = timer->getTotalProgramDuration();
	std::cout << "SPH1D Total Elapsed Time: " << timeElapsed << " s\n" << std::endl;

    // Clean-up
    delete dOut;
    delete timer;

    // Success
    return 0;
} // END: MAIN
