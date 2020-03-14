/* *************************************************************************************************
 *
 * Class:	    DataOut
 * Purpose:	    Write simulation results to file.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 11, 2020
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
    const Arrays &sA)
{
    const int nTot = sA.nTot;
    fileOut << "TIME\t" << t << std::endl;
    fileOut << "NP\t" << nTot << std::endl;
    fileOut << std::left
            << std::setw(20) << "    X" 
            << std::setw(20) << "    Vx" 
            << std::setw(20) << "    Mass" 
            << std::setw(20) << "    DEN" 
            << std::setw(20) << "    P" 
            << std::setw(20) << "    IE" 
            << std::endl;
    for(int i=0;i<nTot;i++)
    {
        fileOut << std::setw(20) << sA.x[i]
                << std::setw(20) << sA.vx[i]
                << std::setw(20) << sA.mass[i]
                << std::setw(20) << sA.rho[i]
                << std::setw(20) << sA.p[i] 
                << std::setw(20) << sA.ie[i]
                << std::endl;
    }
    fileOut << "DONE" << std::endl;
}

// Destructor
DataOut::~DataOut()
{
	fileOut.close();
}
