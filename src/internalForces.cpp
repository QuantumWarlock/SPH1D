/* *************************************************************************************************
 *
 * Function:	internalForces
 * Purpose:	    Calculate internal forces for Euler Equations.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "internalForces.h"


void internalForces(
    const double dt,
    const double h[],
    const double mass[],
    const double vx[],
    const int nIP,
    const double rho[],
    const int iIP[],
    const int jIP[],
    const double dw[],
    const double ie[],
    const double x[],
    double T[],
    double ss[],
    double p[],
    double axIF[],
    double die[]
    )
{
    int i = 0;
    int j = 0;
    double H = 0.0;
    double He = 0.0;

    // Initialize: Acceleration, d[ie]/dt
    for(auto k=0; k<CON::nTot; k++)
    {
        axIF[k] = 0.0;
        die[k] = 0.0;
    }

    // Pressure from EOS
    for(auto k=0; k<CON::nTot; k++)
    {
        gasEOS(rho[k], ie[k], p[k], ss[k]);
    }

    // SPH sum for Pressure Force and Internal Energy Change
    for(int k=0; k<nIP; k++)
    {
        i = iIP[k];
        j = jIP[k];
        H = -dw[k]*( (p[i]/pow(rho[i],2)) + (p[j]/pow(rho[j],2))  );
        He = H*(vx[j] - vx[i]);
        axIF[i] += H*mass[j];
        axIF[j] -= H*mass[i];
        die[i] += He*mass[j];
        die[j] += He*mass[i];
    }

    // Update Internal Energy
    for(auto k=0; k<CON::nTot; k++)
    {
        die[k] /= 2.0;
    }
}
