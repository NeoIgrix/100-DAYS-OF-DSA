#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top != -1)
        top--;
}

int main() {
    int n, m;

    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);

    // Pop m elements
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display stack from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}