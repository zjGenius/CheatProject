#include <stdio.h>
#include <deque>
#include <pthread.h>
#include <assert.h>

#include "func.h"
#include "paramRead.h"
#include "version_config.h"
#include "huffman.h"
#include "file_compress_huffman.h"
#include "log.h"
#include "container.h"
// #include "l_opencv.h"
#include "IQTransmitCenter.h"
#include "IQRecvData.h"
// #include "context.h"
// #include "device.h"

#include "DesignPatterns.h"
#include "CPlusPlusPrimer.h"

#include "leetcode.h"
#include "AddressBook.h"
#include "WorkManager.h"
#include "HeimaDisplay.h"

#include "smartPointer.hpp"
// #include "huffman1.h"
// #include "HuffmanCompressAndUn.h"

pthread_t signal_IQRecv;

std::string ip = "127.0.0.1";
int port = 1122;
std::string readFile = "sig_pragma.dat";
std::string writeFile = "recv_IQIIO.dat";

/**
 * @brief udp接收大文件
 *
 * @param arg
 * @return void*
 */
void *Recv_relay(void *arg)
{
	IQRecv *recv_data = new IQRecv(ip, port);
	// WifiRelay *wifirelay = new WifiRelay(&target_info, target_mac);
	printf("\n-------IQRecv-------\n");
	while (1)
	{
		recv_data->recv_fun(writeFile);
	}
}

void heimaStudy()
{
	// 通讯录管理系统
	// AddressBook *addressSystem = new AddressBook();
	// addressSystem->startAddressSystem();

	HeimaDisplay heima;
	// heima.PolymorphicDisplay();
	// heima.ComputerDisplay();
	// heima.FileStreamDisplay();
	// heima.TemplateDisplay();
	heima.ScoringSystemDisplay();

	// using namespace workManagerSpace;
	// WorkManager *managerSysyem;
	// managerSysyem->startSystem();
}
void leetcodeStudy()
{
	LeedCode *lee = new LeedCode();
	// std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	// std::vector<int> nums = {3, 2, 2, 3};

	// lee->topic_1(nums, 9);
	// printf("20 bool:%d\n", lee->topic_20("{)}"));
	// printf("27 vector size:%d\n", lee->topic_27(nums, 2));
	// lee->topic_2682(5, 2);
	// printf("9 bool:%d\n", lee->topic_9(1234567899));
}

void DesignPatternsStudy()
{
	DesignPatterns *design = new DesignPatterns();
	// design->sampleFactory_display();
	// design->strategy_display();
	// design->decorator_display();
	// design->proxy_display();
	// design->factoryMethod_display();
	// design->prototype_display();
	// design->template_display();
	// design->appearance_display();
	// design->builder_display();
	// design->observer_display();
	// design->abstractFactory_display();
	// design->state_display();
	// design->adapter_display();
	// design->memento_display();
	// design->compsite_display();
	// design->bridge_display();
	// design->command_display();
	// design->responsibility_display();
	// design->mediator_display();
	// design->flyWeight_display();
	// design->interpreter_display();
	// design->visitor_display();
}

/**
 * @brief CPlusPlusPrimer 书籍案例
 */
void CPlusPlusPrimerStudy()
{
	CPlusPlusPrimer *cplusplus = new CPlusPlusPrimer();
	// cplusplus->chapter1_display();
	// cplusplus->chapter10_display();
	cplusplus->chapter12_display();
}

/**
 * @brief opencv学习
 */
void opencvStudy()
{
	// test_imge1();
	// test_imge2();
	// test_mat();
	// test_draw();
}

/**
 * @brief 文件压缩，通过哈夫曼树实现
 */
void fileCompressByHuffman()
{
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

	file_compress_huffman file_compress; // 成功案例
										 // file_compress.compress_file(inputFile);
										 // file_compress.un_compress_file(compressedFile);
}

/**
 * @brief 容器学习
 */
void containerStudy()
{
	cout << "容器学习" << endl;
	// deque_test();
	// list_test();
	// map_test(0);
	// set_test(2);
	// STL_test();
	// predicateOne_test();
	// predicateTwo_test();
	// functional_test1();
	// functional_test2();
	// functional_test3();

	// algorithm_for();
	// algorithm_find_example();
	// algorithm_sort_example();
	// algorithm_copy_replace_example();
	// numeric_example();
	setContainer_example();
	cout << endl;
}

// 错误的写法，默认参数有误
// void test(int a, int b = 10, int c)
// {
// 	printf("sum:%d\n", a + b + c);
// }

int main(void)
{
	printf("-----------------------------------------\n");
	printf("------------System Start!----------------\n");
#if USE_RELEASE_MODE
	printf("------------VERSION: %d.%d.%d---------------\n", VERSION_MAJOR, VERSION_MINOR, VERSION_LEVEL3);
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

	/***************容器类学习********************/
	// containerStudy();

	/***************opencv学习********************/
	// opencvStudy();

	/***************等级打印********************/
	// LOG_D("hello world sum1:%d sum2:%d\n", sum1, sum2);
	// LOG_I("hello world\n");
	// LOG_W("hello world\n");
	// LOG_E("hello world\n");

	/***************Huffman文件压缩********************/
	// fileCompressByHuffman();

	/******************udp传输文件  坤雷科技*********************/
	// pthread_create(&signal_IQRecv, NULL, *Recv_relay, NULL);

	// IQTransmit *transmit = new IQTransmit(ip, port);
	// int mode;
	// printf("请选择发送模式： \n 0-文件模式 1-iio模式:  ");
	// scanf("%d", &mode);
	// transmit->sendMode(mode, readFile);

	// sleep(2);
	// transmit->readIQFile(writeFile);

	// std::string ip = "ip:192.168.100.10";
	// Context *context = new Context(ip);
	// if (context->context() == nullptr)
	// {
	// 	printf("connect %s error\n", ip.c_str());
	// 	return 0;
	// }
	// Device *pDev = new Device(context);
	// if (pDev == nullptr)
	// {
	// 	delete context;
	// 	printf("make Device error\n");
	// 	return 0;
	// }
	// uint32_t data = 0;
	// pDev->alarm(data, 0);
	// printf("alarm:%08X\n", data);

	// pDev->set_rx_lo_frequency(2450 * 1000 );
	// pDev->set_rx_samplerate(61.44 * 1000 * 1000, 0);
	// pDev->set_rx_bandwidth(61.44 * 1000 * 1000, 0);
	// pDev->set_rx_gain(30, 0);

	// usleep(50);
	// pDev->_getIQData();

	/******************设计模式************************/
	// DesignPatternsStudy();

	/******************C++ Primer 第五版************************/
	CPlusPlusPrimerStudy();

	/******************LeedCode************************/
	// leetcodeStudy();

	// printf("\n\nnum:%d\n", 7 % 5);

	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	// for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	// {
	// 	printf("num:%d\n", *arr + i);
	// }

	/******************黑马教程************************/
	// heimaStudy();

	// 阶乘定义：3! = 3*2*1
	// 按照这个思路
	// cout << "请输入数值：" << endl;
	// int num, result = 1;
	// cin >> num;
	// printf("result: %d!= ", num);
	// for (int i = num; i > 0; i--)
	// {
	// 	result *= i;
	// 	if (i == 1)
	// 		printf("%d", i);
	// 	else
	// 		printf("%d*", i);
	// }
	// printf(" =%d\n", result);

	constexpr size_t sz = 5;
	int arr[sz] = {1, 2, 3, 4, 5};
	int *arrp = arr;

	cout << "sizeof sz:" << sizeof(sz) << endl;		// long 8
	cout << "sizeof arr:" << sizeof(arr) << endl;	// （int) 4 * 5 = 20
	cout << "sizeof arrp:" << sizeof(arrp) << endl; // long 8

	int aa = 5;
	int *aaa = &aa;
	cout << "sizeof aa:" << sizeof(aa) << " aaa:" << sizeof(aaa) << endl; // int 4 , int * 8

	char bb = '1';
	char *bbb = &bb;
	cout << "sizeof bb:" << sizeof(bb) << " bbb:" << sizeof(bbb) << endl; // char 1 , char * 8

	float cc = 1.2f;
	float *ccc = &cc;
	cout << "sizeof cc:" << sizeof(cc) << " ccc:" << sizeof(ccc) << endl;

	double dd = 1.2f;
	double *ddd = &dd;
	cout << "sizeof dd:" << sizeof(dd) << " ddd:" << sizeof(ddd) << endl;

	long long ee = 1;
	long long *eee = &ee;
	cout << "sizeof ee:" << sizeof(ee) << " eee:" << sizeof(eee) << endl;

	int ia[3][4] = {{1, 2}, 3, 4, 5};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (auto &as : ia)
	{
		for (auto &ass : as)
		{
			cout << ass << " ";
		}
		cout << endl;
	}

	return 0;
}