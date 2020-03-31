# SPH1D
1D Smoothed Particle Hydrodynamics C++ code for simulating a classic Shock Tube.

## Linux: SPH1D.x

**Build:**

Recommend "out of source" build. 
```bash
>mkdir build
>cd build
>cmake /path/to/dir/with/CMakeLists.txt/in/it
>make
```
**Run:**
```bash
./sph.x
```

## Windows: SPH1D.exe

**Build:**
```powershell
Powershell works fine. However, paths can get very long etc...
```
I recommend Visual Studio Code (a.k.a. VS Code) or Visual Studio. I tested both Visual Studio Community 2019 (16.5.1) and VS Code (1.43.2) using Microsoft's Visual C++ compiler. If you are fully committed to Windows then I recommend Visual Studio (and learn to love JSON). If you want work on Linux and Windows I recommend VS Code. 

## Scripts:

### sphPlot.py

**Execute:**
```bash
python3 sphPlot.py -i path/to/SPH1D_Output.txt
```
**Help:**
```bash
python3 sphPlot.py -h
```
or
```bash
python3 sphPlot.py --help
```

### gasEOS.py
**Execute:**
```bash
python3 gasEOS.py
```
