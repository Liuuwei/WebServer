cmake_minimum_required(VERSION 3.12)
project(http)

# 设置编译信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

#定义参与编译的源文件
aux_source_directory(. SRC_LIST)
add_executable(test ${SRC_LIST})