/* *************************************************************************************************
 *
 * Function:	dtStep
 * Purpose:	    Integrate equations one time step.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include "artVisc.h"
#include "constants.h"
#include "internalForces.h"
#include "sumDen.h"
#include "symFind.h"


// PRAGMA
#pragma once


void dtStep(
    const int,
    const double,
    const double [],
    const double [],
    const double [],
    const double [],
    const double [],
    double [],
    double [],
    double [],
    double [],
    double [],
    double [],
    double [],
    int [],
    int [],
    int [],
    double [],
    double [],
    double [],
    double [],
    double []
);
