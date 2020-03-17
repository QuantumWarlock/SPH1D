/* *************************************************************************************************
 *
 * Function:	conDen
 * Purpose:	    Continuity Density Approach.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "conDen.h"


void conDen(
    Arrays &sA )
    {
        int i = 0;
        int j = 0;
        double dvx = 0;
        double vcc = 0;

        for(int i=0; i<sA.nTot; i++)
        {
            sA.drho[i] = 0.0;
        }

        for(int k=0; k<sA.nIP; k++)
        {
            i = sA.iIP[k];
            j = sA.jIP[k];
            dvx = sA.vx[i] - sA.vx[j];
            vcc = dvx*sA.dw[k];
            sA.drho[i] += sA.mass[j]*vcc;
            sA.drho[j] += sA.mass[i]*vcc;
        }
    }