# eXcel Tuition Center System

A DSTR project that we work.

## Requirements
- C++17
- Cmake
- Ninja

We use CMake and Ninja as our build system.

```sh
$ apt-get install ninja gcc cmake
```

## Building
Make sure you have GCC/G++ that have most of C++17 standard features set.

1. Create a folder named `build`: `mkdir build`
2. Enter the directory: `cd build`
3. Run `cmake .. -G Ninja`
4. Execute `ninja`

It should generate an executable inside `build/src/eXcelSystem.exe`

