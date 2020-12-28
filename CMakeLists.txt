project("HR")

cmake_minimum_required(VERSION 3.19.1)


include_directories(include)
include_directories(include/HR)



add_executable(HR
    src/main.cpp
    src/Employee.cpp
    src/HRMS.cpp
)


