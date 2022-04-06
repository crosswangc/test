#ifndef TREE_H
#define TREE_H

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        root = new TreeNode(x);
        return root;
    }
    if (x < root->val)
    {
        root->left = buildTree(root->left, x);
    }
    else if (x > root->val)
    {
        root->right = buildTree(root->right, x);
    }
    return root;
}

#endif
