# CatUnlocker

A C++ system utility designed for Windows maintenance and security. Developed using WinAPI and C++17 standards.

## Features
- **Logo Animation**: Sequential ASCII-art rendering on startup.
- **Temp Cleaner**: Automated removal of Windows temporary files using std::filesystem.
- **Registry Fixer**: Verification and restoration of the Winlogon\Userinit key to protect against common persistence threats.
- **Input Validation**: Robust handling of invalid console input to prevent program crashes.

## Build Instructions (Visual Studio)

Follow these steps to compile the project:

1. **Clone or Download**: Obtain the source code and open the folder.
2. **Open Solution**: Launch Visual Studio (2019/2022) and open the .sln file.
3. **Configure Project**:
   - Set the configuration to Release and the platform to x64.
   - Go to Project Properties -> C/C++ -> Language.
   - Set C++ Language Standard to ISO C++17 Standard (/std:c++17) or higher.
4. **Build**:
   - Press Ctrl + Shift + B or navigate to Build -> Build Solution.
5. **Output**:
   - The compiled executable will be located in the x64/Release/ directory.

Note: Administrative privileges are required for registry modification functions to execute correctly.

## Project Structure
- main.cpp: Entry point, command loop, and menu logic.
- /functions: Implementation of system cleanup and registry logic.
- /heading: Header files containing function prototypes and ASCII definitions.

## Disclaimer
This tool modifies system registry keys and deletes files. The author is not responsible for any system damage. Use at your own risk.
