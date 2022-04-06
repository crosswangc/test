// 700. 二叉搜索树中的搜索
#include "../../datastructure/tree.h"

using namespace std;

// 递归，空间复杂度 O(n)
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;

    if (root->val == val)
    {
        return root;
    }
    return searchBST(root->val < val ? root->right : root->left, val);
}

// 迭代，空间复杂度 O(1)
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root) {
        if (root->val == val) {
            return root;
        }
        root = root->val > val ? root->left : root->right;
    }
    return nullptr;
}