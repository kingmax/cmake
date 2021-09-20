cmake_minimum_required(VERSION 3.20)

project(hello_static_lib)

############################################################
# Create a library
############################################################
# Generate the static library from the source sources
add_library(hello_library STATIC
		src/hello.cpp
)

target_include_directories(hello_library
	PUBLIC
		${PROJECT_SOURCE_DIR}/src/include
)

############################################################
# Create an executable
############################################################
# add an executable with the above sources
add_executable(hello_binary
	src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries(hello_binary
	PRIVATE
		hello_library
)
