 /* *************************************************************************************************
  *
  * Code:	    sph1D
  * Purpose:	1D Smooth Particle Hydrodynamics Simulation
  * Credits:    This C++ based code is derived from the FORTRAN in "Smoothed Particle Hydrodynamics a
  *             meshfree particle method" by G.R. Liu and M.B. Liu, 2003
  * Diclaimer:  This code has no warranty or claims of correctness whatsoever.
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
#include "SPH1DConfig.h"
#include "timeIntegrator.h"
#include "Timer.h"

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
    double t = 0.0;                 // Time [s]
    double dt = 0.005;              // Time Step [s]
    double tMax = 0.20;             // Maximum Simulation Time [s] (Simulation stop condition)

    // Simulation Arrays
    Arrays simArr;

    // Simulation Output
    DataOut *dOut = new DataOut;

    // Initialize Problem
    init(simArr);
    dOut->dump(t,simArr);

    std::cout << "\tStart Time: " << t << " s" << std::endl;
    // Time Integration
    timeIntegrator(tMax,dt,t,simArr);
    std::cout << "\tStop Time: " << t << " s" << std::endl;
    dOut->dump(t,simArr);

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
