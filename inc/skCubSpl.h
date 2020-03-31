/* *************************************************************************************************
 *
 * Function:	skCubSpl
 * Purpose:	    Cubic Spline Smoothing Kernel (W4? Monaghan 1985).
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include <cmath>


#pragma once


void skCubSpl(
    const double,
    const double,
    const double,
    double &,
    double &
);
