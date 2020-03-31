/* *************************************************************************************************
 *
 * Function:	internalForces
 * Purpose:	    Calculate internal forces for Euler Equations.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include <cmath>
#include "constants.h"
#include "gasEOS.h"


#pragma once


void internalForces(
    const double,
    const double [],
    const double [],
    const double [],
    const int,
    const double [],
    const int [],
    const int [],
    const double [],
    const double [],
    const double [],
    double [],
    double [],
    double [],
    double [],
    double []
);
