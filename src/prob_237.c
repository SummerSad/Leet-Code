/* Delete Node in a Linked List
 * Given a node in a list
 * delete that node without knowing head
 * given only access to that node.
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

void deleteNode(struct ListNode *node)
{
	if (!node)
		return;
	struct ListNode *pNext = node->next;
	if (pNext) {
		node->val = pNext->val;
		node->next = pNext->next;
	}
}

typedef struct ListNode *pNode;

int main()
{
	pNode p0 = init(1);
	pNode p1 = init(2);
	pNode p2 = init(3);
	pNode p3 = init(4);
	p0->next = p1;
	p1->next = p2;
	p2->next = p3;

	deleteNode(p3);
	pNode p = p0;
	while (p) {
		printf("%d\n", p->val);
		p = p->next;
	}

	free(p0);
	free(p1);
	free(p2);
	free(p3);
	return 0;
}
