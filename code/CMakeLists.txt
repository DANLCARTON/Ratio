cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXE_LINKER_FLAGS "-lrt")

# give a name to the project
project(RatioTest)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

# file to compile and name of the executable
add_executable(RatioTest src/main.cpp)

# include directory
target_include_directories(RatioTest PRIVATE "include")

target_link_libraries(RatioTest PRIVATE Ratio)      # lib dependency
target_link_libraries(RatioTest PUBLIC GTest::GTest GTest::Main)

# include directory
target_include_directories(RatioTest PRIVATE "include")
target_include_directories(RatioTest PRIVATE "include")

# compilation options
target_compile_features(RatioTest PRIVATE cxx_std_17) # use at least c++ 17

if (MSVC)
    # target_compile_options(simpleProject PRIVATE /W3)
    target_compile_options(RatioTest PRIVATE /W3)
else()
    # target_compile_options(simpleProject PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
    target_compile_options(RatioTest PRIVATE -Wall -O2 -Wextra -Wpedantic -pedantic-errors)
endif()

