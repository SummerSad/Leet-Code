// 141. Linked List Cycle
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 * Imagine 2 runners, slow and fast runner
 * If there is a cycle, fast runner will meet slow runner
 * Otherwise there is not.
 */
bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head->next;
    while (slow_ptr != fast_ptr) {
        if (slow_ptr == NULL || fast_ptr == NULL)
            return false;
        slow_ptr = slow_ptr->next;
        if (fast_ptr->next == NULL)
            return false;
        fast_ptr = fast_ptr->next->next;
    }
    return true;
}

int main()
{
    return 0;
}
