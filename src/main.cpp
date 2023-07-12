#include <stdio.h>
#include <deque>
#include <pthread.h>

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
#include "IQTransmitCenter.h"
#include "IQRecvData.h"
#include "Decorator.h"
#include "myDecorator.h"
#include "Proxy.h"
#include "FactoryMethod.h"
#include "context.h"
#include "device.h"
// #include "huffman1.h"
// #include"HuffmanCompressAndUn.h"

pthread_t signal_IQRecv;

std::string ip = "127.0.0.1";
int port = 1122;
std::string readFile = "sig_pragma.dat";
std::string writeFile = "recv_IQIIO.dat";

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

	/***************容器类学习********************/
	// deque_test();
	// list_test();
	// map_test(0);
	// set_test(2);

	/***************opencv学习********************/
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

	file_compress_huffman file_compress; // 成功案例
	// file_compress.compress_file(inputFile);
	// file_compress.un_compress_file(compressedFile);

	/***************设计模式之工厂模式 实现加减乘除********************/
	// Operation *oper;
	// oper = OperationFactory::createOperate('/');
	// oper->setNumberA(10.2);
	// oper->setNumberB(2.2);
	// double result_num = oper->getResult();

	// printf("result_num:%lf\n", result_num);

	/***************设计模式之策略模式 商场促销案例********************/
	/*
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
*/

	/******************udp传输文件*************************/

	pthread_create(&signal_IQRecv, NULL, *Recv_relay, NULL);

	IQTransmit *transmit = new IQTransmit(ip, port);
	int mode;
	printf("请选择发送模式： \n 0-文件模式 1-iio模式:  ");
	scanf("%d", &mode);
	transmit->sendMode(mode, readFile);

	sleep(2);
	transmit->readIQFile(writeFile);

	/******************设计模式之装饰模式*************************/
	/*
	// 搭配方案1 (面条6.6 + 鸡蛋0.5 = 7.1元)
	printf("搭配方案1:");
	Food *aaa1 = new FoodNoodle();
	Food *bbb1 = new EggDecorator(aaa1);
	bbb1->myInterface();
	printf("=%f\n\n", bbb1->getPrice());

	// 搭配方案2 （米饭2.5 + 鸡蛋0.5 + 牛肉10 + 火腿5 = 18元）
	printf("搭配方案2:");
	Food *aaa2 = new FoodRice();		  // aaa2
	Food *bbb2 = new EggDecorator(aaa2);  // 装饰1（aaa2 + bbb2）
	Food *ccc2 = new BeefDecorator(bbb2); // 装饰2（aaa2 + bbb2 + ccc2）
	Food *ddd2 = new HamDecorator(ccc2);  // 装饰3（aaa2 + bbb2 + ccc2 + ddd2）

	// 此处的ddd2->myInterface()其实是一个链式调用。
	// 链式调用过程：HamDecorator::myInterface() ——> BeefDecorator::myInterface() ——> EggDecorator::myInterface() ——> FoodRice::myInterface()
	// 在每个装饰类的myInterface函数中又加入了具体的装饰操作，所以，装饰顺序与链式调用顺序正好相反。
	ddd2->myInterface();
	printf("=%f\n\n", ddd2->getPrice());

	// 衣服装饰
	Person *per = new Person("xiaoming");

	TShirt *ts = new TShirt();
	Jeans *je = new Jeans();

	ts->Deracte(per);
	je->Deracte(ts);
	je->show();
	*/

	/******************设计模式之代理模式*************************/
	/*
	SchoolGirl *girl = new SchoolGirl("小花");
	Bulb *proxy = new Bulb(girl);
	proxy->sendChocolate();
	proxy->sendFlowers();
	proxy->sendMilk();
	*/

	/******************设计模式之工厂方法模式*************************/
	/*
	LeiFengFactory *factory1 = new StudentFactory();
	L_Student *student = (L_Student *)factory1->createLeiFeng();
	LeiFengFactory *factory2 = new VolunteerFactory();
	L_Volunteer *volunteer = (L_Volunteer *)factory2->createLeiFeng();

	student->buyRice();
	student->sweep();

	volunteer->buyRice();
	volunteer->sweep();
	*/

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

	return 0;
}
