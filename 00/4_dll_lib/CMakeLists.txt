# 比较复杂
# 参考：https://dominoc925.blogspot.com/2016/08/use-cmake-to-help-build-and-use-windows.html

cmake_minimum_required(VERSION 3.20)

project(HELLO_SHARED_DLL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

# D:\git\cmake\00\4_dll_lib\src\main.cpp(1,10): fatal error C1083: 无法打开包括文件: “shared/hello.h”: No such file or directory
# [D:\git\cmake\00\4_dll_lib\build\hello_dll_bin.vcxproj]
include_directories(src/include)
# add_subdirectory(src/include)


############################################################
# Create a library
############################################################
# set(HELLO_SHARED_DLL_EXPORTS 1)
include (GenerateExportHeader)
add_library(hello_dll SHARED
	src/hello.cpp
)
# add_library(hello_dll src/hello.cpp)

GENERATE_EXPORT_HEADER(hello_dll
	BASE_NAME HELLO_DLL
	EXPORT_MACRO_NAME HELLO_SHARED_DLL_EXPORTS
	EXPORT_FILE_NAME HELLO_DLL_EXPORT.h
	STATIC_DEFINE ${BASE_NAME}_STATIC_DEFINE
)

# add_library(hello::dll ALIAS hello_dll)

set_target_properties(hello_dll PROPERTIES COMPILE_FLAGS -DLIBSHARED_AND_STATIC_STATIC_DEFINE
)

target_include_directories(hello_dll
	PUBLIC
		src/include
		HELLO_DLL_EXPORT.h
)

############################################################
# Create an executable
############################################################
add_executable(hello_dll_bin
	src/main.cpp
)

# target_link_libraries(hello_dll_bin hello::dll)
# LINK : fatal error LNK1181: 无法打开输入文件“Release\hello_dll.lib” [D:\git\cmake\00\4_dll_lib\build\hello_dll_bin.vcxproj]

# link the new hello_dll target with the hello_dll_bin target
target_link_directories(hello_dll_bin
	PRIVATE
		hello_dll
)

# main.obj : error LNK2019: 无法解析的外部符号 "public: void __cdecl Hello::print(void)" (?print@Hello@@QEAAXXZ)，该符号在函数 main 中被引用
# [D:\git\cmake\00\4_dll_lib\build\hello_dll_bin.vcxproj]
# D:\git\cmake\00\4_dll_lib\build\Release\hello_dll_bin.exe : fatal error LNK1120: 1 个无法解析的外部命令 [D:\git\cmake\00\4_dll_li
# b\build\hello_dll_bin.vcxproj]