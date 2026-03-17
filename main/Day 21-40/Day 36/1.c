#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int m;
    scanf("%d", &m);

    int front = 0;

    // Perform m dequeues
    for (int i = 0; i < m; i++) {
        front = (front + 1) % n;
    }

    // Display queue from front in circular order
    for (int i = 0; i < n; i++) {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}