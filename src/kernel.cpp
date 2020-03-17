/* *************************************************************************************************
 *
 * Function:	kernel
 * Purpose:	    AKA Smoothing Function.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


 // INCLUDE
#include "kernel.h"


void kernel(
    const double r,
    const double hM,
    double &w,
    double &dw )
{
    const double factor = 1.0/(hM*CON::sqrtPi);
    const double q = r/hM;
    const double qMin = 1.0e-9;

    if ( (q > qMin) && (q <= 3.0) )   // NOTE: May adjust 1.0e-9 to be smaller in the future.
    {
        w = factor*exp(-q*q);
        dw = -2.0*q*w;
    }
    else if ( q <= qMin )
    {
        w = factor;
        dw = -2.0*q*factor;
    }
    else
    {
        w = 0.0;
        dw = 0.0;
    }
}
