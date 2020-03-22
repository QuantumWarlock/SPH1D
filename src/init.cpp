/* *************************************************************************************************
 *
 * Function:	init
 * Purpose:	    Initialize problem (set-up).
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "init.h"


void init(double x[], double vx[], double mass[], double rho[], double p[], double ie[], double h[])
{
    std::cout << "\tInitializing Shock Tube Simulation ..." << std::endl;

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
    const double massInit = 0.75/CON::nTot;

    for(auto i=0; i<CON::nTot; i++)
    {
        mass[i] = massInit;
        h[i] = 0.015;
        vx[i] = 0.0;
        if ( i < 320 )
        {
            x[i] = -0.6 + dx*i/4.0;
            ie[i] = 2.5;
            rho[i] = 1.0;
            p[i] = 1.0;
        }
        else
        {
            x[i] = dx*(i-319);
            ie[i] = 1.795;
            rho[i] = 0.25;
            p[i] = 0.1795;
        }
    }
}
