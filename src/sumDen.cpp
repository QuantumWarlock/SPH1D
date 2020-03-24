/* *************************************************************************************************
 *
 * Function:	sumDen
 * Purpose:	    Summation Density Approach.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include "sumDen.h"


void sumDen(
    const double h[],
    const double mass[],
    const int nIP,
    const int iIP[],
    const int jIP[],
    const double w[],
    double rho[]
    )
{
    int i = 0;
    int j = 0;
    double r0 = 0.0;
    double w0 = 0.0;
    double dw0 = 0.0;


    // Density Integration
    for(auto k=0; k<CON::nTot; k++)
    {
        kernel(r0, dw0, h[k], w0, dw0);
        rho[k] = w0*mass[k];
    }

    // SPH Sum for Density
    for(auto k=0; k<nIP; k++)
    {
        i = iIP[k];
        j = jIP[k];
        rho[i] += mass[j]*w[k];
        rho[j] += mass[i]*w[k];
    }
}
