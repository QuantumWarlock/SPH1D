# -*- coding: utf-8 -*-
"""
Created: March 2020

@author: Ryan Clement (RRCC)
"""


import numpy as np
import matplotlib.pyplot as plt
import math as m


def gaseos(rho, ie):
    """


    Parameters
    ----------
    rho : TYPE
        DESCRIPTION.
    ie : TYPE
        DESCRIPTION.

    Returns
    -------
    p : TYPE
        DESCRIPTION.
    c : TYPE
        DESCRIPTION.

    """
    gamma = 1.4
    p = (gamma - 1.0) * rho * ie
    c = m.sqrt( (gamma - 1.0) * ie )
    return p,c


def gasP(rho, ie):
    """


    Parameters
    ----------
    rho : TYPE
        DESCRIPTION.
    ie : TYPE
        DESCRIPTION.

    Returns
    -------
    TYPE
        DESCRIPTION.

    """
    gamma = 1.4
    return (gamma - 1.0) * rho * ie


def init():
    """


    Returns
    -------
    mass : TYPE
        DESCRIPTION.
    x : TYPE
        DESCRIPTION.
    vx : TYPE
        DESCRIPTION.
    rho : TYPE
        DESCRIPTION.
    ie : TYPE
        DESCRIPTION.
    p : TYPE
        DESCRIPTION.

    """
    nPars = 400
    dx = 0.6/80.0;
    massInit = 0.75/nPars;
    mass = np.zeros(nPars)
    vx = np.zeros(nPars)
    x = np.zeros(nPars)
    rho = np.zeros(nPars)
    ie = np.zeros(nPars)
    p = np.zeros(nPars)
    for i in np.arange(nPars):
        mass[i] = massInit
        vx[i] = 0.0
        if ( i < 320 ):
            x[i] = -0.6 + dx*i/4.0
            ie[i] = 2.5
            rho[i] = 1.0
            p[i] = 1.0
        else:
            x[i] = dx*(i-319)
            ie[i] = 1.795
            rho[i] = 0.25
            p[i] = 0.1795
    return mass, x, vx, rho, ie, p


def plotVar(x,var):
    """


    Parameters
    ----------
    x : TYPE
        DESCRIPTION.
    var : TYPE
        DESCRIPTION.

    Returns
    -------
    None.

    """
    plt.plot(x,var,label='Pressure')
    plt.xlabel('Position')
    plt.ylabel('Variable')
    plt.xlim(-.4,.4)
    plt.ylim(-.1,1.2)
    plt.legend()
    plt.show()


def compareP():
    """


    Returns
    -------
    None.

    """
    nPars = 400
    peos = np.zeros(nPars)
    percDiff = np.zeros(nPars)
    for i in np.arange(nPars):
        peos[i] = gasP(rho[i], ie[i])
        percDiff[i] = 100.0*(p[i] - peos[i])/p[i]
    plt.plot(x,p,label='IC Pressure')
    plt.plot(x,peos,label='EOS Pressure')
    #plt.plot(x,p-peos,label='P Diff')
    plt.plot(x,percDiff,label='Percent Diff')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    mass, x, vx, rho, ie, p = init()
    compareP()
