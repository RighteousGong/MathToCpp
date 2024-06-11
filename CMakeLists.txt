# 设置cmake的最低版本要求为 3.16
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# 设置c++标准
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

project(BSModel
    LANGUAGES C CXX
)
# 设置安装路径
set(CMAKE_INSTALL_PREFIX "E:\\GraduationThesis\\Code\\BSModel\\install")

# 设置动态库的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# 添加子文件夹 add_subdirectory(文件夹名)
add_subdirectory(MathFunctions)

# 为项目添加可执行文件
add_executable(BSModel main.cpp)

# 向可执行文件中添加链接库 target_link_libraries(目标名称 PUBLIC 库名)
target_link_libraries(BSModel PUBLIC MathFunctions)

# 添加搜索目录
target_include_directories(BSModel PUBLIC
                        "${PROJECT_SOURCE_DIR}"
)

# 把程序安装到 install/bin目录下
install(TARGETS BSModel DESTINATION bin)