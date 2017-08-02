#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

struct Node *makeNode(int val)
{
    struct Node *re = malloc(sizeof(struct Node));
    re->val = val;
    re->next = NULL;
}

void addHead(struct Node **head, int val)
{
    struct Node *temp = makeNode(val);
    temp->next = *head;
    *head = temp;
}

void addTail(struct Node **head, int val)
{
    struct Node *temp = makeNode(val);
    if (*head == NULL)
        *head = temp;
    else {
        struct Node *cur = *head;
        while (cur->next != NULL) cur = cur->next;
        cur->next = temp;
    }
}

void delHead(struct Node **head)
{
    if (head) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        temp = NULL;
    }
}

void delNode(struct Node **head)
{
    while (*head) {
        delHead(head);
    }
}

void priNode(struct Node *head)
{
    if (head == NULL)
        printf("NULL\n");
    else {
        printf("%d->", head->val);
        priNode(head->next);
    }
}

struct Node *addTwo(struct Node *head_1, struct Node *head_2)
{
    struct Node *head_sum = NULL;
    struct Node *p = head_1, *q = head_2;
    int carry = 0;
    while (p || q) {
        int x = (p == NULL) ? 0 : p->val;
        int y = (q == NULL) ? 0 : q->val;
        int sum = x + y + carry;
        carry = sum / 10;
        addTail(&head_sum, sum % 10);
        if (p) p = p->next;
        if (q) q = q->next;
    }
    return head_sum;
}

int main()
{
    struct Node *head_1 = NULL;
    addHead(&head_1, 3);
    addHead(&head_1, 4);
    addHead(&head_1, 2);

    struct Node *head_2 = NULL;
    addHead(&head_2, 4);
    addHead(&head_2, 6);
    addHead(&head_2, 5);

    struct Node *sum = addTwo(head_1, head_2);
    priNode(sum);

    delNode(&head_1);
    delNode(&head_2);
    delNode(&sum);
    return 0;
}
