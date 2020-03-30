/* *************************************************************************************************
 *
 * Function:	timeIntegrator
 * Purpose:	    Advance the simulation in time.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "timeIntegrator.h"


void timeIntegrator(
    const double tMax,
    double dt,
    double &t,
    double x[],
    double vx[],
    double ax[],
    double mass[],
    double rho[],
    double p[],
    double ie[],
    double ss[],
    double s[],
    double te[],
    double h[],
    double T[],
    DataOut *dOut )
    {
        int     iTime = 0;
        int     iIP[CON::maxSZ]   = { 0 };   // First Particle of Interaction Pair
        int     jIP[CON::maxSZ]   = { 0 };   // Second Particle of Interaction Pair
        int     nNP[CON::nTot]    = { 0 };
        double  w[CON::maxSZ]     = { 0.0 }; // Smoothing Function
        double  dw[CON::maxSZ]    = { 0.0 }; // Soothing Function Derivative
        double  die[CON::nTot]    = { 0.0 }; // d[ie]/dt
        double  drho[CON::nTot]   = { 0.0 }; // d[rho]/dt
        double  ieMin[CON::nTot]  = { 0.0 };
        double  rhoMin[CON::nTot] = { 0.0 };
        double  vxMin[CON::nTot]  = { 0.0 };
        double  axAV[CON::nTot]   = { 0.0 }; // Artificial Viscosity Particle Acceleration
        double  dieAV[CON::nTot]  = { 0.0 }; // Artificial Viscosity d[ie]/dt
        double  axIF[CON::nTot]   = { 0.0 }; // Internal Energy Particle Acceleration

        // "kick-drift-kick" variant "Leapfrog" Integration Scheme
        // "kick-drift-kick" is used to support the potential for variable timestepping.
        dtStep(iTime, dt, h, mass, x, vx, ie, rho, p, ax, die, drho, T, ss,
               iIP, jIP, nNP, w, dw, axAV, dieAV, axIF);

        for(auto i=0; i<CON::nTot; i++)
        {
            // Update Internal Energy 1/2 time step
            ie[i] += dt*die[i]/2.0;
            if ( ie[i] < 0.0 ) ie[i] = 0.0;
            // Update Velocity 1/2 time step
            vx[i] += dt*ax[i]/2.0;
            // Update Position
            x[i] += dt*vx[i];
        }
        t += dt;
        iTime++;

        while( t <= tMax )
        {
            dOut->dump(t, x, vx, mass, rho, p, ie);
            for(auto i=0; i<CON::nTot; i++)
            {
                // Update Internal Energy 1/2 time step
                ieMin[i] = ie[i];
                ie[i] += dt*die[i]/2.0;
                if( ie[i] < 0 ) ie[i] = 0.0;
                // Update Velocity 1/2 time step
                vxMin[i] = vx[i];
                vx[i] += dt*ax[i]/2.0;
            }
            dtStep(iTime, dt, h, mass, x, vx, ie, rho, p, ax, die, drho, T, ss,
                   iIP, jIP, nNP, w, dw, axAV, dieAV, axIF);
            for(auto i=0; i<CON::nTot; i++)
            {
                ie[i] = ieMin[i] + dt*die[i];
                if( ie[i] < 0.0 ) ie[i] = 0.0;
                vx[i] = vxMin[i] + dt*ax[i];
                x[i] += dt*vx[i];
            }
            t += dt;
            iTime++;
        }
    }
