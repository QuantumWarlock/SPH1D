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
#include "DataOut.h"
#include "init.h"
#include "gasEOS.h"
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
    Timer timer;
    timer.begin();
    std::cout << "\nSPH1D BEGIN: " << timer.getTimeStampBegin() << std::endl;

    
    // Initial Parameters
    const int nTot = 400;           // Total Number of Particles
    double t = 0.0;                 // Time
    double dt = 0.0;                // Time Step
    double tMax = 0.0;              // Maximum Simulation Time (Simulation stop condition)
    double x[nTot] = {0};           // Particle Position
    double vx[nTot] = {0};          // Paricle Velocity
    double mass[nTot] = {0};        // Mass
    double rho[nTot] = {0};         // Density
    double p[nTot] = {0};           // Pressure
    double ie[nTot] = {0};          // Internal Energy
    double h[nTot] = {0};           // Smoothing Length
    double ss[nTot] = {0};          // Sound Speed (normally called "c")
    double s[nTot] = {0};           // Entropy
    double te[nTot] = {0};          // Total Energy

    // Simulation Output
    DataOut *dOut = new DataOut;


    // Initialize Problem
    init(x,vx,mass,rho,p,ie,h,nTot);
    dOut->dump(t,x,vx,mass,rho,p,ie,nTot);
    
    // Time Integration
    timeIntegrator(x,vx,mass,rho,p,ie,ss,s,te,h,nTot,tMax,dt);




    // Clean-up
    delete dOut;

    // END: Timing
	// Final Time Stamp
	timer.end();
	std::cout << "\n\nSPH1D END: " << timer.getTimeStampEnd();
	// Total Run Time
	timeElapsed = timer.getTotalProgramDuration();
	std::cout << "SPH1D Total Elapsed Time: " << timeElapsed << " s\n" << std::endl;


    // Success
    return 0;
} // END: MAIN
