#include <stdio.h>
#include <stdlib.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    *returnSize = n;
    // Allocate memory for the array of string pointers
    char **result = (char **)malloc(n * sizeof(char *));

    for (int i = 1; i <= n; i++)
    {
        // If divisible by both 3 and 5, set to "FizzBuzz"
        if (i % 3 == 0 && i % 5 == 0)
        {
            result[i - 1] = "FizzBuzz";
        }
        // If divisible by 3 only, set to "Fizz"
        else if (i % 3 == 0)
        {
            result[i - 1] = "Fizz";
        }
        // If divisible by 5 only, set to "Buzz"
        else if (i % 5 == 0)
        {
            result[i - 1] = "Buzz";
        }
        // Otherwise, convert the number to a string
        else
        {
            // Allocate enough space for the integer as a string (max 11 digits + null terminator)
            result[i - 1] = (char *)malloc(12 * sizeof(char));
            sprintf(result[i - 1], "%d", i);
        }
    }
    return result;
}

/*
 * Complexity Analysis:
 * - Time Complexity: O(n)
 *   - The function iterates from 1 to n exactly once, performing constant-time operations for each value.
 *   - Thus, the overall time complexity is O(n).
 *
 * - Space Complexity: O(n)
 *   - The function allocates an array of n pointers to strings.
 *   - For numbers not divisible by 3 or 5, it allocates up to 12 bytes per string (to store the integer as a string).
 *   - The space used for the result array and the strings is proportional to n, so the space complexity is O(n).
 */