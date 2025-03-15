# FazonEngine
This is my first game engine, initially based on The Cherno's game engine series but I plan to diverge from that quite early one with plans to implement my own physics engine, map editor, sprite editor and shading language.
This engine will initially only be supported on Windows, although I plan to add Linux support at a later date. macOS support is planned for the (far) future but will have to wait until I can get my hands on a Mac mini, macOS will **only** support the Metal rendering API.

## Building
This engine uses CMake 3.30, earlier versions may work but have not been tested

To clone this repository use 

```git clone --recursive git@github.com:SomeRandomGuy64/FazonEngine.git```

or 

```git clone --recursive https://github.com/SomeRandomGuy64/FazonEngine.git``` 

to make sure that you clone every git submodule.

First confirm you have CMake 3.30 installed. 
This engine was made with Visual Studio 2022 using C++23, I can only guarentee the engine will work using this setup.

### CMake
In the root of the project open PowerShell and input:
```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug
```
You can then open the project using Visual Studio

Note that Release and Dist builds don't work at the moment, they will be fixed soon

### CMake GUI
1. In the "Where is the source code:" text box input the path to the root of the project directory
2. In the "Where to build the binaries:" text box input the same path appended with "/build"
3. Click configure
4. If CMake asks you if it can create a build directory then click yes
5. Select Visual Studio 17 2022 as the Generator and then click "Ok"
6. Click Configure again
7. Click Generate
8. Click Open Project

### Running
If it isn't already, make sure that Sandox is set as the startup project by right-clicking Sandbox where the projects are listed and then clicking "Set as startup project"
You can now run through the debugger or build with F7

## Issues
If you are experiencing any issues, whether that be running the code or building the project" please create an issue in the "Issues" section at the top of the page

## Pull requests
I will not be accepting any pull requests
