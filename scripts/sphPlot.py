#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created: March 2020
Python without class!

@author: Ryan Clement (RRCC)
"""

import numpy as np
import matplotlib.pyplot as plt
import argparse


def readFile(fName):
    """


    Returns
    -------
    nDumps : TYPE
        DESCRIPTION.
    nPars : TYPE
        DESCRIPTION.
    times : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    vx : TYPE
        DESCRIPTION.
    mass : TYPE
        DESCRIPTION.
    rho : TYPE
        DESCRIPTION.
    p : TYPE
        DESCRIPTION.
    ie : TYPE
        DESCRIPTION.
    xm : TYPE
        DESCRIPTION.
    dx : TYPE
        DESCRIPTION.

    """
    print('Opening File: ',fName)
    f = open(fName,'r')
    times = []
    nDumps = 0
    for lin in f:
        if lin.find("DONE") != -1: nDumps += 1
        if lin.find("NP") != -1: iNP = lin.split()[1]
    print(nDumps," SPH1D output records found.")
    print(iNP, " particles used in simulation.") # iNP assumed constant!
    nPars = int(iNP)
    x = np.zeros((nDumps,nPars))
    xm = np.zeros((nDumps,nPars-1))
    dx = np.zeros((nDumps,nPars-1))
    vx = np.zeros((nDumps,nPars))
    mass = np.zeros((nDumps,nPars))
    rho = np.zeros((nDumps,nPars))
    p = np.zeros((nDumps,nPars))
    ie = np.zeros((nDumps,nPars))
    f.seek(0,0)
    for i in np.arange(nDumps):
        lin1 = f.readline().split()
        t = lin1[1]
        times.append(t)
        print("Processing record from time = ",t," s")
        f.readline()
        f.readline()
        j = 0
        while j < nPars:
            lin = f.readline()
            nums = lin.split()
            x[i][j] = nums[0]
            vx[i][j] = nums[1]
            mass[i][j] = nums[2]
            rho[i][j] = nums[3]
            p[i][j] = nums[4]
            ie[i][j] = nums[5]
            j+=1
        f.readline()
        dx[i] = x[i][1:] - x[i][0:-1]
        xm[i] = (x[i][1:] + x[i][0:-1])/2.0
    f.close()
    return nDumps,nPars,times,x,vx,mass,rho,p,ie,xm,dx


def plotAll(t,x,vx,mass,rho,p,ie,xm,dx):
    """


    Parameters
    ----------
    t : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    vx : TYPE
        DESCRIPTION.
    mass : TYPE
        DESCRIPTION.
    rho : TYPE
        DESCRIPTION.
    p : TYPE
        DESCRIPTION.
    ie : TYPE
        DESCRIPTION.
    xm : TYPE
        DESCRIPTION.
    dx : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(xm,dx,label='delta-X')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('delta-X')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,3)
    plt.legend()
    plt.show()
    plt.plot(x,vx,label='X-Velocity')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Velocity')
    plt.xlim(-.4,.4)
    plt.ylim(-.5,1)
    plt.legend()
    plt.show()
    plt.plot(x,mass,label='Mass')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Mass')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,3)
    plt.legend()
    plt.show()
    plt.plot(x,rho,label='Density')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Density')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,3)
    plt.legend()
    plt.show()
    plt.plot(x,p,label='Pressure')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Pressure')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,1.2)
    plt.legend()
    plt.show()
    plt.plot(x,ie,label='Internal Energy')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Internal Energy')
    plt.xlim(-.4,.4)
    plt.ylim(1,3)
    plt.legend()
    plt.show()


def plotIE(t,x,ie):
    """


    Parameters
    ----------
    t : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    ie : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(x,ie,label='Internal Energy')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Internal Energy')
    plt.xlim(-.4,.4)
    plt.ylim(1,3)
    plt.legend()
    plt.show()


def plotVEL(t,x,vx):
    """


    Parameters
    ----------
    t : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    vx : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(x,vx,label='X-Velocity')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Velocity')
    plt.xlim(-.4,.4)
    plt.ylim(-.5,1)
    plt.legend()
    plt.show()


def plotP(t,x,p):
    """


    Parameters
    ----------
    t : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    p : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(x,p,label='Pressure')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Pressure')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,1.2)
    plt.legend()
    plt.show()


def plotDEN(t,x,rho):
    """


    Parameters
    ----------
    t : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    rho : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(x,rho,label='Density')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('Density')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,3)
    plt.legend()
    plt.show()


def plotDX(t,xm,dx):
    """


    Parameters
    ----------
    t : TYPE
        DESCRIPTION.
    xm : TYPE
        DESCRIPTION.
    dx : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(xm,dx,label='delta-X')
    plt.title('Simulation Time = '+t+' s')
    plt.xlabel('Position')
    plt.ylabel('delta-X')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,3)
    plt.legend()
    plt.show()


def getUserOptions():
    """


    Returns
    -------
    TYPE
        DESCRIPTION.

    """
    parser = argparse.ArgumentParser(
        description='Welcome to sphPlot help...',
        epilog='Example:\n>python sphPlot.py -i <input_file>')
    # Required argument
    parser.add_argument(
        '-i',
        required=True,
        help="'file/location/SPH1D_Output.txt' is required")
    return parser.parse_args()


def main(args):
    """


    Parameters
    ----------
    args : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    nDumps,nPars,t,x,vx,mass,rho,p,ie,xm,dx = readFile(args.i)
    for i in np.arange(nDumps):
        print("Plotting Time: ",t[i]," s")
        plotVEL(t[i],x[i],vx[i])


if __name__ == '__main__':
    args = getUserOptions()
    main(args)