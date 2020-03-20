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
    Arrays &sA )
{
    // Calculate Neighboring Particles
    symFind(sA);

    // Density Approximation
    sumDen(sA);

    // Artificial Viscosity
    artVisc(axAV,dieAV,sA);

    // Convert Velocity, Force, and Energy to f and df/dt
    // ... add components from updates above
    for(auto i=0; i<sA.nTot; i++)
    {
        sA.ax[i] = axAV[i];
        sA.die[i] += dieAV[i];
    }
}
