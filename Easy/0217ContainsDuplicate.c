#include <stdio.h>
#include <stdbool.h>

// Comparator function for qsort()
// Returns negative if *a < *b, zero if equal, positive if *a > *b
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int *nums, int numsSize)
{
    // Sort the array so that duplicates are adjacent
    qsort(nums, numsSize, sizeof(int), compare);

    // Check for adjacent duplicates
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

/**
 * Complexity Analysis:
 * - Time Complexity: O(n log n)
 *   - The array is sorted using qsort, which on average takes O(n log n) time.
 *   - The subsequent single pass to check for duplicates is O(n).
 *   - Overall, the time complexity is O(n log n).
 *
 * - Space Complexity: O(1)
 *   - The sorting is done in-place (qsort does not use extra space for the array).
 *   - No additional data structures are used.
 *   - Hence, space complexity is O(1).
 */