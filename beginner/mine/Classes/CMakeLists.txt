set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

# Explicitly set a valid project name
project(beginner_course)

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

# Ensure the executable target has a valid name
add_executable(beginner_course_executable ${project_sources} ${project_headers})
