/* *************************************************************************************************
 *
 * Function:	waterEOS
 * Purpose:	    "Special" Equation Of State for Artifical Compressibility of Water.
 * Reference:   Morris, 1997
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 12, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "waterEOS.h"


void waterEOS(
    // IN
    const double rho,
    // OUT
    double &p,
    double &ss )
    {
        ss = 0.01;
        p = ss*ss*rho;
    }
