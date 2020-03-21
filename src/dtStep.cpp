/* *************************************************************************************************
 *
 * Function:	dtStep
 * Purpose:	    Integrate equations one time step.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include "dtStep.h"


void dtStep(
    // IN
    const double dt,
    double axAV[],
    double dieAV[],
    double axIF[],
    Arrays &sA )
{
    const int nTot = sA.nTot;

    for(auto i=0; i<nTot; i++)
    {
        dieAV[i] = 0.0;
        axAV[i] = 0.0;
        axIF[i] = 0.0;
    }

    // Calculate Neighboring Particles
    symFind(sA);

    // Density Approximation
    sumDen(sA);

    // Internal Forces
    internalForces(axIF,sA);

    // Artificial Viscosity
    artVisc(axAV,dieAV,sA);

    // Convert Velocity, Force, and Energy to f and df/dt
    // ... add components from updates above
    for(auto i=0; i<nTot; i++)
    {
        sA.ax[i] = axAV[i] + axIF[i];
        sA.die[i] += dieAV[i];
    }
}
