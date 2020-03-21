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

    // Array Size Parameters
    constexpr int maxIP = 100;
    constexpr int nTot = 400;
    constexpr int maxSZ = maxIP*nTot;

    // Simulation Arrays
    int     iIP[maxSZ] = { 0 };
    int     jIP[maxSZ] = { 0 };
    int     nNP[nTot] = { 0 };
    double  w[maxSZ] = { 0.0 };          // Smoothing Function
    double  dw[maxSZ] = { 0.0 };         // Soothing Function Derivative
    double  x[nTot] = { 0.0 };           // Particle Position
    double  vx[nTot] = { 0.0 };          // Paricle Velocity
    double  ax[nTot] = { 0.0 };          // Particle Acceleration
    double  mass[nTot] = { 0.0 };        // Mass
    double  rho[nTot] = { 0.0 };         // Density
    double  drho[nTot] = { 0.0 };        // d[rho]/dt
    double  p[nTot] = { 0.0 };           // Pressure
    double  T[nTot] = { 0.0 };           // Temperature
    double  ie[nTot] = { 0.0 };          // Internal Energy
    double  die[nTot] = { 0.0 };         // d[ie]/dt
    double  te[nTot] = { 0.0 };          // Total Energy
    double  h[nTot] = { 0.0 };           // Smoothing Length
    double  ss[nTot] = { 0.0 };          // Sound Speed (normally called "c")

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
