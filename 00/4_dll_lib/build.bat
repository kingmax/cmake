md build
cd build
cmake -G "Visual Studio 16 2019" -A x64 -DHELLO_SHARED_DLL_EXPORTS=1 ..
cmake --build . --config release
cd ..
