// Remove Duplicates from Sorted List
#include <stdio.h>
#include <stdlib.h>

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

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (!head || !(head->next))
		return head;
	struct ListNode *prev = head;
	struct ListNode *cur = head->next;
	while (cur) {
		struct ListNode *p = head;
		while (p != cur) {
			if (p->val == cur->val)
				break;
			p = p->next;
		}
		// No dup
		if (p == cur) {
			prev = cur;
			cur = cur->next;
		}
		// cur is dup
		else {
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
	}
	return head;
}

typedef struct ListNode *pNode;

int main()
{
	return 0;
}
