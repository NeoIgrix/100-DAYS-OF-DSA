#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char token[20];

    while (scanf("%s", token) != EOF) {

        // If operand
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }

        // Operator
        else {
            int b = pop();
            int a = pop();
            int res;

            if (token[0] == '+')
                res = a + b;
            else if (token[0] == '-')
                res = a - b;
            else if (token[0] == '*')
                res = a * b;
            else if (token[0] == '/')
                res = a / b;

            push(res);
        }
    }

    printf("%d", pop());

    return 0;
}