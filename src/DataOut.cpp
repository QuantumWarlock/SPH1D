/* *************************************************************************************************
 *
 * Class:	    DataOut
 * Purpose:	    Write simulation results to file.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 2020
 *
 ***************************************************************************************************/


// INCLUDE
#include "DataOut.h"


// Constructor
DataOut::DataOut()
{
	fileOut.open("SPH1D_Output.txt");
	if ( fileOut.fail() )
	{
		std::cout << "ERROR: Output file, SPH1D_Output.txt, was not opened." << std::endl;
		exit(-1);
	}
	else
	{
		fileOut.precision(6);
		fileOut.setf(std::ios::scientific);
	}
}

// Private Member Functions

// Public Member Functions
void DataOut::dump(
    const double t,
    const double x[],
    const double vx[],
    const double mass[],
    const double rho[],
    const double p[],
    const double ie[] )
{
    fileOut << "TIME\t" << t << std::endl;
    fileOut << "NP\t" << CON::nTot << std::endl;
    fileOut << std::left
            << std::setw(20) << "    X"
            << std::setw(20) << "    Vx"
            << std::setw(20) << "    Mass"
            << std::setw(20) << "    DEN"
            << std::setw(20) << "    P"
            << std::setw(20) << "    IE"
            << std::endl;
    for(auto i=0;i<CON::nTot;i++)
    {
        fileOut << std::setw(20) << x[i]
                << std::setw(20) << vx[i]
                << std::setw(20) << mass[i]
                << std::setw(20) << rho[i]
                << std::setw(20) << p[i]
                << std::setw(20) << ie[i]
                << std::endl;
    }
    fileOut << "DONE" << std::endl;
}

// Destructor
DataOut::~DataOut()
{
	fileOut.close();
}
