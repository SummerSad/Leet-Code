/*
 * 111. Minimum Depth of Binary Tree
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 */

#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	// leaf node
	if (root->left == NULL && root->right == NULL)
		return 1;
	if (root->left == NULL)
		return 1 + minDepth(root->right);
	if (root->right == NULL)
		return 1 + minDepth(root->left);
	int left_min = minDepth(root->left);
	int right_min = minDepth(root->right);
	return 1 + (left_min < right_min ? left_min : right_min);
}

int main()
{
	return 0;
}
