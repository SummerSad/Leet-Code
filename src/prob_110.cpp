// 110. Balanced Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depTree(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    // leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left == NULL)
        return 1 + depTree(root->right);
    if (root->right == NULL)
        return 1 + depTree(root->left);
    int left_dep = depTree(root->left);
    int right_dep = depTree(root->right);
    return 1 + (left_dep > right_dep ? left_dep : right_dep);
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
        return true;
    int left_dep = depTree(root->left);
    int right_dep = depTree(root->right);
    if (left_dep - right_dep > 1 || left_dep - right_dep < -1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

struct TreeNode *newTreeNode(int val)
{
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main()
{
    struct TreeNode *root = newTreeNode(1);
    struct TreeNode *p = newTreeNode(2);
    struct TreeNode *q = newTreeNode(3);
    root->left = NULL;
    root->right = p;
    p->left = NULL;
    p->right = q;
    printf("%d\n", isBalanced(root));
    free(root);
    free(p);
    free(q);
    return 0;
}
