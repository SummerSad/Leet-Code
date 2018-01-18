/* Remove Duplicates from Sorted List II
 * delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list
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

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (!head || !(head->next))
		return head;
	struct ListNode *prev_p = NULL;
	struct ListNode *p = head;
	struct ListNode *newHead = head;
	while (p) {
		struct ListNode *prev = p;
		struct ListNode *cur = p->next;
		int dup = 0;
		// remove cur dup with p
		while (cur) {
			if (p->val == cur->val) {
				prev->next = cur->next;
				// free(cur);
				cur = prev->next;
				dup = 1;
			} else {
				prev = cur;
				cur = cur->next;
			}
		}
		if (dup) {
			// remove p
			if (!prev_p) {
				newHead = p->next;
				// free(p);
				p = newHead;
			} else {
				prev_p->next = p->next;
				// free(p);
				p = prev_p->next;
			}
		} else {
			prev_p = p;
			p = p->next;
		}
	}
	return newHead;
}

typedef struct ListNode *pNode;

int main()
{
	pNode p0 = init(3);
	pNode p1 = init(1);
	pNode p2 = init(1);
	pNode p3 = init(2);
	pNode p4 = init(1);
	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	pNode p = deleteDuplicates(p0);
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
