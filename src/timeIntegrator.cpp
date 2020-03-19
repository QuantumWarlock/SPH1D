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
    Arrays &sA)
    {
        double time = 0.0; // Future: Add offset for non-zero start time.
        double tmp0 = 0.0;
        double tmp1 = 0.0;
        double ieMin[sA.nTot] = { 0.0 };

        // "Leap Frog" Integration
        dtStep(dt,sA);
        time += dt;
        for(auto i=0; i<sA.nTot; i++)
        {
            // Update Internal Energy
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
            // Update Velocity
            sA.vx[i] += dt*sA.ax[i]/2.0;
            // Update Position
            sA.x[i] += dt*sA.vx[i];
        }

        while( time <= tMax )
        {
            time += dt;
        }
    }
