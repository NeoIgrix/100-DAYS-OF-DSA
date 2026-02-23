#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    int n, m;

    node *head1 = NULL, *head2 = NULL;
    node *temp = NULL, *newNode = NULL;

    /* Create first sorted list */
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (node*)malloc(sizeof(node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    /* Create second sorted list */
    scanf("%d", &m);
    temp = NULL;

    for (int i = 0; i < m; i++) {
        newNode = (node*)malloc(sizeof(node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    /* Merge two sorted lists */
    node dummy;
    node *tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    /* Print and free merged list */
    node *current = dummy.next;
    node *freeNode;

    while (current != NULL) {
        printf("%d ", current->data);
        freeNode = current;
        current = current->next;
        free(freeNode);
    }

    return 0;
}