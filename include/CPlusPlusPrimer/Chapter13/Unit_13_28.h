/**
 * @file Unit_13_28.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief C++ primer 5 第13章练习
 * @version 0.1
 * @date 2024-06-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _UNIT_13_28_H_
#define _UNIT_13_28_H_

#include <iostream>

class Unit_13_TreeNode
{
private:
    std::string value;
    int *count;
    Unit_13_TreeNode *left;
    Unit_13_TreeNode *right;

public:
    Unit_13_TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}                      ///< 构造函数
    Unit_13_TreeNode(Unit_13_TreeNode &treeNode) : value(treeNode.value), left(treeNode.left), right(treeNode.right) {} ///< 拷贝构造函数
    Unit_13_TreeNode &operator=(const Unit_13_TreeNode &treeNode);                                                      ///< 赋值构造函数
    ~Unit_13_TreeNode()                                                                                                 ///< 析构函数
    {
        if (--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
    }
};

class Unit_13_BinStrTree
{
private:
    Unit_13_TreeNode *root;

public:
    Unit_13_BinStrTree() : root(new Unit_13_TreeNode()) {}                        ///< 构造函数
    Unit_13_BinStrTree(Unit_13_BinStrTree &binStrTree) : root(binStrTree.root) {} ///< 拷贝构造函数
    Unit_13_BinStrTree &operator=(const Unit_13_BinStrTree &binStrTree);          ///< 赋值构造函数
    ~Unit_13_BinStrTree()                                                         ///< 析构函数
    {
        delete root;
    }
};

#endif //!_UNIT_13_28_H_