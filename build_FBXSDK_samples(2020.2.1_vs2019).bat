mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A X64 -DFBX_SHARED=1 ..
cmake --build . --config Release
cd ../../../../bin/vs2019/Release
start UI_Example_ImportExport.exe