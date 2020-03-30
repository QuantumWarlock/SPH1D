/* *************************************************************************************************
 *
 * Function:	artVisc
 * Purpose:	    Artificial Viscosity (Monaghan, 1992).
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "artVisc.h"


void artVisc(
    const double h[],
    const double mass[],
    const double x[],
    const double vx[],
    const int nIP,
    const double rho[],
    const double ss[],
    const int iIP[],
    const int jIP[],
    const double w[],
    const double dw[],
    double axAV[],
    double dieAV[] )
{
    int i = 0;
    int j = 0;
    double dx = 0.0;
    double dvx = 0.0;
    double hAV = 0.0;
    double hM = 0.0;
    double piv = 0.0;
    double rhoM = 0.0;
    double rr = 0.0;
    double ssM = 0.0;
    double uvM = 0.0;
    double vr = 0.0;

    // "Zero" Acceleration and d[internal energy]/dt
    for(auto k=0; k<CON::nTot; k++)
    {
        axAV[k] = 0.0;
        dieAV[k] = 0.0;
    }

    // SPH Sum for Artificial Viscosity
    for(auto k=0; k<nIP; k++)
    {
        i = iIP[k];
        j = jIP[k];
        hM = (h[i] + h[j])/2.0;
        dvx = vx[i] - vx[j];
        dx = x[i] - x[j];
        vr = dvx*dx;
        rr = dx*dx;
        if ( vr < 0.0 )
        {
            uvM = hM*vr/(rr + hM*hM*CON::etq*CON::etq);
            ssM = (ss[i] + ss[j])/2.0;
            rhoM = (rho[i] + rho[j])/2.0;
            piv = uvM*(CON::beta*uvM - CON::alpha*ssM)/rhoM;
            hAV = -piv*dw[k];
            axAV[i] += mass[j]*hAV;
            axAV[j] -= mass[i]*hAV;
            dieAV[i] -= mass[j]*dvx*hAV;
            dieAV[j] -= mass[i]*dvx*hAV;
        }
    }

    // Change of Specific Internal Energy
    for(auto i=0; i<CON::nTot; i++)
    {
        dieAV[i] *= 0.5;
    }
}
