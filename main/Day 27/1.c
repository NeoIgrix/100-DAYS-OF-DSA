#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to find length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    if (len1 > len2)
        while (diff--) ptr1 = ptr1->next;
    else
        while (diff--) ptr2 = ptr2->next;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *temp = NULL, *newNode;

    // Create first list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head1 == NULL)
            head1 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    scanf("%d", &m);

    struct Node *head2 = NULL;
    temp = NULL;

    // Create second list (separate first)
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head2 == NULL)
            head2 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    // Artificially create intersection if matching value exists
    struct Node* p1 = head1;
    while (p1 != NULL) {
        struct Node* p2 = head2;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                p2->next = p1->next;  // connect intersection
                break;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    struct Node* intersect = getIntersection(head1, head2);

    if (intersect)
        printf("%d", intersect->data);
    else
        printf("No Intersection");

    return 0;
}