/* *************************************************************************************************
 *
 * Function:	timeIntegrator
 * Purpose:	    Advance the simulation in time.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 12, 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "timeIntegrator.h"


void timeIntegrator(
    const double tMax,
    double dt,
    Arrays &sA)
    {
        dtStep(dt,sA);
    }