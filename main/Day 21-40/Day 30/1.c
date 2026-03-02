#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coef = c;
    newnode->exp = e;
    newnode->next = NULL;
    return newnode;
}

void insertTerm(struct Node** head, int c, int e) {
    struct Node* newnode = createNode(c, e);

    // If list is empty or exponent is larger than head
    if (*head == NULL || e > (*head)->exp) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coef);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
}

int main() {
    int n, c, e;
    scanf("%d", &n);

    struct Node* poly = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insertTerm(&poly, c, e);
    }

    printPolynomial(poly);
    return 0;
}