cmake_minimum_required(VERSION 3.17)

project(experiment1)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(out ${DIR_SRCS})
#add_executable(experiment1 main.cpp)