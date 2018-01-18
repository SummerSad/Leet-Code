// Merge Two Sorted Lists
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

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	if (!l1 && !l2)
		return NULL;
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	struct ListNode *newHead;
	struct ListNode *other;
	if (l1->val > l2->val) {
		newHead = l2;
		other = l1;
	} else {
		newHead = l1;
		other = l2;
	}
	// merge each node from 1 list to other list
	while (other) {
		struct ListNode *temp = other->next;

		struct ListNode *prev_p = NULL;
		struct ListNode *p = newHead;
		while (p && p->val <= other->val) {
			prev_p = p;
			p = p->next;
		}
		prev_p->next = other;
		other->next = p;

		other = temp;
	}
	return newHead;
}

typedef struct ListNode *pNode;

int main()
{
	pNode p1 = init(1);
	pNode p2 = init(2);
	pNode p3 = init(4);
	p1->next = p2;
	p2->next = p3;
	pNode q1 = init(1);
	pNode q2 = init(3);
	pNode q3 = init(4);
	q1->next = q2;
	q2->next = q3;

	struct ListNode *p = mergeTwoLists(p1, q1);
	while (p) {
		printf("%d\n", p->val);
		p = p->next;
	}

	free(p1);
	free(p2);
	free(p3);
	free(q1);
	free(q2);
	free(q3);
	return 0;
}
