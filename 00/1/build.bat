mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A X64 ..
cmake --build . --config release
cd ..