cmake_minimum_required(VERSION 3.10)

# set project name and version
project(helloWorld VERSION 1.0)

# configure a header file to pass the version number to the source code, 
# need header template to gen header file
# 注意: CMakeLists.txt里定义的ProjectName是什么,头文件模板中定义的版本号前面要保持完全一致！包括大小写！
# configure_file(src/helloWorld.h.in src/helloWorld.h)

# gen head file from in-template
configure_file(
	"${PROJECT_SOURCE_DIR}/src/helloWorld.h.in"
	"${PROJECT_SOURCE_DIR}/src/helloWorld.h"	
)

# include
include_directories("${PROJECT_BINARY_DIR}")

# specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(helloWorld src/helloWorld.cpp)

# Since the configured file will be written into the binary tree, we must add that directory to the list
# of paths to search for include files
target_include_directories(helloWorld PUBLIC "${PROJECT_BINARY_DIR}")