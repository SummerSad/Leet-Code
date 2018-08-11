// 104. Maximum Depth of Binary Tree
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    // leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left == NULL)
        return 1 + maxDepth(root->right);
    if (root->right == NULL)
        return 1 + maxDepth(root->left);
    int left_dep = maxDepth(root->left);
    int right_dep = maxDepth(root->right);
    return 1 + (left_dep > right_dep ? left_dep : right_dep);
}

int main()
{
    return 0;
}
