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
    p = CON::gammaM1*rho*ie;
    ss = sqrt( CON::gammaM1*ie );
}
