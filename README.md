# Coding Sandbox for C++

Repo contains solutions for data structures and problem solving in C++.

Makes use of some parts of Sébastien Rombauts [Cpp-Skeleton](https://github.com/SRombauts/cpp-skeleton) for basic utility functions such as timers, and includes the [Catch](https://github.com/catchorg/Catch2) headers as a test suite.

Visual Studio 2017 projects and solution files can be created using CMake and `build.bat` script or:

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64"
```

## Notes
- Ctrl + F5 in visual studio 
- Redirection :
```
program.exe <infile >outfile
```

## CMake
`build.bat` and `build.sh` scripts should build automatically for VS2017, but in case you want to customize the visual studio version or build with another version or compiler, I have found the VSCode CMake utilies very helpful

- [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=vector-of-bool.cmake-tools)

## Links
[CMake Visual Studio Guide](https://cognitivewaves.wordpress.com/cmake-and-visual-studio/#cmakelists-details)
[C++ Primer Exercises](https://github.com/jaege/Cpp-Primer-5th-Exercises)