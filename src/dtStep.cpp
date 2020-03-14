/* *************************************************************************************************
 *
 * Function:	dtStep
 * Purpose:	    Integrate equations one time step.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 12, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "dtStep.h"
    

void dtStep(
    // IN
    const double dt,
    Arrays &sA )
{
    // Calculate Neighboring Particles
    symFind(sA);

}
