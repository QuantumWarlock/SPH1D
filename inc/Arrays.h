/* *************************************************************************************************
 *
 * Class:	    Arrays (C struct with constructor and destructor.)
 * Purpose:	    Bundle 'O Simulation Arrays.
 * Author:	    Ryan Clement (RRCC)
 * Date:	    March 10, 2020
 *
 ***************************************************************************************************/


// PRAGMA
#pragma once


class Arrays
{
public:
    static constexpr int maxIP = 100;
    static constexpr int nTot = 400;

    // Constructor
    Arrays();
    Arrays(const int);

    // Data Members: Scalers
    int nIP = 0;

    // Data Members: Arrays
    int iIP[maxIP*nTot] = { 0 };
    int jIP[maxIP*nTot] = { 0 };
    int nNP[nTot] = { 0 };
    double x[nTot] = { 0.0 };           // Particle Position
    double vx[nTot] = { 0.0 };          // Paricle Velocity
    double ax[nTot] = { 0.0 };          // Particle Acceleration
    double axAV[nTot] = { 0.0 };        // Artificial Viscosity Particle Acceleration
    double mass[nTot] = { 0.0 };        // Mass
    double rho[nTot] = { 0.0 };         // Density
    double p[nTot] = { 0.0 };           // Pressure
    double ie[nTot] = { 0.0 };          // Internal Energy
    double h[nTot] = { 0.0 };           // Smoothing Length
    double ss[nTot] = { 0.0 };          // Sound Speed (normally called "c")
    double s[nTot] = { 0.0 };           // Entropy
    double te[nTot] = { 0.0 };          // Total Energy
    double w[maxIP*nTot] = { 0.0 };     // Smoothing Function
    double dw[maxIP*nTot] = { 0.0 };    // Soothing Function Derivative
    //double w0[nTot] = { 0.0 };          // Kernel at distance 0 (self interaction) for Normalization Density Approach
    //double vxM[nTot] = { 0.0 };         // Monoghan Average Velocity
    double tds[nTot] = { 0.0 };         // Production of Viscous Entropy (t*ds/dt)
    double die[nTot] = { 0.0 };         // d[ie]/dt
    double dieAV[nTot] = { 0.0 };       // Artificial Viscosity d[ie]/dt
    double ds[nTot] = { 0.0 };          // ds/dt
    double drho[nTot] = { 0.0 };        // d[rho]/dt
    //double T[nTot] = { 0.0 };           // Temperature

    // Destructor
    ~Arrays();
};
