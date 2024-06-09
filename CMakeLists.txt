cmake_minimum_required(VERSION 3.0)
project(mprpc)

#设置项目可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#设置项目库文件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#设置项目编译头文件搜索路径 -I
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
#设置项目库文件搜索路径 -L
link_directories(${PROJECT_SOURCE_DIR}/lib)
#包含mprpc 框架所有的相关代码
add_subdirectory(src)
#包含example中的所有代码
add_subdirectory(example)