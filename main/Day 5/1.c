#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);

    int arr[500];
    int total = 0;

    for (int i = 0; i < p; i++) {
        scanf("%d", &arr[total++]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr[total++]);
    }

    // Simple bubble sort
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
