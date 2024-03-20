Learning how to use CMake by following this playlist: https://www.youtube.com/playlist?list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4

Episode 1 Notes:
- Using MinGW compilers: cmake -DCMAKE_C_COMPILER="C:\path\to\gcc.exe" -DCMAKE_CXX_COMPILER="C:\path\to\g++.exe"
- Explicitly specify generator when running build: cmake -G"MinGW Makefiles" -S ..\..\ -B .\
- Downloaded make for Windows: https://gnuwin32.sourceforge.net/packages/make.htm