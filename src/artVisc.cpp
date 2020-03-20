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
    double axAV[],
    double dieAV[],
    Arrays &sA )
    {
        int i = 0;
        int j = 0;
        double dx = 0.0;
        double dvx = 0.0;
        double h = 0.0;
        double hM = 0.0;
        double piv = 0.0;
        double rhoM = 0.0;
        double rr = 0.0;
        double ssM = 0.0;
        double uvM = 0.0;
        double vr = 0.0;

        // "Zero" Acceleration and d[internal energy]/dt
        for(auto i=0; i<sA.nTot; i++)
        {
            axAV[i] = 0.0;
            dieAV[i] = 0.0;
        }

        // SPH Sum for Artificial Viscosity
        for(auto k=0; k<sA.nIP; k++)
        {
            i = sA.iIP[k];
            j = sA.jIP[k];
            hM = (sA.h[i] + sA.h[j])/2.0;
            vr = 0.0;
            rr = 0.0;
            dvx = sA.vx[i] - sA.vx[j];
            dx = sA.x[i] - sA.x[j];
            vr += dvx*dx;
            rr += dx*dx;
            if ( vr < 0.0 )
            {
                /*
                NOTE:   In (Liu and Liu, 2003) the sound speed is passed
                        as the temperature, i.e. "c" vs "t" in the text!
                        Check the literature (Monaghan, 1992) ...
                 */
                uvM = hM*vr/(rr + hM*hM*CON::etq*CON::etq);
                ssM = (sA.ss[i] + sA.ss[j])/2.0;
                rhoM = (sA.rho[i] + sA.rho[j])/2.0;
                piv = (CON::beta*uvM - CON::alpha*ssM)*uvM/rhoM;
                h = -piv*sA.dw[k];
                axAV[i] += sA.mass[j]*h;
                axAV[j] -= sA.mass[i]*h;
                dieAV[i] -= sA.mass[j]*dvx*h;
                dieAV[j] -= sA.mass[i]*dvx*h;
            }
        }

        // Change of Specific Internal Energy
        for(auto i=0; i<sA.nTot; i++)
        {
            dieAV[i] *= 0.5;
        }
    }
