/**
 * @file FileStream.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 文件流学习
 * @version 0.1
 * @date 2023-08-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <fstream>
#include <iostream>

namespace filestream
{
    struct Person
    {
        char mName[64];
        int mAge;
    };

    class FileStream
    {
    private:
        /* data */
    public:
        FileStream();
        ~FileStream();

        void saveTxtFile(char *filename);
        void readTxtFile(char *filename);

        void saveBinaryFile(char *filename);
        void readBinaryFile(char *filename);

        void fileIsEmpty(char *filename);
    };

}