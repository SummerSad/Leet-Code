// Reverse Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *pNode;
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *init(int val)
{
	struct ListNode *temp = malloc(sizeof(struct ListNode));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

void freeNode(pNode *head)
{
	while (*head) {
		pNode temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

struct ListNode *reverseList(struct ListNode *head)
{
	struct ListNode *prev = NULL;
	struct ListNode *cur = head;
	while (cur) {
		struct ListNode *temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}

int main()
{
	return 0;
}
