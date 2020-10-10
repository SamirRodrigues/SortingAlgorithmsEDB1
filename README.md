To compile this project with [cmake](https://cmake.org) follow these steps:

1. `cd quick-sort`: enters into the main project directory.
2. `cmake -S . -Bbuild`:  asks cmake to create the build directory and generate the Unix Makefile based on the script found in `CMakeLists.txt`, on the current level.
3. `cd build`: enter the build folder.
5. `cmake --build .` or `make`: triggers the compiling process.