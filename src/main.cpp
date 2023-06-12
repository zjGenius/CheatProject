#include <stdio.h>
#include <deque>
#include "func.h"
#include "paramRead.h"
#include "version_config.h"
#include "huffman.h"
#include "file_compress_huffman.h"
#include "log.h"
#include "container.h"
// #include "huffman1.h"
// #include"HuffmanCompressAndUn.h"

int main(void)
{
	printf("-----------------------------------------\n");
	printf("------------System Start!----------------\n");
#if USE_RELEASE_MODE
	printf("-----------VERSION: %d.%d.%d-----------\n", VERSION_MAJOR, VERSION_MINOR, VERSION_LEVEL3);
#else
	printf("------------VERSION:%s %s------------\n", PROJECT_NAME, COMPILE_TIME);
#endif
	printf("-----------------------------------------\n");

	// func(200);
	string inputFile = "/home/bekl/zhangjun/code/MyProject/output/CtrPulseResult.txt";
	string compressedFile_path = "/home/bekl/zhangjun/code/MyProject/output/";
	// string decompressedFile = "/home/bekl/zhangjun/code/MyProject/output/output.txt";
	string compressedFile;

	vector<string> file_vec = split(inputFile, '/');
	// printf("file_vec: %s\n",file_vec[file_vec.size() - 1].c_str());
	vector<string> file_name = split(file_vec[file_vec.size() - 1], '.');
	// printf("file_name: %s , %s\n",file_name[0].c_str(), file_name[1].c_str());

	compressedFile += compressedFile_path;
	compressedFile += file_name[0];
	compressedFile += ".hz.bin";

	printf("compressedFile: %s\n", compressedFile.c_str());

	int sum1 = 0, sum2 = 0, m = 5, n = 11;

	sum1 = (m + n) * (n - m + 1) / 2;

	for (int i = m; i <= n; i++)
	{
		sum2 += i;
	}

	// deque_test();
	// list_test();
	map_test(0);

	// printf("sum1:%d sum2:%d\n", sum1, sum2);

	// LOG_D("hello world sum1:%d sum2:%d\n", sum1, sum2);
	// LOG_I("hello world\n");
	// LOG_W("hello world\n");
	// LOG_E("hello world\n");

	// compressFile(inputFile, compressedFile);
	// decompressFile(compressedFile, decompressedFile);

	file_compress_huffman file_compress;
	// file_compress.compress_file(inputFile);
	// file_compress.un_compress_file(compressedFile);

	return 0;
}
