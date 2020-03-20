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
    const double tMax,
    double dt,
    double &t,
    Arrays &sA)
    {
        double time = t;
        double tmp0 = 0.0;
        double tmp1 = 0.0;
        constexpr int nTot = sA.nTot;
        double ieMin[nTot] = { 0.0 };
        double vxMin[nTot] = { 0.0 };
        double axAV[nTot] = { 0.0 };        // Artificial Viscosity Particle Acceleration
        double dieAV[nTot] = { 0.0 };       // Artificial Viscosity d[ie]/dt

        // "Leap Frog" Integration
        dtStep(dt,axAV,dieAV,sA);
        time += dt;
        for(auto i=0; i<nTot; i++)
        {
            // Update Internal Energy 1/2 time step
            tmp0 = dt*sA.die[i]/2.0;
            tmp1 = sA.ie[i] + tmp0;
            if ( tmp1 >= 0.0 )
            {
                sA.ie[i] += tmp0;
            }
            else
            {
                sA.ie[i] = 0.0;
            }
            // Update Velocity 1/2 time step
            sA.vx[i] += dt*sA.ax[i]/2.0;
            // Update Position
            sA.x[i] += dt*sA.vx[i];
        }

        while( time <= tMax )
        {
            for(auto i=0; i<nTot; i++)
            {
                // Update Internal Energy 1/2 time step
                ieMin[i] = sA.ie[i];
                sA.ie[i] += dt*sA.die[i]/2.0;
                if( sA.ie[i] < 0 ) sA.ie[i] = 0.0; // Eliminate extra array call later.
                // Update Velocity 1/2 time step
                vxMin[i] = sA.vx[i];
                sA.vx[i] += dt*sA.ax[i]/2.0;
            }
            dtStep(dt,axAV,dieAV,sA);
            for(auto i=0; i<nTot; i++)
            {
                sA.ie[i] = ieMin[i] + dt*sA.die[i];
                if( sA.ie[i] < 0.0 ) sA.ie[i] = 0.0; // Eliminate extra array call later.
                sA.vx[i] = vxMin[i] + dt*sA.ax[i];
                sA.x[i] += dt*sA.vx[i];
            }
            time += dt;
        }
        t = time;
    }
