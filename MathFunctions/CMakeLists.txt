# 创建链接库 add_library(库名 源文件 头文件(可选放))
add_library(MathFunctions SHARED OptionFunctions.cpp)

# 添加搜索目录
target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# 安装库文件到libs目录下
set(installl_libs MathFunctions)
install(TARGETS ${installl_libs} DESTINATION libs)

# 把库文件对应的头文件安装到include文件下
install(FILES OptionFunctions.h DESTINATION include)