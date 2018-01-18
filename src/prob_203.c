/* Remove Linked List Elements
 * Remove all elements from a linked list of integers
 * that have value val.
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

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode *prev = NULL;
	struct ListNode *cur = head;
	struct ListNode *newHead = head;
	while (cur) {
		if (cur->val == val) {
			if (!prev) {
				newHead = cur->next;
				// free(cur);
				cur = newHead;
			} else {
				prev->next = cur->next;
				// free(cur);
				cur = prev->next;
			}
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
	return newHead;
}

typedef struct ListNode *pNode;

int main()
{
	pNode p0 = init(2);
	pNode p1 = init(1);
	pNode p2 = init(1);
	pNode p3 = init(1);
	pNode p4 = init(1);
	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	pNode p = removeElements(p0, 1);
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
