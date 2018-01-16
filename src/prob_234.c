// Palindrome Linked List
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

int isPalindrome(struct ListNode *head)
{
	if (!head || !head->next)
		return 1;
	// find mid
	struct ListNode *mid = head;
	struct ListNode *tail = head;
	while (tail && tail->next) {
		mid = mid->next;
		tail = tail->next->next;
	}

	// reverse second half
	if (tail) {
		// number of nodes is odd
		mid = mid->next;
	}
	struct ListNode *prev = NULL;
	struct ListNode *cur = mid;
	while (cur) {
		struct ListNode *temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	// compare first half and second half
	struct ListNode *p = head;
	while (prev) {
		if (p->val != prev->val)
			return 0;
		p = p->next;
		prev = prev->next;
	}
	return 1;
}

int main()
{
	pNode head = init(0);
	pNode p1 = init(1);
	pNode p2 = init(-1);
	pNode p3 = init(1);
	pNode p4 = init(2);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	int result = isPalindrome(head);
	printf("%d\n", result);

	free(head);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	return 0;
}
