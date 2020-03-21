/* *************************************************************************************************
 *
 * Function:	init
 * Purpose:	    Initialize problem (set-up).
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 11, 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "init.h"


void init(
    Arrays &sA )
{
    std::cout << "\tInitializing Noh Shock Tube Simulation ..." << std::endl;

    /* ***** Set-Up Information *****
     *
     * Length of tube: 1.2 [-0.6,0.6]
     * LHS: [-0.6, 0]
     * RHS: (0.0, 0.6]
     * Number of particles on RHS: 80
     * Number of particles on LHS: 320
     *
     */

    const double dx = 0.6/80.0;
    const double massInit = 0.75/nTot;

    for(int i=0; i<nTot; i++)
    {
        sA.mass[i] = massInit;
        sA.h[i] = 0.015;
        sA.vx[i] = 0.0;
        if ( i < 320 )
        {
            sA.x[i] = -0.6 + dx*i/4.0;
            sA.ie[i] = 2.5;
            sA.rho[i] = 1.0;
            sA.p[i] = 1.0;
        }
        else
        {
            sA.x[i] = dx*(i-319);
            sA.ie[i] = 1.795;
            sA.rho[i] = 0.25;
            sA.p[i] = 0.1795;
        }
    }
}
