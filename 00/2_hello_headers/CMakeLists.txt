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