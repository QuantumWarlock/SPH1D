/* *************************************************************************************************
 *
 * Class:	DataOut
 * Purpose:	Output simulation results to file.
 * Author:	Ryan Clement (RRCC)
 * Date:	March 11, 2020
 *
 ***************************************************************************************************/

// INCLUDES
#include "Arrays.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

// PRAGMA
#pragma once


class DataOut 
{
private:
	std::ofstream fileOut;

public:
	// Constructor
	DataOut();


	// Public Member Functions
    void dump(
        const double,
        const Arrays &
    );
	

	// Destructor
	~DataOut();
};