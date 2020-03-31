 /* *************************************************************************************************
  *
  * Code:	    sph1D
  * Purpose:	1D Smooth Particle Hydrodynamics Simulation
  * Credits:    This code was inspired by "Smoothed Particle Hydrodynamics a
  *             meshfree particle method" by G.R. Liu and M.B. Liu, 2003
  * Diclaimer:  This code has no warranty or claims of correctness whatsoever.
  *             Please e-mail me with issues & comments. Perhaps a pull request
  *             if you are so inclined.
  * Licence:
  * Cite:       Please properly cite this code and/or any portion used.
  * Author:	    Ryan Clement (RRCC)
  *             scisoft@outlook.com
  * Date:	    March 2020
  *
  ***************************************************************************************************/

// System INCLUDES
#include <iostream>
#include <new>			// Dynamic storage
#include <string>		// Strings

// SPH Code Base INCLUDES
#include "constants.h"
#include "DataOut.h"
#include "init.h"
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
    double t = 0.0;        // Time [s]
    double dt = 0.005;     // Time Step [s]
    double tMax = 0.2;     // Maximum Simulation Time [s] (Simulation stop condition)

    // Simulation Arrays
    double  x[CON::nTot]    = { 0.0 };  // Particle Position
    double  vx[CON::nTot]   = { 0.0 };  // Paricle Velocity
    double  ax[CON::nTot]   = { 0.0 };  // Particle Acceleration
    double  mass[CON::nTot] = { 0.0 };  // Mass
    double  rho[CON::nTot]  = { 0.0 };  // Density
    double  p[CON::nTot]    = { 0.0 };  // Pressure
    double  T[CON::nTot]    = { 0.0 };  // Temperature
    double  ie[CON::nTot]   = { 0.0 };  // Internal Energy
    double  te[CON::nTot]   = { 0.0 };  // Total Energy
    double  h[CON::nTot]    = { 0.0 };  // Smoothing Length
    double  ss[CON::nTot]   = { 0.0 };  // Sound Speed (normally called "c")
    double  s[CON::nTot]    = { 0.0 };  // Entropy

    // Simulation Output
    DataOut *dOut = new DataOut;

    // Initialize Problem
    init(x, vx, mass, rho, p, ie, h);
    dOut->dump(t, x, vx, mass, rho, p, ie);

    std::cout << "\tStart Time: " << t << " s" << std::endl;
    // Time Integration
    timeIntegrator(tMax, dt, t, x, vx, ax, mass, rho, p, ie, ss, s, te, h, T, dOut);
    std::cout << "\tStop Time: " << t << " s" << std::endl;
    dOut->dump(t, x, vx, mass, rho, p, ie);

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
