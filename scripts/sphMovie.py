# -*- coding: utf-8 -*-
"""
Created: March 2020
Python without class!

@author: Ryan Clement (RRCC)

Purpose: Animate SPH shock tube simulation.
"""

import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Set FIGURE to 8 inches by 8 inches
mpl.rcParams['figure.figsize'] = [8.0, 8.0]


def getData():
    fName = '../build/SPH1D_Output.txt'
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
            x[i,j] = nums[0]
            vx[i,j] = nums[1]
            mass[i,j] = nums[2]
            rho[i,j] = nums[3]
            p[i,j] = nums[4]
            ie[i,j] = nums[5]
            j+=1
        f.readline()
    f.close()
    return nDumps,nPars,times,x,vx,mass,rho,p,ie


def init():
    # Velocity
    aV.set_data([],[])
    # Pressure
    aP.set_data([],[])
    # Density
    aD.set_data([],[])
    # Internal Energy
    aU.set_data([],[])
    # Simulation Time
    tText.set_text('Time = 0.0')
    return aV, aP, aD, aU, tText


def animate(i):
    s = 'Time = %s s' % times[i]
    tText.set_text( s )
    aV.set_data(x[i,:],vx[i,:])
    aP.set_data(x[i,:],p[i,:])
    aD.set_data(x[i,:],rho[i,:])
    aU.set_data(x[i,:],ie[i,:])
    return aV, aP, aD, aU, tText



# MAKE A MOVIE !
nDumps,nPars,times,x,vx,mass,rho,p,ie = getData()
fig, axs = plt.subplots(2,2,sharex=True,constrained_layout=True)
fig.suptitle( 'Shock Tube' )
# Velocity
axs[0,0].set_xlim(-.4,.4)
axs[0,0].set_title('Velocity')
axs[0,0].set_ylim(-.15,1.1)
axs[0,0].grid(True)
tText = axs[0,0].text(-.39, 1, 'Time = 0.0', fontweight='bold')
aV, = axs[0,0].plot([],[])
# Pressure
axs[0,1].set_ylim(-.1,1.2)
axs[0,1].set_title('Pressure')
axs[0,1].grid(True)
aP, = axs[0,1].plot([],[],'tab:red')
# Density
axs[1,0].set_ylim(0,1.2)
axs[1,0].set_title('Density')
axs[1,0].grid(True)
aD, = axs[1,0].plot([],[],'tab:purple')
# Internal Energy
axs[1,1].set_ylim(1.5,2.8)
axs[1,1].set_title('Internal Energy')
axs[1,1].grid(True)
aU, = axs[1,1].plot([],[],'tab:green')

ani = animation.FuncAnimation(fig, animate, np.arange(nDumps),
                              interval=500,blit=True,
                              init_func=init)

pwriter = animation.PillowWriter(fps=2, metadata=dict(artist='Dr. Ryan Clement'))
ani.save('../movies/sph_shocktube.gif',writer=pwriter)
plt.show()

