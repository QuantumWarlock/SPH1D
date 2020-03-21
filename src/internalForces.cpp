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
    double axIF[],
    Arrays &sA )
{
    const int nTot = sA.nTot;
    int i = 0;
    int j = 0;
    double H = 0.0;
    double He = 0.0;

    // Initialize: Velocity Divergence, t*d[s]/dt, d[ie]/dt, Acceleration
    for(auto i=0; i<nTot; i++)
    {
        axIF[i] = 0.0;
        sA.die[i] = 0.0;
    }

    // Pressure from EOS
    for(auto i=0; i<nTot; i++)
    {
        gasEOS(sA.rho[i],sA.ie[i],sA.p[i],sA.ss[i]);
    }

    // SPH sum for: Pressure Force and Internal Energy Change
    for(auto k=0; k<sA.nIP; k++)
    {
        i = sA.iIP[k];
        j = sA.jIP[k];
        H = -sA.dw[k]*( (sA.p[i]/pow(sA.rho[i],2)) + (sA.p[j]/pow(sA.rho[j],2))  );
        He = H*(sA.vx[j] - sA.vx[i]);
        sA.ax[i] += H*sA.mass[j];
        sA.ax[j] += H*sA.mass[i];
        sA.die[i] += He*sA.mass[j];
        sA.die[j] += He*sA.mass[i];
    }

    // Update Internal Energy
    for(auto i=0; i<nTot; i++)
    {
        sA.die[i] /= 2.0;
    }
}
