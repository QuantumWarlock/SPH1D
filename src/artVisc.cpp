/* *************************************************************************************************
 *
 * Function:	artVisc
 * Purpose:	    Artificial Viscosity (Monaghan, 1992).
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "artVisc.h"


void artVisc(
    Arrays &sA )
    {
        int i = 0;
        int j = 0;
        double dvx = 0.0;
        double vr = 0.0;
        double rr = 0.0;

        // "Zero" Acceleration and d[internal energy]/dt
        for(auto i=0; i<sA.nTot; i++)
        {
            sA.ax[i] = 0.0;
            sA.die[i] = 0.0;
        }

        for(auto k=0; k<sA.nIP; k++)
        {

        }
    }
