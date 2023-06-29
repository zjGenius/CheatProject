/**
 * @file file_compress_huffman.cpp
 * @author zhangjun (1905212905@qq.com)
 * @brief Huffman文件压缩的具体实现
 * @version 0.1
 * @date 2023-06-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#define _CRT_SECURE_NO_WARNINGS
#include "file_compress_huffman.h"
#include "huffman_tree.hpp"
#include "command.h"
//在构造函数中要初始化类中的字符信息数组表：
file_compress_huffman::file_compress_huffman()
{
	_fileinfo.resize(256);
	//因为byteinfo中的ch表示字符，而ch是char类型的，那么就有256种状态，我们初始化存放
	//哈夫曼压缩中的数组那么我们就可以得到文件中所有出现的字符的状态,用字符的ASII码来
	//定位字符在数组中的位置
	for (int i = 0; i < 256; i++)
	{
		_fileinfo[i]._ch = i;
	}
}
//获取文件后缀名
string file_compress_huffman::get_postfix(const string& file_name)
{
	return file_name.substr(file_name.find_first_of('.')+1);
}
//获取文件名
string file_compress_huffman::get_file_name(const string& file_name)
{
	return file_name.substr(0, file_name.find_first_of('.'));
}
 
//写入解压缩要用的头部信息：
void file_compress_huffman::write_head_info(const string& file_name, FILE* fpout)
{
	//首先写入文件后缀名，因为要在解压缩的时候还原文件名所以要保存信息
	string file_postfix = get_postfix(file_name);
	file_postfix += "\n";
	//然后写入在文件中出现字符种类的个数,以及每个字符出现的次数字符和出现次数之间用：隔开
	string numappear_count;
	size_t type_count = 0;
	for (auto e:_fileinfo)
	{
		if (e._appear_count == 0)
		{
			continue;
		}
		numappear_count += e._ch;
		numappear_count += ':';
		numappear_count += to_string(e._appear_count);
		numappear_count += '\n';
		type_count++;
	}
	file_postfix += to_string(type_count);
	file_postfix += "\n";
	fwrite(file_postfix.c_str(), 1, file_postfix.size(), fpout);//先写入文件后缀和字符出现种类个数
	fwrite(numappear_count.c_str(), 1, numappear_count.size(), fpout);
}
 
//压缩函数：
void file_compress_huffman::compress_file(const string& file_name)
{
	//1.首先要统计源文件中字符的出现次数：
	//(1).首先要打开文件：
	FILE* fpin = fopen(file_name.c_str(), "rb");
	if (fpin == nullptr)
	{
		cout << "文件打开失败" << endl;
		return ;
	}
	//(2).读取文件到内存中
	uch buf[1024] = {0};
	while (true)
	{
		size_t read_size = fread(buf, 1, 1024, fpin);
		if (read_size == 0)
		{
			//if (feof(fpin))
			//{
			//	break;
			//}
			//else
			//{
			//	buf[0] = (uch)0xFF;
			//	fseek(fpin, 1, SEEK_CUR);
			//	read_size = 1;
			//}
			break;
		}
		//统计文件中的出现的字符的次数
		for (size_t i = 0; i < read_size; i++)
		{
			_fileinfo[buf[i]]._appear_count++;
		}
	}
 
	//2.用字节频次来创建huffman树：
	//(1).先构造一个huffman树对象
	huffman_tree<byteinfo> tree(_fileinfo,byteinfo());
 
	//3.获取每个huffman编码：
	tree.huffman_code(_fileinfo);
	//tree.getree(_fileinfo);
 
	//要打开的压缩文件名
	string compressed_filename = get_file_name(file_name);
	compressed_filename += ".hz.bin";//这里压缩后的后缀应该要修改一下，但是我不知修改为什么
	FILE* fpout = fopen(compressed_filename.c_str(), "wb");
 
	//4.向压缩文件中写入头部信息：
	write_head_info(file_name, fpout);
 
	//5.用获取的到的编码对源文件进行改写,然后写入到文件当中：
	//(1).先将文件指针指到文件头部
	fseek(fpin, 0, SEEK_SET);
	uch bit = 0;//对文件中编码临时要用的bit位
	int bitcount = 0;//计算上面bit用了多少位
	//string text;
	while (true)
	{
		size_t read_size = fread(buf, 1, 1024, fpin);
		if (read_size == 0)
		{
			break;
		}
		//将文件中的每个字符读到内存中，然后将每一位替换为相应的编码然后写到压缩文件中
		for (size_t i = 0; i < read_size; i++)
		{
			string& temp_code = _fileinfo[buf[i]]._ch_code;
			for (size_t j = 0; j < temp_code.size(); j++)
			{
				bit <<=  1;
				if (temp_code[j] == '1')
				{
					bit |= 1;
				}
				bitcount++;
				if (bitcount == 8)
				{
					//text.push_back(uch(bit));
					fputc(bit, fpout);
					//if (text.size() > 0x40000000)
					//{//这里如果每次凑够一个bit位就向文件中写入太浪费时间所以这里我们先将bit位存储起来然后一次性写入到文件中
					// 但是如果一次存储过多那么可能会导致写入失败，我在网上看32位linux系统下一次性最多写2G的数据那么我们这里保险起见
					// 达到1G的数据就进行写入
					//	fwrite(text.c_str(), 1, text.size(), fpout);
					//	text.clear();
					//}
					bit = 0;
					bitcount = 0;
				}
			}
		}
		//fwrite(text.c_str(), 1, text.size(), fpout);
		//防止最后一位bit位没有写入
		/*if (bitcount > 0 && bitcount < 8)
		{
			bit <<= (8 - bitcount);
			fputc(bit, fpout);
		}*/
	}
	if (bitcount > 0 && bitcount < 8)
	{
		bit <<= (8 - bitcount);
		fputc(bit, fpout);
	}
	fclose(fpin);
	fclose(fpout);
}
//解压缩
void file_compress_huffman::un_compress_file(const string& file_name)
{
	//打开压缩文件：
	//(1)这里可以判断一下文件的后缀名是否是我们我们的设置的后缀，因为我们当前的函数的功能只能解压huffman编码的压缩文件：
	//但是由于我测试没有打开二进制文件的软件所以我就将压缩文件的后缀名也写为了txt方便测试所以这里就不判断了
	//(2)打开文件：
	FILE* fpread = fopen(file_name.c_str(), "rb");
	if (fpread == nullptr)
	{
		cout << "要解压缩打开文件不存在" << endl;
	}
	//1.首先要读取文件后缀信息,还原后的文件我们要以压缩文件中保存的后缀信息作为文件的类型
	string file_post_fix;
	get_line(file_post_fix, fpread);
	//2.读取总行数
	string fileinfo;
	get_line(fileinfo, fpread);
	int count = atoi(fileinfo.c_str());//读取的频次信息总行数
	//3.读取频次信息
	while (count--)
	{
		fileinfo = "";//重复利用fileinfo字符串
		get_line(fileinfo, fpread);
		if (fileinfo == "")
		{
			fileinfo = "\n";
			get_line(fileinfo, fpread);
		}
		uch ch = fileinfo[0];
		//用读到的字符来构造_fileinfo数组因为要用_fileinfo来还原huffman树从而来解压文件
		_fileinfo[ch]._ch = ch;//这一步可有可无因为我们在构造对象的时候就已经初始化过_fileinfo了
		_fileinfo[ch]._appear_count = atoi(fileinfo.c_str() + 2);
	}
	//4.还原Huffman树
	huffman_tree<byteinfo> tree(_fileinfo);
	//5.解压缩
	//从huffman树的根开始按照文件中的存放的bit位来还原huffman树
	//(1)打开要保存解压缩之后的还原文件
	string refilename = get_file_name(file_name);
	refilename += "un";
	refilename += ".";
	refilename += file_post_fix;
	//FILE* fpwrite = fopen("121up.txt", "wb");
	FILE* fpwrite = fopen(refilename.c_str(), "wb");
	uch buf[1024];
	string text;
	uch bit = 0;
	count = 0;//解压缩字符个数
	huffman_tree_node<byteinfo>* cur = tree.get_root();
	while (true)
	{
		size_t read_size=fread(buf, 1, 1024, fpread);
		if (read_size == 0)
		{
			break;
		}
		for (size_t i = 0; i < read_size; i++)
		{
			bit = buf[i];
			for (size_t j = 0; j < 8;j++)
			{
				if (bit & 0x80)
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
				bit <<= 1;
				if (cur&&cur->_left == nullptr&&cur->_right == nullptr)
				{
					uch ch = cur->_weight._ch;
					fputc(ch, fpwrite);
					//text.push_back(cur->_weight._ch);
					cur = tree.get_root();
					count++;
					//if (text.size() > 0x40000000)
					//{
					//	fwrite(text.c_str(), 1, text.size(), fpwrite);
					//	text.clear();
					//}
					if (count == cur->_weight._appear_count)
					{
						break;
					}
				}
			}
		}
	}
	//fwrite(text.c_str(), 1, text.size(), fpwrite);
	fclose(fpwrite);
	fclose(fpread);
}
//读取文件中一行的字符：
void file_compress_huffman::get_line(string& buf, FILE* fpread)
{
	if (fpread == nullptr)
	{
		return;
	}
	while (!feof(fpread))//这里的feof当文件结束的时候会返回一个非0的值
	{
		uch ch = fgetc(fpread);
		if (ch == '\n')
		{
			return;
		}
		buf+=ch;
	}
}