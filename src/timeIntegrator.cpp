/* *************************************************************************************************
 *
 * Function:	timeIntegrator
 * Purpose:	    Advance the simulation in time.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 12, 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "timeIntegrator.h"


void timeIntegrator(
    double x[],
    double vx[],
    double mass[],
    double rho[],
    double p[],
    double ie[],
    double ss[],
    double s[],
    double te[],
    double h[],
    const int nTot,
    const double tMax,
    double dt )
    {
        double vxM[nTot] = {0};         // Monoghan Average Velocity
        double tds[nTot] = {0};         // Production of Viscous Entropy (t*ds/dt)
        double ax[nTot] = {0};          // Acceleration
        double die[nTot] = {0};         // d[ie]/dt
        double ds[nTot] = {0};          // ds/dt
        double drho[nTot] = {0};        // d[rho]/dat
        double T[nTot] = {0};           // Temperature


        dtStep(dt,nTot,h,mass,x,vx,ie,s,rho,p,T,tds,ax,die,ds,drho,vxM);
    }