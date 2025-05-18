#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    // Initialize the return size to 2, as we need to return two indices
    *returnSize = 2;
    int *result;
    // Allocate memory for the result array
    result = (int *)malloc(*returnSize * sizeof(int));

    // Initialize two pointers: one at the beginning (i) and one at the end (j)
    int i = 0;
    int j = numbersSize - 1;

    // Iterate while the two pointers do not cross each other
    while (i < j)
    {
        int sum = numbers[i] + numbers[j];

        // If the sum of the two numbers matches the target, return their indices
        if (sum == target)
        {
            result[0] = i + 1; // Storing 1-based index
            result[1] = j + 1;
            return result;
        }
        // If the sum is less than the target, move the left pointer forward
        else if (sum < target)
        {
            i++;
        }
        // If the sum is greater than the target, move the right pointer backward
        else
        {
            j--;
        }
    }

    // If no solution is found, reset returnSize and free allocated memory
    *returnSize = 0;
    free(result);
    return NULL;
}

/**
 * Complexity Analysis:
 * - Time Complexity: O(n)
 *   - The two-pointer approach ensures that we traverse the array at most once.
 *   - Each iteration either increments `i` or decrements `j`, leading to linear time complexity.
 *
 * - Space Complexity: O(1)
 *   - We only use a fixed-size array of length 2 to store the result.
 *   - No additional space is used beyond this, making it constant space complexity.
 */
