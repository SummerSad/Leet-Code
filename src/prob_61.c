/* Rotate List
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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

int lenNode(struct ListNode *head)
{
	int len = 0;
	struct ListNode *p = head;
	while (p) {
		++len;
		p = p->next;
	}
	return len;
}

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	if (!head || !(head->next))
		return head;
	k %= lenNode(head);
	if (k < 1)
		return head;

	struct ListNode *prev = head;
	struct ListNode *cur = head;
	while (k > 0) {
		cur = cur->next;
		--k;
	}
	while (cur && cur->next) {
		prev = prev->next;
		cur = cur->next;
	}
	// rotate
	if (cur) {
		struct ListNode *newHead = prev->next;
		prev->next = cur->next;
		cur->next = head;
		return newHead;
	}
	return head;
}

typedef struct ListNode *pNode;

int main()
{
	pNode p0 = init(1);
	pNode p1 = init(2);
	p0->next = p1;

	pNode p = rotateRight(p0, 200000);
	while (p) {
		printf("%d\n", p->val);
		p = p->next;
	}

	free(p0);
	free(p1);
	return 0;
}
