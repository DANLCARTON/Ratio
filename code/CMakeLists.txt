cmake_minimum_required(VERSION 3.13)

enable_testing()

add_executable(RatioTest src/main.cpp)
target_link_libraries(RatioTest gtest Ratio)
target_compile_features(RatioTest PRIVATE cxx_std_17)

add_test(NAME RatioTest COMMAND RatioTest)