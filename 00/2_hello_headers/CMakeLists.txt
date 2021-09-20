cmake_minimum_required(VERSION 3.20)

project(hello_headers)

# all cpp files
set(SOURCES
	src/hello.cpp
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${PROJECT_SOURCE_DIR}/src/include
)

# https://github.com/kingmax/cmake-examples/tree/master/01-basic/B-hello-headers
# Variable	Info
# CMAKE_SOURCE_DIR

# The root source directory

# CMAKE_CURRENT_SOURCE_DIR

# The current source directory if using sub-projects and directories.

# PROJECT_SOURCE_DIR

# The source directory of the current cmake project.

# CMAKE_BINARY_DIR

# The root binary / build directory. This is the directory where you ran the cmake command.

# CMAKE_CURRENT_BINARY_DIR

# The build directory you are currently in.

# PROJECT_BINARY_DIR

# The build directory for the current project.