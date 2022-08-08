# Fall 2021 - PA03 - Mystery Sort

Resume formatted version of Data Structures Project 3. The project provides 5 unnamed/encrypted sorting algorithms and tasks you to use their Big-O notation to determine which searching algorithm is which. You then narrow down the O(n^2) algorithms by running the extreme test cases and seeing how each responds. This was done by testing, and comparing, the speed of which each algorithm sorts (a 5 sort average), at varying data sizes.

## Important

In order for the project to link against the correct version of the myster_sorter library, you need to set
a CMAKE environment variable.  To do this, Choose **Settings** from the File Menu.  In the left-side tree, 
choose **Build, Execution, Deployment** > **CMake**.  In the **Environment** field (circled in yellow in the 
screencap below), add `PLATFORM=wsl2` if you're on Windows using WSL OR add `PLATFORM=mac` if you're on a mac. 

![cmake_settings](img/cmake_settings.png)

- The `include` directory contains a .h file with 5 mystery sort algorithm function declarations
- The `lib` folder contains a static link library that has the implementations of those 5 sorts. There's a version for WSL and a version for mac. 

