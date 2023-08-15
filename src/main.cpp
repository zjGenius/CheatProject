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
// #include "l_opencv.h"
#include "IQTransmitCenter.h"
#include "IQRecvData.h"
// #include "context.h"
// #include "device.h"

#include "DesignPatterns.h"
#include "CPlusPlusPrimer.h"

#include "leetcode.h"
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

	/******************udp传输文件*************************/

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

	/******************C++ Primer 第五版************************/
	// CPlusPlusPrimer *cplusplus = new CPlusPlusPrimer();
	// cplusplus->chapter1_display();

	/******************LeedCode************************/
	LeedCode *lee = new LeedCode();
	std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	// std::vector<int> nums = {3, 2, 2, 3};

	// lee->topic_1(nums, 9);
	// printf("20 bool:%d\n", lee->topic_20("{)}"));
	printf("27 vector size:%d\n", lee->topic_27(nums, 2));

	return 0;
}

/* 库构思
#IIO

class
{
	##初始化:
	initIIO(string ip); // ip:设备ip; type: 0,初始化iio 1,初始化按键  2,0和1同时用
	initKeys(void*(int key,int type));	//回调函数

	##蜂鸣器:
	setBuzzerAlarm(bool _switch, int seconds, int mode) // _switch true开 false关;  seconds 时长(秒);  mode 模式

	##马达:
	setMotorAlarm(bool _switch, int seconds, int mode) // _switch true开 false关;  seconds 时长(秒);  mode 模式

	##LED:
	setLedAlarm(bool _switch, int seconds, int mode) // _switch true开 false关;  seconds 时长(秒);  mode 模式

	// 上面三个可提供一个接口?

	##屏幕:
	setScreen(bool _switch, int light) // _switch true开 false关;  light 亮度

	##开关板:
	setSignalSwitch(int mode) // mode 通道切换

	##设置值
	set_control_IIO(int mode, bool _switch)	// mode 控制哪个引脚 _switch 置0还是置1

	##获取值
	int get_control_IIO(int mode)			// 获取需要寄存器位值
}
*/
