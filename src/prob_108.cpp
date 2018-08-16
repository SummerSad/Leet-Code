#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *newTreeNode(int val)
{
	struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	p->val = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

// insert only 1 follow BST rule
void insertBST(struct TreeNode *root, int x)
{
	struct TreeNode *parent = NULL;
	struct TreeNode *child = root;
	int flag = -1; // -1 left 1 right
	while (child != NULL) {
		parent = child;
		if (child->val > x) {
			child = child->left;
			flag = -1;
		} else {
			child = child->right;
			flag = 1;
		}
	}
	child = newTreeNode(x);

	if (flag == -1) {
		parent->left = child;
	} else {
		parent->right = child;
	}
}

// insert exact mid value from arr to BST => to build height BST
void insertMidToBST(struct TreeNode *root, int *nums, int ite_left,
		    int ite_right)
{
	if (ite_left > ite_right)
		return;
	int ite_mid = ite_left + (ite_right - ite_left) / 2;
	insertBST(root, nums[ite_mid]);
	insertMidToBST(root, nums, ite_left, ite_mid - 1);
	insertMidToBST(root, nums, ite_mid + 1, ite_right);
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	if (numsSize < 1)
		return NULL;
	int ite_mid = (numsSize - 1) / 2;
	struct TreeNode *root = newTreeNode(nums[ite_mid]);
	insertMidToBST(root, nums, 0, ite_mid - 1);
	insertMidToBST(root, nums, ite_mid + 1, numsSize - 1);
	return root;
}

int main()
{
	return 0;
}
