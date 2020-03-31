/* *************************************************************************************************
 *
 * Class:	DataOut
 * Purpose:	Output simulation results to file.
 * Author:	Ryan Clement (RRCC)
 * Date:	March 2020
 *
 ***************************************************************************************************/


// INCLUDES
#include "constants.h"
#include <iomanip>			// Parametric manipulators (formatting)
#include <iostream>			// Input/Output (streams)
#include <fstream>
#include <stdexcept>
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
        const double [],
    	const double [],
    	const double [],
    	const double [],
    	const double [],
    	const double []
    );

	// Destructor
	~DataOut();
};
