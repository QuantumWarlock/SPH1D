/* *************************************************************************************************
 *
 * Namespace:	CON
 * Purpose:	    Constants for the simulation.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/

#pragma once

namespace CON
{
    // Array Size Parameters
    constexpr int maxIP = 100;
    constexpr int nTot = 400;
    constexpr int maxSZ = maxIP*nTot;


    // PI
    constexpr double pi     = 3.14159265358979323846;
    constexpr double sqrtPi = 1.7724538509055160273;
    constexpr double fourPi = 4.0*pi;
    constexpr double twoPi  = 2.0*pi;
    constexpr double piSq   = pi*pi;

    // ARTIFICIAL VISCOSITY
    constexpr double alpha  = 1.0e0;
    constexpr double beta   = 1.0e0;
    constexpr double etq    = 1.0e-1;

    // GAS EOS
    constexpr double gammaM1 = 0.4;   // gamma = 1.4
}
