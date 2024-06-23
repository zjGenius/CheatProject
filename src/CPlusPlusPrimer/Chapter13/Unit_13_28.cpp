#include "Unit_13_28.h"

Unit_13_TreeNode &Unit_13_TreeNode::operator=(const Unit_13_TreeNode &treeNode)
{
    ++*treeNode.count;
    if (--*count == 0)
    {
        delete count;
        delete left;
        delete right;
    }
    count = treeNode.count;
    left = treeNode.left;
    right = treeNode.right;
    return *this;
}

Unit_13_BinStrTree &Unit_13_BinStrTree::operator=(const Unit_13_BinStrTree &binStrTree)
{
    Unit_13_TreeNode *new_root = new Unit_13_TreeNode(*binStrTree.root);
    delete root;
    root = new_root;
    return *this;
}
