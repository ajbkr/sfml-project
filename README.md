SFML Project
============

Based on the examples developed in the [Zenva](https://academy.zenva.com/) course
[Discover SFML for C++ Game Development](https://academy.zenva.com/product/discover-sfml-for-c-game-development/).

Prerequisites
-------------

Install [CMake](https://cmake.org/) version 3.16 or higher.

```
$ sudo apt-get install cmake
```

Install [vcpkg](https://vcpkg.io/).

See the vcpkg Web site for installation instructions.

Install [SFML](https://www.sfml-dev.org/).

```
$ vcpkg install sfml
```

Build
-----

```
$ mkdir build
$ cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake
$ cd build
$ cmake --build .
```

Run
---

```
$ ./run.sh
```
