cmake_minimum_required(VERSION 3.10)    

project(calcproject)

set(SOURCE_FILES                       
    calculator.cpp
    test.cpp   
)

add_executable(trial  ${SOURCE_FILES})  

target_include_directories(trial PUBLIC CSlab)

target_link_libraries(trial -LCSlab)
