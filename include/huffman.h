#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
#include "paramRead.h"

using namespace std;

void compressFile(const string &inputFile, const string &outputFile); // 解压缩
void decompressFile(const string &inputFile, const string &outputFile);   // 压缩


#endif