/*********************************************************************************
 *Author:
 *Date:                2021.11.12
 *Description:         实现有等级有颜色的log输出
 **********************************************************************************/
#ifndef __LOG_H__
#define __LOG_H__

#include <string.h>

/************************************配置区***************************************/
// 配置输出接口
#include <stdio.h>
#define LOG_PRINT(format, ...) printf(format, ##__VA_ARGS__)

// 选择LOG等级 低于此等级的LOG不会打印
#define CURRENT_LOG_LEVEL LOG_LEVEL_DEBUG

// 输出__FILE__文件名时可能带有很长的路径 只需要文件名就行了
// 地址分隔符  Linux中是正斜杠'/'  Windows中是反斜杠'\'
#define PATH_SEPARATOR '/'
/************************************end*****************************************/

typedef enum
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERR,
} LOG_LEVEL;

// 颜色代码
#define LOG_COLOUR_BLACK "\x1B[2;30m"
#define LOG_COLOUR_RED "\x1B[2;31m"
#define LOG_COLOUR_GREEN "\x1B[2;32m"
#define LOG_COLOUR_YELLOW "\x1B[2;33m"
#define LOG_COLOUR_BLUE "\x1B[2;34m"
#define LOG_COLOUR_MAGENTA "\x1B[2;35m"
#define LOG_COLOUR_CYAN "\x1B[2;36m"
#define LOG_COLOUR_WHITE "\x1B[2;37m"

#define LOG_COLOUR_RESET "\x1B[0m"

// 去掉__FILE__中的路径
#define GET_FILE_NAME(path) strrchr(path, PATH_SEPARATOR) ? strrchr(path, PATH_SEPARATOR) + 1 : path

// 调试log输出 青色
#define LOG_D(format, ...)                                                                                                     \
    if (CURRENT_LOG_LEVEL <= LOG_LEVEL_DEBUG)                                                                                  \
    {                                                                                                                          \
        LOG_PRINT(LOG_COLOUR_CYAN "[DEBUG %s %d] " LOG_COLOUR_RESET format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__); \
    }

// 信息log输出 绿色
#define LOG_I(format, ...)                                                                                                      \
    if (CURRENT_LOG_LEVEL <= LOG_LEVEL_INFO)                                                                                    \
    {                                                                                                                           \
        LOG_PRINT(LOG_COLOUR_GREEN "[INFO  %s %d] " LOG_COLOUR_RESET format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__); \
    }

// 警告log输出 黄色
#define LOG_W(format, ...)                                                                                                       \
    if (CURRENT_LOG_LEVEL <= LOG_LEVEL_WARN)                                                                                     \
    {                                                                                                                            \
        LOG_PRINT(LOG_COLOUR_YELLOW "[WARN  %s %d] " LOG_COLOUR_RESET format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__); \
    }

// 错误log输出 红色
#define LOG_E(format, ...)                                                                                                    \
    if (CURRENT_LOG_LEVEL <= LOG_LEVEL_ERR)                                                                                   \
    {                                                                                                                         \
        LOG_PRINT(LOG_COLOUR_RED "[ERROR %s %d] " LOG_COLOUR_RESET format, GET_FILE_NAME(__FILE__), __LINE__, ##__VA_ARGS__); \
    }

#define LOG_RED(format, ...) \
    printf(LOG_COLOUR_RED format LOG_COLOUR_RESET, ##__VA_ARGS__);

#define LOG_GREEN(format, ...) \
    printf(LOG_COLOUR_GREEN format LOG_COLOUR_RESET, ##__VA_ARGS__);

#endif
