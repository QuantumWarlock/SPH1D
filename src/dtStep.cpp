/* *************************************************************************************************
 *
 * Function:	dtStep
 * Purpose:	    Integrate equations one time step.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 12, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "dtStep.h"
    

void dtStep(
    // IN
    const double dt,
    const int nTot,
    const double h[],
    const double mass[],
    const double x[],
    const double vx[],
    const double ie[],
    const double s[],
    // OUT
    double rho[],
    double p[],
    double T[],
    double tds[],
    double ax[],
    double die[],
    double ds[],
    double drho[],
    double vxM[] )
{
    const int maxIP = 100;
    int nIP = 0;
    int iIP[maxIP*nTot] = {0};
    int jIP[maxIP*nTot] = {0};
    double w[maxIP*nTot] = {0};
    double dw[maxIP*nTot] = {0};
    int nNP[nTot] = {0};

    // Calculate Neighboring Particles
    symFind(nTot,h,x,nIP,iIP,jIP,w,dw,nNP);

}
