#include <stdio.h>
#include <deque>
#include "func.h"
#include "paramRead.h"
#include "version_config.h"
#include "huffman.h"
#include "file_compress_huffman.h"
#include "log.h"
#include "container.h"
#include "l_opencv.h"
#include "SampleFactory.h"
#include "Strategy.h"
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
	printf("-----------------------------------------\n\n");

	/***************读取ini文件********************/
	// func(200);
	/**************累加运算********************/
	int sum1 = 0, sum2 = 0, m = 5, n = 11;
	sum1 = (m + n) * (n - m + 1) / 2;
	for (int i = m; i <= n; i++)
	{
		sum2 += i;
	}
	// printf("sum1:%d sum2:%d\n", sum1, sum2);

	/***************容器********************/
	// deque_test();
	// list_test();
	// map_test(0);
	// set_test(2);

	/***************opencv********************/
	// test_imge1();
	// test_imge2();
	// test_mat();
	// test_draw();

	/***************等级打印********************/
	// LOG_D("hello world sum1:%d sum2:%d\n", sum1, sum2);
	// LOG_I("hello world\n");
	// LOG_W("hello world\n");
	// LOG_E("hello world\n");

	/***************Huffman文件压缩********************/
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

	// compressFile(inputFile, compressedFile);
	// decompressFile(compressedFile, decompressedFile);

	file_compress_huffman file_compress;
	// file_compress.compress_file(inputFile);
	// file_compress.un_compress_file(compressedFile);

	/***************简单的工厂模式 实现加减乘除********************/
	// Operation *oper;
	// oper = OperationFactory::createOperate('/');
	// oper->setNumberA(10.2);
	// oper->setNumberB(2.2);
	// double result_num = oper->getResult();

	// printf("result_num:%lf\n", result_num);

	/***************简单的策略模式 商场促销案例********************/
	double result = 0.0;
	int mode = 0;
	double all_money = 0.0;
	CashContext *csuper = new CashContext();
main_function:
	printf("请选择促销模式： \n 0-普通模式 1-返现模式 2-打折模式:  ");
	scanf("%d", &mode);
	switch (mode)
	{
	case MyType::Normal:
	{
		csuper->CreateContext(MyType::Normal);
	}
	break;
	case MyType::Return:
	{
		double amount = 0.0, return_amount = 0.0;
		printf("请输入满减金额与返现金额 (格式:[满减金额,返现金额])  ");
		scanf("%lf,%lf", &amount, &return_amount);
		csuper->SetDiscount(amount, return_amount);
		csuper->CreateContext(MyType::Return);
	}
	break;
	case MyType::Rebate:
	{
		double discount = 0.0;
		printf("请输入折扣 (备注:0.8代表8折)  ");
		scanf("%lf", &discount);
		csuper->SetDiscount(discount);
		csuper->CreateContext(MyType::Rebate);
	}
	break;
	default:
		printf("\n**********输入类型有误!!!\n\n");
		goto main_function;
		break;
	}
	printf("请输入金额: ");
	scanf("%lf", &all_money);
	result = csuper->getResult(all_money);
	printf("最终金额: %.1lf\n", result);















	return 0;
}