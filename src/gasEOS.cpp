/* *************************************************************************************************
 *
 * Function:	gasEOS
 * Purpose:	    Ideal Gas Equation Of State.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 12, 2020
 *
 ***************************************************************************************************/
    

// INCLUDES
#include "gasEOS.h"


void gasEOS(
    // IN
    const double rho,
    const double ie,
    // OUT
    double &p,
    double &ss )
    {
        double gammaM1 = 0.4;   // gamma = 1.4
        p = gammaM1*rho*ie;
        ss = sqrt( gammaM1*ie );
    }