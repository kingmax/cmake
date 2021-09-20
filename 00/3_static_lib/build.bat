md build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
REM cmake --build . --config release --verbose
cmake --build . --config release -v
cd ..
