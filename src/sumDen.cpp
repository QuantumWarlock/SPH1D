/* *************************************************************************************************
 *
 * Function:	sumDen
 * Purpose:	    Summation Density Approach.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "sumDen.h"


void sumDen(
    Arrays &sA )
    {
        int i = 0;
        int j = 0;
        double r0 = 0.0;
        double w0 = 0.0;
        double dw0 = 0.0;

        // Contribution of particle density to itself
        /*
        for(int i=0; i<sA.nTot; i++)
        {
            kernel(r0,sA.h[i],w0,dw0);
            sA.w0[i] = w0*sA.mass[i]/sA.rho[i];
        }

        // Kernel Integration
        for(int k=0; k<sA.nIP; k++)
        {
            i = sA.iIP[k];
            j = sA.jIP[k];
            sA.w0[i] += sA.w[k]*sA.mass[j]/sA.rho[j];
            sA.w0[j] += sA.w[k]*sA.mass[i]/sA.rho[i];
        }
        */

        // Density Integration
        for(int k=0; k<sA.nTot; k++)
        {
            kernel(r0,sA.h[k],w0,dw0);
            sA.rho[k] = w0*sA.mass[k];
        }

        // SPH Sum for Density
        for(int k=0; k<sA.nIP; k++)
        {
            i = sA.iIP[k];
            j = sA.jIP[k];
            sA.rho[i] += sA.mass[j]*sA.w[k];
            sA.rho[j] += sA.mass[i]*sA.w[k];
        }

        // NOTE: Normalize Density Approach
        /*  
        for(int i=0; i<sA.nTot; i++)
        {
            sA.rho[i] /= sA.w0[i];
        } 
        */
    }
