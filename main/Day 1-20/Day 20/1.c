#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long sum;
    int count;
} Hash;

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix = 0;
    long long result = 0;

    // Simple dynamic hash storage
    Hash* hash = (Hash*)malloc(sizeof(Hash) * (2 * n + 1));
    int size = 0;

    // Insert prefix sum 0 initially
    hash[size].sum = 0;
    hash[size].count = 1;
    size++;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int found = 0;
        for (int j = 0; j < size; j++) {
            if (hash[j].sum == prefix) {
                result += hash[j].count;
                hash[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            hash[size].sum = prefix;
            hash[size].count = 1;
            size++;
        }
    }

    printf("%lld", result);

    free(hash);
    return 0;
}