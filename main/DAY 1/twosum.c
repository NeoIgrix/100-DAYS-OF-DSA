/*#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int nums[n];
    for (int i = 0; i <n; i++)
    {
    scanf("%d",&nums[i]);
    }
    int target;
    scanf("%d",&target);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d, %d]", i, j);
                return 0;
            }
        }
    }
    return 0;
}*/
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL; // guaranteed one solution, so unreachable
}

