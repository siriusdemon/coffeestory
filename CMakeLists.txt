cmake_minimum_required(VERSION 3.20) 

project(coffeestory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories("D:\\softwares\\opencv\\opencv\\build\\include\\")
add_executable("coffeestory" "coffeestory.cpp")
target_link_libraries(coffeestory "D:\\softwares\\opencv\\opencv\\build\\x64\\vc16\\lib\\opencv_world480.lib")







