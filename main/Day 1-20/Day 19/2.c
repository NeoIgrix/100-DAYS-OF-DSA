int maxSubarraySumCircular(int* nums, int numsSize) {

    int totalSum = 0;

    int currentMax = nums[0], maxSub = nums[0];
    int currentMin = nums[0], minSub = nums[0];

    totalSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];

        // Standard Kadane for max
        currentMax = (currentMax > 0) ? currentMax + num : num;
        if (currentMax > maxSub)
            maxSub = currentMax;

        // Kadane for min
        currentMin = (currentMin < 0) ? currentMin + num : num;
        if (currentMin < minSub)
            minSub = currentMin;

        totalSum += num;
    }

    // If all numbers are negative
    if (maxSub < 0)
        return maxSub;

    return (maxSub > totalSum - minSub) ? maxSub : totalSum - minSub;
}
