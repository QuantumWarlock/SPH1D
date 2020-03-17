cmake_minimum_required(VERSION 3.0.0)
project(SPH1D VERSION 0.1.0
        DESCRIPTION "Noh Shock Tube"
        LANGUAGES CXX)
# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(inc)
set(SOURCES 
        src/Arrays.cpp
        src/artVisc.cpp
        src/conDen.cpp
        src/DataOut.cpp
        src/dtStep.cpp
        src/gasEOS.cpp
        src/init.cpp
        src/kernel.cpp
        src/sph1D.cpp
        src/sumDen.cpp
        src/symFind.cpp
        src/timeIntegrator.cpp
        src/Timer.cpp
        src/waterEOS.cpp
)
configure_file(inc/SPH1DConfig.h.in ../inc/SPH1DConfig.h)
add_executable(SPH1D.x ${SOURCES})


