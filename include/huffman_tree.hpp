 
#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<initializer_list>
using namespace std;
//实现哈夫曼树：
//1.首先用优先级队列来存储只有根节点的二叉树森林每颗二叉树只有一个带权的根节点左右孩子都为空。
//2.在优先级队列队列中把根节点权值最小的两颗二叉树作为左右子树来构造一颗新的二叉树，新的二叉树根节点的
//权值为两棵树根节点权值之和。然后将新的二叉树的根节点再放回到优先级队列中。
//3.重复上面的步骤就可以得到哈夫曼树了。
template<class T>
struct huffman_tree_node
{
	huffman_tree_node(T weight)
	:_right(nullptr)
	, _left(nullptr)
	, _weight(weight)
	{}
	huffman_tree_node(huffman_tree_node<T>* left = nullptr, huffman_tree_node<T>* right = nullptr,  T weight = T())
		:_left(left)
		, _right(right)
		, _weight(weight)
	{}
	huffman_tree_node<T>* _left;
	huffman_tree_node<T>* _right;
	T _weight;
};
 
template<class T>
class huffman_tree
{
public:
 
	typedef huffman_tree_node<T> node;
	class compare
	{//创建小堆要提供大于的比较方式：
	public:
		bool operator()(const node* a, const node* b)
		{
			return a->_weight > b->_weight;
		}
	};
 
 
public:
	//用invalid来代表无效元素，在我们的文件压缩中就代表没有出现的元素那么也就是_appear_count=0的
	//元素不需要在huffman树中存在因为他们在文件中没有出现，我们不需要他们的编码。
	huffman_tree(const vector<T>& ln,const T invalid=T())
	{
		priority_queue<node*,vector<node*>,compare> q;
		for (auto e : ln)
		{
			if(e!=invalid)
			q.push(new node(e));
		}
		while (q.size() > 1)
		{//这里我们将较大的元素放到新构造的树的右边，小的放到左边
			node* temp1 = q.top();//最小的元素
			q.pop();
			node* temp2 = q.top();
			q.pop();
			node* temp_root= new node(temp1, temp2, (temp1->_weight + temp2->_weight));
 
			q.push(temp_root);
		}
		if (!q.empty())
		{
			_root = q.top();
		}
	}
	//列表构造huffman树
	huffman_tree(const initializer_list<T> ln)
	{
		priority_queue<node*, vector<node*>, compare> q;
		for (auto e : ln)
		{
			q.push(new node(e));
		}
		while (q.size() > 1)
		{//这里我们将较大的元素放到新构造的树的右边，小的放到左边
			node* temp1 = q.top();//最小的元素
			q.pop();
			node* temp2 = q.top();
			q.pop();
			node* temp_root = new node(temp1, temp2,(temp1->_weight + temp2->_weight));
			q.push(temp_root);
		}
		_root = q.top();
	}
	~huffman_tree()
	{
		destroy(_root);
	}
	//哈夫曼编码：获取每个叶子节点的编码
	void huffman_code(vector<T>& fileinfo)
	{
		string path;
		front(path, _root, fileinfo);
	}
	node* get_root()
	{
		return _root;
	}
 
private:
	void front(string& path, node* root,vector<T>& fileinfo)
	{
		if (root == nullptr)
		{
			return;
		}
		if (root->_left == nullptr&&root->_right == nullptr)
		{
			fileinfo[root->_weight._ch]._ch_code = path;
			return;
		}
		path.push_back('0');
		front(path, root->_left, fileinfo);
		path.pop_back();
		path.push_back('1');
		front(path, root->_right, fileinfo);
		path.pop_back();
	}
	void destroy(node* root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			delete root;
			root = nullptr;
		}
	}
	node* _root;
};