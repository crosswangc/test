// 剑指 Offer 54. 二叉搜索树的第k大节点

#include <vector>
#include "../../datastructure/tree.h"

using namespace std;

int kthLargest(TreeNode *root, int k)
{
    int res;
    dfs(root, k, res);
    return res;
}

void dfs(TreeNode *root, int &k, int &res)
{
    if (root == nullptr || k == 0)
        return;
    dfs(root->right, k, res);
    if (--k == 0)
        res = root->val;
    dfs(root->left, k, res);
}

// 同理，第k小节点
int kthSmallest(TreeNode *root, int k)
{
    int res = 0;
    dfs(root, k, res);
    return res;
}
void dfs(TreeNode *root, int &k, int &res)
{
    if (root == nullptr || k == 0)
        return;
    dfs(root->left, k, res);
    if (--k == 0)
    {
        res = root->val;
    }
    dfs(root->right, k, res);
}
