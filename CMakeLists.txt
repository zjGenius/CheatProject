cmake_minimum_required(VERSION 2.5)

if(COMMAND cmake_policy)
cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

set(DEBUG_VERSION "DebugMode")
set(RELEASE_VERSION "ReleaseMode")
set(COMPILE_MODE ${DebugMode})            # 编译模式
set(TARGET_NAME "myproject")              # 目标可执行程序名称
string(TIMESTAMP COMPILE_TIME %m%d_%H%M)        # 生成编译时间

# Debug模式（目标：工程名+编译时间）
if(${COMPILE_MODE} MATCHES ${DEBUG_VERSION})   
    message(STATUS "Compile mode: ${COMPILE_MODE}")
    set(USE_RELEASE_MODE 0)
    set(CMAKE_BUILD_TYPE "Debug")
    set(target ${TARGET_NAME}_${COMPILE_TIME})
# Release模式（目标：工程名+版本号）
else()
    message(STATUS "Compile mode: ${COMPILE_MODE}")
    set(USE_RELEASE_MODE 1)
    set(CMAKE_BUILD_TYPE "Release") 
    set(VERSION_MAJOR  0)    # 一级版本号
    set(VERSION_MINOR  0)    # 二级版本号
    set(VERSION_LEVEL3 1)    # 三级版本号
    message(STATUS "USE_RELEASE_MODE: ${USE_RELEASE_MODE}")
    set(target ${TARGET_NAME}_V${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_LEVEL3})
endif()

project(ExternalPlugIn)
set(CMAKE_BUILD_TYPE "Debug")
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

configure_file("version_config.h.in"  "../include/version_config.h")

execute_process(
    COMMAND echo "copy ini file"
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/version.ini ${PROJECT_BINARY_DIR}/version.ini
)


#添加.h文件
include_directories(./include)
include_directories(./include/Huffman)
include_directories(./include/Learn)
include_directories(./include/NetWork)

include_directories(./include/DesignPatterns)
include_directories(./include/DesignPatterns/Factory)
include_directories(./include/DesignPatterns/Strategy)
include_directories(./include/DesignPatterns/Decorator)
include_directories(./include/DesignPatterns/Proxy)
include_directories(./include/DesignPatterns/FactoryMethod)
include_directories(./include/DesignPatterns/Prototype)
include_directories(./include/DesignPatterns/Template)
include_directories(./include/DesignPatterns/Appearance)
include_directories(./include/DesignPatterns/Builder)
include_directories(./include/DesignPatterns/Observer)
include_directories(./include/DesignPatterns/AbstractFactory)
include_directories(./include/DesignPatterns/State)
include_directories(./include/DesignPatterns/Adapter)
include_directories(./include/DesignPatterns/Memento)
include_directories(./include/DesignPatterns/Composite)
include_directories(./include/DesignPatterns/Bridge)
include_directories(./include/DesignPatterns/Command)
include_directories(./include/DesignPatterns/Responsibility)
include_directories(./include/DesignPatterns/Mediator)
include_directories(./include/DesignPatterns/FlyWeight)
include_directories(./include/DesignPatterns/Interpreter)
include_directories(./include/DesignPatterns/Visitor)

include_directories(./include/CPlusPlusPrimer)
include_directories(./include/CPlusPlusPrimer/Chapter1)
include_directories(./include/CPlusPlusPrimer/Chapter10)
include_directories(./include/CPlusPlusPrimer/Chapter12)

include_directories(include/Leetcode)
include_directories(include/Learn)
include_directories(include/Learn/heima)
include_directories(include/Learn/heima/operator)
include_directories(include/Learn/heima/polymorphic)
include_directories(include/Learn/heima/FileStream)
include_directories(include/Learn/heima/Template)
include_directories(include/Learn/heima/ScoringSystem)
# include_directories(./include/SDR)
# include_directories(./include/3rdparty)
# include_directories(./include/Tools)



#添加.c文件
aux_source_directory(./src SRC_LIST)
list(REMOVE_ITEM SRC_LIST "main.cpp")
aux_source_directory(./src/Huffman SRC_LIST)
aux_source_directory(./src/Learn SRC_LIST)
aux_source_directory(./src/Learn/heima SRC_LIST)
aux_source_directory(./src/Learn/heima/operator SRC_LIST)
aux_source_directory(./src/Learn/heima/FileStream SRC_LIST)
aux_source_directory(./src/Learn/heima/Template SRC_LIST)
aux_source_directory(./src/Learn/heima/ScoringSystem SRC_LIST)
aux_source_directory(./src/NetWork SRC_LIST)
aux_source_directory(./src/DesignPatterns SRC_LIST)
aux_source_directory(./src/DesignPatterns/Factory SRC_LIST)
aux_source_directory(./src/DesignPatterns/Strategy SRC_LIST)
aux_source_directory(./src/DesignPatterns/Decorator SRC_LIST)
aux_source_directory(./src/DesignPatterns/Proxy SRC_LIST)
aux_source_directory(./src/DesignPatterns/FactoryMethod SRC_LIST)
aux_source_directory(./src/DesignPatterns/State SRC_LIST)

aux_source_directory(./src/CPlusPlusPrimer SRC_LIST)
aux_source_directory(./src/CPlusPlusPrimer/Chapter1 SRC_LIST)
aux_source_directory(./src/CPlusPlusPrimer/Chapter10 SRC_LIST)
aux_source_directory(./src/CPlusPlusPrimer/Chapter12 SRC_LIST)

aux_source_directory(src/Leetcode SRC_LIST)
# aux_source_directory(./src/SDR SRC_LIST)


#打印src信息
message(STATUS "${SRC_LIST}" )
#该条指令告诉 CMake 创建可执行文件所使用的源文件
add_executable(ExternalPlugIn ${SRC_LIST})


# 操作系统架构
message(${CMAKE_HOST_SYSTEM_PROCESSOR})

# if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "armv7l")
#     # 寻找OpenCV库
#     find_package( OpenCV REQUIRED )
#     # 添加头文件
#     include_directories( ${OpenCV_INCLUDE_DIRS} )
#     # 链接OpenCV库
#     target_link_libraries( ExternalPlugIn ${OpenCV_LIBS} )
# elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
#     # set(CMAKE_CXX_FLAGS "-fsanitize=address  -g")
#     # set(CMAKE_EXE_LINKER_FLAGS "-fsanitize=address -static-libasan")
#     find_package( OpenCV 4 REQUIRED )
#     include_directories( ${OpenCV_INCLUDE_DIRS} )
#     target_link_libraries( ExternalPlugIn ${OpenCV_LIBS} )
# else()
#     # set(CMAKE_CXX_FLAGS "-fsanitize=address  -g")
#     # set(CMAKE_EXE_LINKER_FLAGS "-fsanitize=address -static-libasan")
#     find_package( OpenCV REQUIRED )
#     include_directories( ${OpenCV_INCLUDE_DIRS} )
#     target_link_libraries( ExternalPlugIn ${OpenCV_LIBS} )
# endif()

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++14 -O0" )



#链接库
TARGET_LINK_LIBRARIES( ExternalPlugIn pthread )
# TARGET_LINK_LIBRARIES( ExternalPlugIn pthread iio )
#TARGET_LINK_LIBRARIES( E310 pthread iio gprofHelp_cxx)