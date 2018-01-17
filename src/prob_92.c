/* Reverse Linked List II
 * Reverse a linked list from position m to n.
 * Do it in-place and in one-pass.
 * 1 <= m <= n <= length of list
 */
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

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	int newHead;
	if (m > 1)
		newHead = 0;
	else
		newHead = 1;

	struct ListNode *prev = NULL;
	struct ListNode *cur = head;
	while (m > 1) {
		prev = cur;
		cur = cur->next;
		--m;
		--n;
	}

	// prev_low -> low or m -> ... n -> x
	// prev_low -> n ... -> low or m -> x
	struct ListNode *prev_low = prev;
	struct ListNode *low = cur;
	while (n > 0) {
		struct ListNode *temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		--n;
	}
	low->next = cur;
	if (prev_low)
		prev_low->next = prev;

	if (newHead)
		return prev;
	return head;
}

typedef struct ListNode *pNode;

int main()
{
	pNode p0 = init(0);
	pNode p1 = init(1);
	pNode p2 = init(2);
	pNode p3 = init(3);
	pNode p4 = init(4);

	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	pNode p = reverseBetween(p0, 1, 3);
	while (p) {
		printf("%d\n", p->val);
		p = p->next;
	}

	free(p0);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	return 0;
}
