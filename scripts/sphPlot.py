#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created: Wed Mar 11 2020

@author: Warlock (RRCC)
"""

import numpy as np
import matplotlib.pyplot as plt


def readFile():
    dataFile = 'SPH1D_Output.txt'
    f = open(dataFile,'r')
    lin1 = f.readline().split()
    t = lin1[1]
    lin2 = f.readline().split()
    nTot = int(lin2[1])
    x = np.zeros(nTot)
    xm = np.zeros(nTot-1)
    dx = np.zeros(nTot-1)
    vx = np.zeros(nTot)
    mass = np.zeros(nTot)
    rho = np.zeros(nTot)
    p = np.zeros(nTot)
    ie = np.zeros(nTot)
    lin3 = f.readline().split()
    for ii in np.arange(nTot):
        lin = f.readline().split()
        x[ii] = lin[0]
        vx[ii] = lin[1]
        mass[ii] = lin[2]
        rho[ii] = lin[3]
        p[ii] = lin[4]
        ie[ii] = lin[5]
    f.close()
    dx = x[1:] - x[0:-1]
    xm = (x[1:] + x[0:-1])/2.0
    return x,vx,mass,rho,p,ie,xm,dx

def plotData(x,vx,mass,rho,p,ie,xm,dx):
    plt.plot(x,x,'.',markersize=0.5,label='X-Position')
    plt.xlabel('Position')
    plt.ylabel('Position')
    plt.legend()
    plt.show()
    plt.plot(xm,dx,'.',markersize=0.5,label='delta-X')
    plt.xlabel('Position')
    plt.ylabel('delta-X')
    plt.legend()
    plt.show()
    plt.plot(x,vx,'.',markersize=0.5,label='X-Velocity')
    plt.xlabel('Position')
    plt.ylabel('Velocity')
    plt.legend()
    plt.show()
    plt.plot(x,mass,'.',markersize=0.5,label='Mass')
    plt.xlabel('Position')
    plt.ylabel('Mass')
    plt.legend()
    plt.show()
    plt.plot(x,rho,'.',markersize=0.5,label='Density')
    plt.xlabel('Position')
    plt.ylabel('Density')
    plt.legend()
    plt.show()
    plt.plot(x,p,'.',markersize=0.5,label='Pressure')
    plt.xlabel('Position')
    plt.ylabel('Pressure')
    plt.legend()
    plt.show()
    plt.plot(x,ie,'.',markersize=0.5,label='Internal Energy')
    plt.xlabel('Position')
    plt.ylabel('Internal Energy')
    plt.legend()
    plt.show()


def main():
    x,vx,mass,rho,p,ie,xm,dx = readFile()
    plotData(x,vx,mass,rho,p,ie,xm,dx)
    

if __name__ == '__main__':
    main()