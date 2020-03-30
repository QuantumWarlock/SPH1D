/* *************************************************************************************************
 *
 * Function:	skCubSpl
 * Purpose:	    Cubic Spline Smoothing Kernel (W4? Monaghan 1985).
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


 // INCLUDE
#include "skCUBSPL.h"


void skCubSpl(
    const double r,
    const double dx,
    const double hM,
    double &w,
    double &dw )
{
    const double q = r/hM;
    const double factor = 1.0/hM;
    if( (q >= 0.0) && (q <= 1.0) )
    {
        w = factor*( (2.0/3.0) - (q*q) + (q*q*q/2.0) );
        dw = factor*dx*( (3.0*q/2.0) - 2.0 )/(hM*hM);
    }
    else if( (q > 1.0) && (q <= 2.0) )
    {
        w = factor*pow( (2.0 - q), 3.0 )/6.0;
        dw = -factor*dx*pow( (2.0 - q), 2.0 )/(2.0*q*hM*hM);
    }
    else
    {
        w = 0.0;
        dw = 0.0;
    }
}
