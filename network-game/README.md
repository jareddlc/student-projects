# network-game
This application consists of a game server and game client. The server written in C++ and Windows Forms, while the client uses C++ and the SDL library for the graphics, input, and network. The game allows for two clients to connect to a server and exchange data such that each client can display both players.

### Dependencies

##### Visual Studio 2017 Community
Visual Studio dev tools & services make app development easy for any platform & language

* SDL
    * SDL Image
    * SDL Net
* Desktop development with C++
    * MFC and ATL support (x86 and x64)

Project Properties

* VC++ Directories
    * Include Directories
        * $(SolutionDir)lib\include
    * Library Directories
        * $(SolutionDir)lib\x86\
* Linker
    * General
        * Additional Include Libraries
            * $(SolutionDir)lib\x86
    * Input
        * Additional Dependencies
            * SDL.lib
            * SDLmain.lib
            * SDL_image.lib
            * SDL_net.lib
    * System
        * Windows
* C/C++
    * Code Generation
        * Runtime Library
            * Multi-Threaded Debug DLL
    * General
        * Additional Include Libraries
            * $(SolutionDir)lib\include

Dont forget to copy the following files to the project or build directory
* SDL.lib
* SDLmain.lib
* SDL_image.lib
* SDL_net.lib

Note: This is a hack for Visual Studio 2017 (main.cpp), however there the SDL libraries where compiled with an earlier version of Visual Studio and some behavior has changed which prevent compilation of the game client

```
#pragma comment(lib, "legacy_stdio_definitions.lib")
extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; }
```
### Running

Run the executable
