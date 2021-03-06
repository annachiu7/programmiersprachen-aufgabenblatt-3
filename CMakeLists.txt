cmake_minimum_required(VERSION 2.8)
project(blatt2)

if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel") AND UNIX))
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++14 -Wall")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  set(CMAKE_CXX_FLAGS "-std=c++14 -Wall")
endif()

# Add externals
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external)
add_definitions(-DGLEW_STATIC)


# Use catch for testing
set(CATCH_DIRECTORY catch-1.1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${CATCH_DIRECTORY})

if(MSVC)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/build/)
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(COPY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/build/Debug/)
  else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(COPY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/build/Release/)
  endif(CMAKE_BUILD_TYPE STREQUAL "Debug")
else(MSVC)
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
  else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
  endif(CMAKE_BUILD_TYPE STREQUAL "Debug")
endif(MSVC)

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

add_subdirectory(source)
