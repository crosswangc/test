// 701. 二叉搜索树中的插入操作
#include "../../datastructure/tree.h"
using namespace std;

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    TreeNode *pos = root;
    while (pos != nullptr) {
        if (pos->val > val) {
            if (pos->left == nullptr) {
                pos->left = new TreeNode(val);
                break;
            }
            else {
                pos = pos->left;
            }
        }
        if (pos->val < val)
        {
            if (pos->right == nullptr) {
                pos->right = new TreeNode(val);
                break;
            }
            else {
                pos = pos->right;
            }
        }
    }
    return root;
}