#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    int k;
    scanf("%d", &k);

    k = k % n;
    if (k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Make circular
    temp->next = head;

    // Move to (n - k)th node
    int steps = n - k;
    struct Node* curr = head;

    for (int i = 1; i < steps; i++)
        curr = curr->next;

    // New head
    head = curr->next;

    // Break circle
    curr->next = NULL;

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}