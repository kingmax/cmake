md build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build . --config release --verbose
cd ..
