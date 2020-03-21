/* *************************************************************************************************
 *
 * Function:	dtStep
 * Purpose:	    Integrate equations one time step.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include "Arrays.h"
#include "artVisc.h"
#include "internalForces.h"
#include "sumDen.h"
#include "symFind.h"

// PRAGMA
#pragma once


void dtStep(
    const double,
    double [],
    double [],
    double [],
    Arrays &
);
