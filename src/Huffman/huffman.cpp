#include "huffman.h"

// 定义哈夫曼树节点
struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// 定义比较函数，用于构建哈夫曼树
struct Compare
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->freq > b->freq;
    }
};

// 递归构建哈夫曼树
HuffmanNode *buildHuffmanTree(unordered_map<char, int> &freqTable)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> pq;
    for (auto &p : freqTable)
    {
        pq.push(new HuffmanNode(p.first, p.second));
    }
    while (pq.size() > 1)
    {
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();
        auto parent = new HuffmanNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

// 递归生成编码表
void generateCodeTable(HuffmanNode *root, string code, unordered_map<char, string> &codeTable)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        codeTable[root->data] = code;
    }
    generateCodeTable(root->left, code + "0", codeTable);
    generateCodeTable(root->right, code + "1", codeTable);
}

// 压缩文件
void compressFile(const string &inputFile, const string &outputFile)
{
    // 统计每个字符出现的频率
    unordered_map<char, int> freqTable;
    ifstream fin(inputFile, ios::binary);
    char c;
    while (fin.get(c))
    {
        freqTable[c]++;
    }
    fin.close();

    // 构建哈夫曼树
    auto root = buildHuffmanTree(freqTable);

    // 生成编码表
    unordered_map<char, string> codeTable;
    generateCodeTable(root, "", codeTable);

    // 写入压缩文件头部信息
    ofstream fout(outputFile, ios::binary);
    fout.write("HUFF", 4);
    string table_size = to_string(freqTable.size());
    fout.write((char *)table_size.c_str(), sizeof(int));
    for (auto &p : freqTable)
    {
        fout.write(&p.first, sizeof(char));
        fout.write((char *)&p.second, sizeof(int));
    }

    // 压缩数据并写入压缩文件
    fin.open(inputFile, ios::binary);
    string code;
    char buffer = 0;
    int offset = 0;
    while (fin.get(c))
    {
        code += codeTable[c];
        for (char bit : code)
        {
            if (bit == '1')
                buffer |= 1 << (7 - offset);
            offset++;
            if (offset == 8)
            {
                fout.put(buffer);
                buffer = 0;
                offset = 0;
            }
        }
        code.clear();
    }
    if (offset > 0)
        fout.put(buffer);
    fin.close();
    fout.close();
}

// 解压缩文件
void decompressFile(const string &inputFile, const string &outputFile)
{
    // 读取压缩文件头部信息
    ifstream fin(inputFile, ios::binary);
    char magic[4];
    fin.read(magic, 4);
    if (strncmp(magic, "HUFF", 4) != 0)
    {
        cerr << "Invalid file format" << endl;
        return;
    }
    int size;
    fin.read((char *)&size, sizeof(int));
    unordered_map<char, int> freqTable;
    for (int i = 0; i < size; i++)
    {
        char c;
        int freq;
        fin.read(&c, sizeof(char));
        fin.read((char *)&freq, sizeof(int));
        freqTable[c] = freq;
    }

    // 构建哈夫曼树
    auto root = buildHuffmanTree(freqTable);

    // 解压缩数据并写入解压缩文件
    ofstream fout(outputFile, ios::binary);
    HuffmanNode *node = root;
    char buffer;
    while (fin.get(buffer))
    {
        for (int i = 7; i >= 0; i--)
        {
            if ((buffer >> i) & 1)
                node = node->right;
            else
                node = node->left;
            if (!node->left && !node->right)
            {
                fout.put(node->data);
                node = root;
            }
        }
    }
    fin.close();
    fout.close();
}
