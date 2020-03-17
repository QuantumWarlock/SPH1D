/* *************************************************************************************************
 *
 * Function:	kernel
 * Purpose:	    AKA Smoothing Function.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 16, 2020
 *
 ***************************************************************************************************/


 // INCLUDE
#include "kernel.h"


void kernel(
    const double r,
    const double dx,
    const double hM,
    double &w,
    double &dw )
{
    const double factor = 1.0/(hM*CON::sqrtPi);
    const double q = r/hM;
    w = 0.0;
    dw = 0.0;
    if ( (q > 0.0) && (q <= 3.0) )
    {
        w = factor*exp(-q*q);
        dw = -2.0*q*w;
    }
    else
    {
        w = 0.0;
        dw = 0.0;
    }
}
