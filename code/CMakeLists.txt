cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXE_LINKER_FLAGS "-lrt")

# give a name to the project
project(RatioTest)

# file to compile and name of the executable
# add_executable(simpleProject src/main.cpp src/plop.cpp include/plop.hpp)
add_executable(RatioTest src/main.cpp)

# include directory
target_include_directories(RatioTest PRIVATE "include")
target_include_directories(RatioTest PRIVATE "include")

# compilation options
# target_compile_features(simpleProject PRIVATE cxx_std_11) # use at least c++ 11
target_compile_features(RatioTest PRIVATE cxx_std_17) # use at least c++ 17

# for each sample file, make an exe
foreach(src_file ${src_files_list})

    get_filename_component(file_exe ${src_file} NAME_WE)    # define te name of the app (filename Without Extension)
    add_executable(${file_exe} ${src_file})                 # file to compile and name of the app
    target_link_libraries(${file_exe} PRIVATE Ratio)      # lib dependency
    target_compile_features(${file_exe} PRIVATE cxx_std_17) # use at least c++ 17
    if (MSVC)
        target_compile_options(${file_exe} PRIVATE /W3)
    else()
        target_compile_options(${file_exe} PRIVATE -Wall -02 -Wextra -Wpedantic -pedantic-errors)
    endif()

    message(STATUS "src file  " ${src_file})
    message(STATUS "exe file  " ${file_exe})

endforeach()


if (MSVC)
    # target_compile_options(simpleProject PRIVATE /W3)
    target_compile_options(RatioTest PRIVATE /W3)
else()
    # target_compile_options(simpleProject PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
    target_compile_options(RatioTest PRIVATE -Wall -O2 -Wextra -Wpedantic -pedantic-errors)
endif()

