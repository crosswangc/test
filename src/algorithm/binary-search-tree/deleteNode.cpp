// 450. 删除二叉搜索树中的节点

#include <vector>
#include "../../datastructure/tree.h"

using namespace std;

int leftMax(TreeNode *root)
{
    root = root->left;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->val;
}

int rightMin(TreeNode *root)
{
    root = root->right;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->val;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            root = nullptr;
        }
        else if (root->left != nullptr) {
            root->val = leftMax(root);
            root->left = deleteNode(root->left, root->val);
        }
        else if (root->right != nullptr) {
            root->val = rightMin(root);
            root->right = deleteNode(root->right, root->val);
        }
    }

    return root;
}