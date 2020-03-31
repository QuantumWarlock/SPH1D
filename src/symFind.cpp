/* *************************************************************************************************
 *
 * Function:	symFind
 * Purpose:	    Brute force particle search.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include "symFind.h"


void symFind(
    const double h[],           // (IN)  Smoothing length
    const double x[],           // (IN)  Particle coordinate
    int iIP[],                  // (OUT) First particle of interaction pair
    int jIP[],                  // (OUT) Second particle of interaction pair
    double w[],                 // (OUT) Kernel for all interaction pairs
    double dw[],                // (OUT) Derivative of kernel with respect to coordinate
    int nNP[],                  // (OUT) Number of neighboring pairs
    int &nIP                    // (OUT) Number of interaction pairs
    )
{
    //const int k = 3;                    // Scaling factor for Gaussian Kernel
    const int k = 2;                    // Scaling factor for Cubic Spline
    double dx = 0.0;                    // 1-D: x = x,          3-D: x = <x,y,z>
    double r = 0.0;                     // 1-D: r = abs(dx),    3-D: r = |dx|
    double hM = 0.0;                    // Average h (Monaghan)

    nIP = 0;
    for (auto i=0; i<CON::nTot; i++)
    {
        nNP[i] = 0;
    }

    for (auto i=0; i<CON::nTot - 1; i++)
    {
        for (auto j=i+1; j < CON::nTot; j++)
        {
            dx = x[i] - x[j];
            r = sqrt(dx*dx);
            hM = (h[i] + h[j]) / 2.0;
            if (r < k * hM)
            {
                try
                {
                    if (nIP < CON::maxSZ)
                    {
                        iIP[nIP] = i;
                        jIP[nIP] = j;
                        nNP[i]++;
                        nNP[j]++;
                        //skGauss(r, dx, hM, w[nIP], dw[nIP]);
                        skCubSpl(r, dx, hM, w[nIP], dw[nIP]);
                        nIP++;
                    }
                    else
                    {
                        throw std::out_of_range("Interacting particle limit exceeded!");
                    }
                }
                catch (std::out_of_range& e)
                {
                    std::cerr << e.what() << std::endl;
                    std::terminate();
                }
            }
        }
    }
}
