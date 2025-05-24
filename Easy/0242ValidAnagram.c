#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
    // If lengths are not equal, they cannot be anagrams
    if (strlen(s) != strlen(t))
    {
        return false;
    }

    // Create a frequency array for all ASCII characters
    // Will work with H[128] but that will be limited to (A-Z,a-z,0-9,!@#$%^&*())
    int H[256] = {0};
    int i;

    // Count frequency of each character in s
    for (i = 0; s[i] != '\0'; i++)
    {
        H[(unsigned char)s[i]]++;
    }
    // Subtract frequency for each character in t
    for (i = 0; t[i] != '\0'; i++)
    {
        H[(unsigned char)t[i]]--;
    }
    // If any character count is not zero, not an anagram
    for (i = 0; i < 256; i++)
    {
        if (H[i] != 0)
        {
            return false;
        }
    }

    return true;
}

/**
 * Complexity Analysis:
 * - Time Complexity: O(n)
 *   - n is the length of the input strings (since both are the same length).
 *   - Each string is traversed once, and the frequency array is checked once (constant size).
 *
 * - Space Complexity: O(1)
 *   - The frequency array H has a fixed size of 256 (for all ASCII characters),
 *     so space usage does not depend on input size.
 */