#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;
struct Translation
{
    string english;
    string spanish;
    string french;
    string german;
    string italian;
};

struct TreeNode
{
    Translation data;
    TreeNode *left;
    TreeNode *right;
};
//bst class
class BinarySearchTree
{
private:
//dynamic memory
    TreeNode *root;
    //private function
    bool Insert(TreeNode *&node, Translation data);
    bool Search(TreeNode *node, string english, Translation &result);
    void Destroy(TreeNode *node);

public:
//public
    BinarySearchTree();
    ~BinarySearchTree();
    //insert and search
    bool Insert(string english, string spanish, string french, string german, string italian);
    bool Search(string english, Translation &result);
};

#endif