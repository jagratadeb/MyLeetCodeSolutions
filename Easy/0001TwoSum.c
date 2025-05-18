#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    // Allocate memory for the result array to store indices of two numbers
    *returnSize = 2;
    int *result = (int *)malloc(*returnSize * sizeof(int));

    // Iterate through the array to find two numbers that add up to target
    for (int i = 0; i < numsSize; i++)
    {
        int requiredValue = target - nums[i]; // Find the required value for nums[i]

        // Check previous elements to see if the required value exists
        for (int j = 0; j < i; j++)
        {
            if (nums[j] == requiredValue)
            {
                result[0] = j;
                result[1] = i;
                return result; // Return indices as soon as a match is found
            }
        }
    }

    // If no pair is found, free allocated memory and return NULL
    *returnSize = 0;
    free(result);
    return NULL;
}

/**
 * Complexity Analysis:
 * - Time Complexity: O(n²)
 *   - The algorithm uses a **nested loop** approach to check all pairs.
 *   - The outer loop runs **n** times, and the inner loop runs up to **n-1** times.
 *   - This results in a worst-case time complexity of **O(n²)**.
 *
 * - Space Complexity: O(1)
 *   - The function only allocates **a fixed-size array of length 2**.
 *   - No additional space is used apart from input storage.
 *   - Hence, **space complexity is O(1)**.
 */
