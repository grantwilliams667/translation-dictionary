#include "bst.h"
//constructor
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}
//destructory
BinarySearchTree::~BinarySearchTree()
{
    Destroy(root);
}
//destroy all nodes in a tree, left to right
void BinarySearchTree::Destroy(TreeNode *node)
{
    if (node != NULL)
    {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
}
//insert function
bool BinarySearchTree::Insert(string english, string spanish, string french, string german, string italian)
{
    Translation data;
    //stores language values
    data.english = english;
    data.spanish = spanish;
    data.french = french;
    data.german = german;
    data.italian = italian;

    return Insert(root, data);
}
//private recursive function
bool BinarySearchTree::Insert(TreeNode *&node, Translation data)
{
    if (node == NULL)
    {
        node = new TreeNode;
        node->data = data;
        //initialize children to null
        node->left = NULL;
        node->right = NULL;
        return true;
    }
    //duplication prevention
    if (data.english == node->data.english)
    {
        return false;
    }
    else if (data.english < node->data.english)
    {
        return Insert(node->left, data);
    }
    else
    {
        return Insert(node->right, data);
    }
}
//public recursive search function
bool BinarySearchTree::Search(string english, Translation &result)
{
    return Search(root, english, result);
}
//privat recursive search function
bool BinarySearchTree::Search(TreeNode *node, string english, Translation &result)
{
    if (node == NULL)
    {
        return false;
    }
//return result if its a match
    if (english == node->data.english)
    {
        result = node->data;
        return true;
    }
    //go left if smaller
    else if (english < node->data.english)
    {
        return Search(node->left, english, result);
    }
    //else go right
    else
    {
        return Search(node->right, english, result);
    }
}