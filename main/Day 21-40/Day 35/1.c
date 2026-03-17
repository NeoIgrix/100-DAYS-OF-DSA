#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int val) {
    queue[++rear] = val;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    // Display queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}