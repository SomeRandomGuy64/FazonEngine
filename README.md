# FazonEngine
This is my first game engine, initially based on The Cherno's game engine series but I plan to diverge from that quite early one with plans to add networking, ray tracing and Vulkan support from the start.
This engine will initially only be supported on Windows, although I plan to add Linux support at a later date. There are currently no plans for macOS support.

## Building (I've yet to test out building on multiple PCs so these instructions may be incorrect)
This engine uses CMake 3.30, earlier versions may work but have not been tested

First confirm you have CMake 3.30 installed. 
This engine was made with Visual Studio 2022 using C++23, I can only guarentee the engine will work using this setup.

### CMake
In the root of the project open PowerShell and input:
```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release
```
You can then open the project using Visual Studio

### CMake GUI
1. In the "Where is the source code:" text box input the path to the root of the project directory
2. In the "Where to build the binaries:" text box input the same path appended with "/build"
3. Click configure
4. If CMake asks you if it can create a build directory then click yes
5. Select Visual Studio 17 2022 as the Generator and then click "Ok"
6. Click Configure again
7. Click Generate
8. Click Open Project

## Issues
If you are experiencing any issues, whether that be running the code or building the project" please create an issue in the "Issues" section at the top of the page

## Pull requests
I will not be accepting any pull requests
