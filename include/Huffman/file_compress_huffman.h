//file_compress_huffman.h头文件
//当前的头文件用来放置huffman文件编码类的头文件，具体的实现我们放在类外实现
#include<string>
#include<vector>
#include"command.h"
using namespace std;
//用一个结构体来保存每个字符的信息：
struct byteinfo
{
	uch _ch;//代表字符
	size_t _appear_count;
	string _ch_code;//当前字符的所用的编码
	byteinfo(size_t appear_count = 0)
		:_appear_count(appear_count)
	{}
	//因为在构造哈夫曼树要建堆那么我们就需要比较，那么就要提供我们自定义结构体的比较符号重载：
	bool operator>(const byteinfo& b)const
	{
		return _appear_count > b._appear_count;
	}
	bool operator<(const byteinfo& b)const
	{
		return _appear_count < b._appear_count;
	}
	bool operator==(const byteinfo& b)const
	{
		return _appear_count == b._appear_count;
	}
	bool operator!=(const byteinfo& b)const
	{
		return _appear_count != b._appear_count;
	}
	//在构造huffman树时候中途要构造新树那么新树的根节点的权值是两个子树根节点的权值的和，那么就要将两个
	//节点相加那么就要重载+号：
	byteinfo operator+(const byteinfo& b)
	{
		//这里我们重载+只需要关注它的出现次数即可不需要关心其他因为我们构造huffman树的时候是用频次来构造
		//而且最终我们用的只是叶子节点。所以我们这里只需要返回相加之后正确的出现频次即可
		return byteinfo(_appear_count + b._appear_count);
	}
};
 
class file_compress_huffman
{
public:
	file_compress_huffman();
	void compress_file(const string& file_name);//压缩
	void un_compress_file(const string& file_name);//解压缩
private:
	void get_line(string& buf, FILE* fpread);
	string get_file_name(const string& file_name);//获取文件名
	string get_postfix(const string& file_name);//获取文件后缀
	void write_head_info(const string& file_path, FILE* fout);	//用来向压缩文件中写入头部信息：
	vector<byteinfo> _fileinfo;//用来存放文件中的每个字符的信息
 
};