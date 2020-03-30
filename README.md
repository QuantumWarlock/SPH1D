# SPH1D
1D Smoothed Particle Hydrodynamics C++ code for simulating the Noh Shock Tube.

## Linux: SPH1D.x

**Build:**

Recommend out of source build.
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
```

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
