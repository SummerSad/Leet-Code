#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
				     struct ListNode *headB)
{
	struct ListNode *ite_a = headA;
	struct ListNode *ite_b = headB;
	while (ite_a != ite_b) {
		ite_a = ite_a != NULL ? ite_a->next : headB;
		ite_b = ite_b != NULL ? ite_b->next : headA;
	}
	return ite_a;
}

int main()
{
	return 0;
}
