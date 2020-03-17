/* *************************************************************************************************
 *
 * Function:	symFind
 * Purpose:	    Brute force particle search.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "symFind.h"


void symFind(
    Arrays &sA )
{
    const int nTot = sA.nTot;
    const int maxA = nTot * sA.maxIP;   // Maximum number of allowed interactions
    const int nTotM1 = nTot - 1;
    const int k = 3;                    // Scaling factor for Gaussian Kernel
    double dx = 0.0;                    // 1-D: x = x,          3-D: x = <x,y,z>
    double r = 0.0;                     // 1-D: r = abs(dx),    3-D: r = |dx|
    double hM = 0.0;                    // Average h (Monaghan)

    sA.nIP = 0;
    for (int i=0; i<nTot; i++)
    {
        sA.nNP[i] = 0.0;
    }

    for (int i=0; i<nTotM1; i++)
    {
        for (int j=i+1; j < nTot; j++)
        {
            dx = sA.x[i] - sA.x[j];
            r = fabs(dx);
            hM = (sA.h[i] + sA.h[j]) / 2.0;
            if (r < k * hM)
            {
                if (sA.nIP <= maxA)
                {
                    sA.iIP[sA.nIP] = i;
                    sA.jIP[sA.nIP] = j;
                    sA.nIP++;
                    sA.nNP[i]++;
                    sA.nNP[j]++;
                    kernel(r, hM, sA.w[sA.nIP], sA.dw[sA.nIP]);
                }
            }
        }
    }
}