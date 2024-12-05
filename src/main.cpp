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
#include "ShareMemery.h"
#include "CallBackFuntion.h"
#include "ImplBook.h"
#include "Design_guanchazhe.hpp"
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

	// std::vector<int> nums_575 = {1, 2, 2, 4};
	// int ret_575 = lee->topic_575(nums_575);
	// printf("ret_575:%d\n", ret_575);

	// std::vector<std::string> ret_0807 = lee->topic_0807("DiLN");
	// printf("LeedCode 0807: ");
	// for(int i = 0; i < ret_0807.size(); i++)
	// {
	// 	printf("%s ", ret_0807[i].c_str());
	// }
	// printf("\n");

	// std::vector<int> ret_1103 = lee->topic_1103(90, 4);
	// printf("LeedCode 1103: ");
	// for(int i = 0; i < ret_1103.size(); i++)
	// {
	// 	printf("%d ", ret_1103[i]);
	// }
	// printf("\n");

	// std::vector<int> temp1{0, 1, 2};
	// std::vector<int> temp2{0, 4, 8};
	// std::vector<int> temp3{1, 2, 3};
	// std::vector<int> temp4{1, 4, 2};
	// std::vector<int> temp5{2, 3, 1};
	// std::vector<int> temp6{3, 4, 1};
	// std::vector<std::vector<int>> temp_vec;
	// temp_vec.push_back(temp1);
	// temp_vec.push_back(temp2);
	// temp_vec.push_back(temp3);
	// temp_vec.push_back(temp4);
	// temp_vec.push_back(temp5);
	// temp_vec.push_back(temp6);

	// std::vector<int> temp1{0, 3, 7};
	// std::vector<int> temp2{2, 4, 1};
	// std::vector<int> temp3{0, 1, 5};
	// std::vector<int> temp4{2, 3, 10};
	// std::vector<int> temp5{1, 3, 6};
	// std::vector<int> temp6{1, 2, 1};
	// std::vector<std::vector<int>> temp_vec;
	// temp_vec.push_back(temp1);
	// temp_vec.push_back(temp2);
	// temp_vec.push_back(temp3);
	// temp_vec.push_back(temp4);
	// temp_vec.push_back(temp5);
	// temp_vec.push_back(temp6);

	// std::vector<int> temp1{0, 3, 5};
	// std::vector<int> temp2{2, 3, 7};
	// std::vector<int> temp3{0, 5, 2};
	// std::vector<int> temp4{0, 2, 5};
	// std::vector<int> temp5{1, 2, 6};
	// std::vector<int> temp6{1, 4, 7};
	// std::vector<int> temp7{3, 4, 4};
	// std::vector<int> temp8{2, 5, 5};
	// std::vector<int> temp9{1, 5, 8};
	// std::vector<std::vector<int>> temp_vec;
	// temp_vec.push_back(temp1);
	// temp_vec.push_back(temp2);
	// temp_vec.push_back(temp3);
	// temp_vec.push_back(temp4);
	// temp_vec.push_back(temp5);
	// temp_vec.push_back(temp6);
	// temp_vec.push_back(temp7);
	// temp_vec.push_back(temp8);
	// temp_vec.push_back(temp9);

	// int ret_1334 = lee->topic_1334(6, temp_vec, 8279);
	// printf("LeedCode 1103:%d\n", ret_1334);

	// bool ret_292 = lee->topic_292(8);
	// printf("LeedCode 292:%d\n", ret_292);

	std::vector<std::vector<char>> grid = {{'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}};
	bool ret_3127 = lee->topic_3127(grid);
	printf("LeedCode 3127:%d\n", ret_3127);
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

typedef struct Node
{
	int data;
	Node *next;
};

void Node_Create_Head(Node *list, int n)
{
	Node *p;
	int j = 0;
	// list = (Node *)malloc(sizeof(Node));
	list->next = NULL;

	int num = 0;
	while (j++ < n)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = num++;
		p->next = list->next;
		list->next = p;
		// printf("Node_Create\n");
	}
	printf("Node_Create_Head OK!\n");
}

// Node *Node_Creat(Node *list)
// {
// 	Node *p;
// 	p = (Node *)malloc(sizeof(Node));
// 	list->next = p;
// 	p->data = list->data+1;
// 	return p;
// }

// void Node_Create_Head(Node *list, int n)
// {
// 	Node *p = list;
// 	int j = 0;
// 	while(j++ < n)
// 	{
// 		p = Node_Creat(p);
// 	}
// 	printf("Node_Create_Head OK!\n");
// }

void Node_Create_End(Node *list, int n)
{
	Node *p;
	list->next = NULL;

	int num = 0;
	int j = 0;
	while (j++ < n)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = num++;
		p->next = list->next;
		list->next = p;
		list = p;
	}
	list->next = NULL;
}

int Node_Insert_Head(Node *list, int n, int data)
{
	Node *p;

	int j = 1;
	while (list->next != NULL && j < n)
	{
		list = list->next;
		j++;
	}

	if (list->next == NULL || j > n)
		return 0;

	p = (Node *)malloc(sizeof(Node));
	p->data = data;
	p->next = list->next;
	list->next = p;

	return 1;
}

int Node_Insert_End(Node *list, int n, int data)
{
	Node *p;

	int j = 0;
	while (list->next != NULL && j < n)
	{
		list = list->next;
		j++;
	}

	if (list == NULL || j > n)
		return 0;

	p = (Node *)malloc(sizeof(Node));
	p->data = data;
	p->next = list->next;
	list->next = p;

	return 1;
}

int Node_Delete(Node *list, int n)
{
	Node *p;

	int j = 1;
	while (list->next != NULL && j < n)
	{
		list = list->next;
		j++;
	}

	if (list->next == NULL || j > n)
		return 0;

	p = list->next;
	list->next = p->next;
	free(p);
	return 1;
}

int Node_Clear(Node *list)
{
	Node *p;
	p = list->next;

	while (p)
	{
		list->next = p->next;
		free(p);
		p = list->next;
	}
	// list->next = NULL;

	return 1;
}

void Node_Printf(Node *list)
{
	Node *p = list->next;
	// printf("Node_Printf:%d\n", p->data);
	printf("Node_Printf:\n");
	if (p == NULL)
	{
		printf("Empty List!!\n");
		return;
	}
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//** 静态链表 **//
#define MAX_SIZE 100
typedef struct
{
	int data;
	int index;
} Const_List[MAX_SIZE];

// 创建链表
int Create_Const_List(Const_List L)
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		L[i].index = i + 1;
	}

	L[MAX_SIZE - 1].index = 0;
	return 1;
}

int Length_Const_List(Const_List L)
{
	int k, j = 0;
	k = L[MAX_SIZE - 1].index;

	while (k)
	{
		k = L[k].index;
		j++;
	}

	return j;
}

// 找到空闲位置
int Malloc_Const_List(Const_List L)
{
	int i = L[0].index;

	if (L[0].index)
		L[0].index = L[i].index;

	return i;
}

// 收回空闲位置
void Free_Const_List(Const_List L, int k)
{
	L[k].index = L[0].index;
	L[0].index = k;
}

int Insert_Const_List(Const_List L, int n, int data)
{
	int j, k, l;
	k = MAX_SIZE - 1; // k是最后一个元素的下标

	if (n < 1 && n > Length_Const_List(L) + 1)
		return 0;

	j = Malloc_Const_List(L); // 找到空闲index

	if (j)
	{
		L[j].data = data;
		for (l = 1; l <= n - 1; l++)
			k = L[k].index;
		L[j].index = L[k].index;
		L[k].index = j;
		return 1;
	}
	return 0;
}

int Delete_Const_List(Const_List L, int i)
{
	int j, k;

	if (1 < i && i > Length_Const_List(L) + 1)
		return 0;

	k = MAX_SIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].index;
	j = L[k].index;
	L[k].index = L[j].index;
	Free_Const_List(L, j);
	return 1;
}

void Print_Const_List(Const_List L)
{
	int k;
	k = L[MAX_SIZE - 1].index;
	printf("const list value:\n");

	if (!k)
	{
		printf("Empty Const List!!\n");
		return;
	}

	while (k)
	{
		// printf("i:%d d:%d| ", L[k].index, L[k].data);
		printf("%d ", L[k].data);
		k = L[k].index;
	}
	printf("\n");
}

#define MAX_STR_SIZE 128
#define LEFT_BRACKET "("
#define RIGHT_BRACKET ")"
#define ADD "+"
#define SUB "-"
#define MUL "*"
#define DIV "/"

typedef struct LinkData
{
	char data[10];
	LinkData *next;
} LinkData;

typedef struct
{
	LinkData *top;
	int count;
} LinkOperatorData;

int LinkDataPush()
{
}

int LinkDataPop()
{
}

int transmitStr(char *inputStr /*, LinkOperatorData *data*/)
{
	int strLength = 1;

	char splitStr[100][10];
	memset(splitStr, 0, 100 * 10);

	char strIndex[2];
	memset(strIndex, 0, 2);

	char NUMBER[] = "0123456789";

	while (strcmp(strncpy(strIndex, inputStr++, 1), "\0") != 0)
	{
		if (strstr(NUMBER, strIndex) != NULL)
		{
			if (strstr(NUMBER, splitStr[strLength - 1]) == NULL)
				strcpy(splitStr[++strLength - 1], strIndex);
			else
				strcat(splitStr[strLength - 1], strIndex);
		}
		else
		{
			strcpy(splitStr[++strLength - 1], strIndex);
		}
		// printf("splitStr:%s size:%d\n", splitStr[strLength-1], strLength);
	}

	printf("str:%d\n", strLength);
	for (int i = 0; i < strLength; i++)
	{
		printf("|%s| ", splitStr[i]);
	}
	printf("\n");

	return 0;
}

int calcFourOperations(char *inputStr)
{
	LinkOperatorData *linkOperatorData;
	linkOperatorData->top = NULL;
	linkOperatorData->count = 0;
}

void InsertSort(std::vector<int> &nums, int n)
{
	if(n <= 1) return;
	for(int i = 0; i < n; ++i)
	{
		printf("i:%d->", i);
		for(int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
		{
			printf("%d %d__", nums[j], nums[j-1]);
			std::swap(nums[j], nums[j - 1]);
			printf("%d %d\n", nums[j], nums[j-1]);
		}
		for(int testi = 0; testi < nums.size(); ++testi)
			printf("%d ", nums[testi]);
		printf("\n");
		printf("\n");
	}
}

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
	DesignPatternsStudy();

	/******************C++ Primer 第五版************************/
	// CPlusPlusPrimerStudy();

	/******************LeedCode************************/
	leetcodeStudy();

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

	ShareMemery *shareMer = new ShareMemery();
	// shareMer->sendShmData();
	// shareMer->recvShmData();

	CallBackFuntion callback;
	// callback.display();

	// PBook mPBook("Primer c++", 59.5);
	// mPBook.display();

	pair<int, string> person = {18, "李四"};
	auto [age, name] = person;
	cout << "age:" << age << " (" << typeid(age).name() << ")";
	cout << " name:" << name << " (" << typeid(name).name() << ")";
	cout << endl;

	printf("\n********单链表测试********\n");
	Node *list1;
	list1 = (Node *)malloc(sizeof(Node));
	list1->data = 10;
	Node_Printf(list1);
	Node_Create_Head(list1, 10);
	printf("list1 size:%d\n", sizeof(list1));
	Node_Printf(list1);
	Node_Insert_Head(list1, 10, 55);
	Node_Printf(list1);

	Node *list2;
	list2 = (Node *)malloc(sizeof(Node));
	Node_Create_End(list2, 10);
	printf("list2 size:%d\n", sizeof(list2));
	Node_Printf(list2);
	Node_Insert_End(list2, 10, 55);
	Node_Printf(list2);

	Node_Delete(list2, 5);
	Node_Printf(list2);
	Node_Clear(list2);
	Node_Printf(list2);

	printf("\n********静态链表测试********\n");
	Const_List constList;
	Create_Const_List(constList);

	Print_Const_List(constList);

	Insert_Const_List(constList, 1, 1);
	Insert_Const_List(constList, 1, 2);
	Insert_Const_List(constList, 1, 3);
	Insert_Const_List(constList, 1, 4);
	Insert_Const_List(constList, 1, 5);
	Insert_Const_List(constList, 1, 6);
	Insert_Const_List(constList, 1, 7);
	Print_Const_List(constList);

	printf("const list length:%d\n", Length_Const_List(constList));

	Insert_Const_List(constList, 5, 55);
	Print_Const_List(constList);

	Delete_Const_List(constList, 5);
	Print_Const_List(constList);

	printf("\n********栈实现四则运算********\n");
	char testData[128];
	memset(testData, 0, 128);
	strcpy(testData, "9+(3-1)*3+10/2");
	transmitStr(testData);

	char testdata111[10];

	char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char *serial = "HANT0424040III";

	string number_str = "0123456789";
	string serial_str = "HANT0424040III";

	int first = serial_str.find_first_of(number_str);
	int last = serial_str.find_last_of(number_str);
	printf("find first number:%d last:%d\n", first, last);

	serial_str = serial_str.substr(first, last - first + 1);
	printf("serial_str:%s\n", serial_str.c_str());


	char c_serial[20];
	// memset(c_serial, 255, 20);
	// strcpy(c_serial, "HANT0424040III");
	
	int ret_num = strcmp(c_serial, "");
	printf("ret_num:%d\n", ret_num);


	// strcat(testdata111, "1");
	// strcat(testdata111, "2");
	// strcat(testdata111, "3");
	// strcat(testdata111, "4");
	// printf("test:%s\n", testdata111);

	std::vector<int> sortNums{4, 6, 5, 2, 3, 1};
	printf("origin nums:");
	for(int testi = 0; testi < sortNums.size(); ++testi)
		printf("%d ", sortNums[testi]);
	printf("\n");
	InsertSort(sortNums, sizeof(sortNums) / sizeof(int));
	printf("sort nums:");
	for(int testi = 0; testi < sortNums.size(); ++testi)
		printf("%d ", sortNums[testi]);
	printf("\n");

	Test_Viewer *v = new Test_Viewer();
	Test_Observer *nba_o = new Test_NBA_Observer("nba摸鱼者", v);
	Test_Observer *stock_o = new Test_Stock_Observer("股票摸鱼者", v);

	v->addObserver(nba_o);
	v->addObserver(stock_o);

	v->text = "吃饭去了!";
	v->notify();

	v->text = "老板来了!";
	v->notify();

	return 0;
}
