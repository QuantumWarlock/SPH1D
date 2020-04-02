# SPH1D
1D Smoothed Particle Hydrodynamics C++ code for simulating a classic Shock Tube. This code is designed for running on desktops and laptops. It is a relatively small 1D test case. However, it was tested on a HPC (because why not?) and the CMake failed to correctly use the Module environment settings. Instead of wading further into CMake for HPC, I will create a Makefile based build system and code that is designed for both serial and parallel use and create a seperate repository for that project (and create a 2 or 3D code because this 1D which executes in fractions of a second would be silly on HPC resources).  

## Linux: SPH1D.x

I recommend "out of source" builds. This will prevent mixing build artifacts with the code base.

**Release Build:**
```bash
>mkdir build
>cd build
>cmake -DCMAKE_BUILD_TYPE=Release /path/to/dir/with/CMakeLists.txt/in/it
>make
```
**Debug Build:**
```bash
>mkdir build
>cd build
>cmake -DCMAKE_BUILD_TYPE=Debug /path/to/dir/with/CMakeLists.txt/in/it
>make
```

**Run:**
```bash
>./SPH1D.x
```

## Windows 10: SPH1D.exe

**Build:**
```powershell
Powershell works fine. However, paths can get very long etc...
```
I recommend Visual Studio Code (a.k.a. VS Code) or Visual Studio. I tested both Visual Studio Community 2019 (16.5.1) and VS Code (1.43.2) using Microsoft's Visual C++ compiler. If you are fully committed to Windows then I recommend Visual Studio (and learn to love JSON). If you want work on Linux and Windows I recommend VS Code. 

**Run:**
```powershell
>.\SPH1D.exe
```
Again, Powershell works fine. However, as above, using either of the Visual Studio products is really the way to go on Windows especially if debugging. Also, as above, VS Code works on both Linux and Windows (so guess what I use ...).

## macOS: SPH1D.x
TBD

## Scripts:

### sphMovie.py
```bash
>python3 sphMovie.py
```
Script assumes relative file structure.

### sphPlot.py

**Execute:**
```bash
>python3 sphPlot.py -i path/to/SPH1D_Output.txt
```
**Help:**
```bash
>python3 sphPlot.py -h
```
or
```bash
>python3 sphPlot.py --help
```

### gasEOS.py
**Execute:**
```bash
>python3 gasEOS.py
```
