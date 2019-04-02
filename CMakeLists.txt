
cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Bridge VERSION 0.1 
                  DESCRIPTION "Bridge"
                  LANGUAGES CXX)

add_library(project_options INTERFACE)
add_library(project_warnings INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)
target_include_directories(project_options INTERFACE include external)

# Taken from: https://github.com/lefticus/cpp_box
if(MSVC)
  add_definitions(/W4 /w14545 /w34242 /w34254 /w34287 /w44263 /w44265 /w44296 /w44311 /w44826 /we4289 /w14546 /w14547 /w14549 /w14555 /w14619 /w14905 /w14906 /w14928 /WX "/permissive-")
  add_definitions(/std:c++17)
  # target_compile_options(project_options INTERFACE /std:c++17)
  # target_compile_options(project_warnings INTERFACE /W4 /WX "/permissive-")
else()
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
                                    -Weffc++ # Hopefully gives some helpful style warnings
                                    -Og # Some warnings only show up under optimization

                         )
endif()
# Taken from https://github.com/ChaiScript/ChaiScript/blob/develop/.travis.yml
#
# Load Conan
#
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(
    STATUS
      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(
    DOWNLOAD
      "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.13/conan.cmake"
      "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(REQUIRED)
conan_cmake_run(CONANFILE
                conanfile.txt
                BASIC_SETUP
                CONAN_COMMAND
                ${CONAN_CMD}
                CMAKE_TARGETS
                BUILD
                missing)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(gsl_microsoft)
find_package(catch2)

# add_library(bridge STATIC bridge.cpp bridge.hpp)
# target_link_libraries(bridge PUBLIC gsl_microsoft::gsl_microsoft PRIVATE project_options project_warnings)
add_executable(test_main test.cpp test_bridge.cpp)

target_link_libraries(test_main
    PRIVATE project_options project_warnings catch2::catch2 gsl_microsoft::gsl_microsoft)

include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)

enable_testing()
catch_discover_tests(test_main)
