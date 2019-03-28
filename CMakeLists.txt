
cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Bridge VERSION 0.1 
                  DESCRIPTION "Bridge"
                  LANGUAGES CXX)


add_library(project_options INTERFACE)
add_library(project_warnings INTERFACE)
add_library(bridge STATIC bridge.cpp bridge.hpp)
add_executable(test test.cpp)
target_compile_features(project_options INTERFACE cxx_std_17)
target_include_directories(bridge PRIVATE ${CONAN_INCLUDE_DIRS})
# Taken from: https://github.com/lefticus/cpp_box
target_compile_options(project_warnings
                         INTERFACE -Wall
                                   -Werror # treat all warnings as errors
                                   -Wextra # reasonable and standard
                                   -Wshadow # warn the user if a variable
                                            # declaration shadows one from a
                                            # parent context
                                   -Wnon-virtual-dtor # warn the user if a class
                                                      # with virtual functions
                                                      # has a non-virtual
                                                      # destructor. This helps
                                                      # catch hard to track down
                                                      # memory errors
                                   -Wold-style-cast # warn for c-style casts
                                   -Wcast-align # warn for potential performance
                                                # problem casts
                                   -Wunused # warn on anything being unused
                                   -Woverloaded-virtual # warn if you overload
                                                        # (not override) a
                                                        # virtual function
                                   -Wpedantic # warn if non-standard C++ is used
                                   -Wconversion # warn on type conversions that
                                                # may lose data
                                   -Wsign-conversion # warn on sign conversions
                                   -Wnull-dereference # warn if a null
                                                      # dereference is detected
                                   -Wdouble-promotion # warn if float is
                                                      # implicit promoted to
                                                      # double
                                   -Wformat=2 # warn on security issues around
                                              # functions that format output (ie
                                              # printf)

                         )
# Taken from https://github.com/ChaiScript/ChaiScript/blob/develop/.travis.yml
#
# Load Conan
#

# if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#   message(
#     STATUS
#       "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
#   file(
#     DOWNLOAD
#       "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.12/conan.cmake"
#       "${CMAKE_BINARY_DIR}/conan.cmake")
# endif()
# 
# include(${CMAKE_BINARY_DIR}/conan.cmake)
# conan_check(REQUIRED)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


target_link_libraries(test
    PRIVATE project_options project_warnings bridge)
	
