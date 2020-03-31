/* *************************************************************************************************
 *
 * Function:	dtStep
 * Purpose:	    Integrate equations one time step.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "dtStep.h"


void dtStep(
    // IN
    const int iTime,
    const double dt,
    const double h[],
    const double mass[],
    const double x[],
    const double vx[],
    const double ie[],
    // OUT
    double rho[],
    double p[],
    double ax[],
    double die[],
    double drho[],
    double T[],
    double ss[],
    // FUNCTION SPECIFIC
    int iIP[],
    int jIP[],
    int nNP[],
    double w[],
    double dw[],
    double axAV[],
    double dieAV[],
    double axIF[]
    )
{
    int nIP = 0;
    for(auto i=0; i<CON::nTot; i++)
    {
        //die[i] = 0.0;
        dieAV[i] = 0.0;
        axAV[i] = 0.0;
        axIF[i] = 0.0;
    }

    // Calculate Neighboring Particles
    symFind(h, x, iIP, jIP, w, dw, nNP, nIP);

    // Density Approximation
    sumDen(h, mass, nIP, iIP, jIP, w, rho);

    // Internal Forces
    internalForces(dt, h, mass, vx, nIP, rho, iIP, jIP, dw, ie, x, T, ss, p, axIF, die);

    // Artificial Viscosity
    artVisc(h, mass, x, vx, nIP, rho, ss, iIP, jIP, w, dw, axAV, dieAV);

    // Convert Velocity, Force, and Energy to f and df/dt
    // ... add components from updates above
    for(auto i=1; i<CON::nTot-1; i++)
    {
        ax[i] = axAV[i] + axIF[i];
        die[i] += dieAV[i];
    }
}
