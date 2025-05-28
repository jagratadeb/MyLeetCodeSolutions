#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(char *s)
{
    int i, length;
    bool isSame = true;

    char *validArray = (char *)malloc((strlen(s) + 1) * sizeof(char));
    int validIndex = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            validArray[validIndex++] = s[i] + 32;
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            validArray[validIndex++] = s[i];
        }
    }
    validArray[validIndex] = '\0';

    length = validIndex;

    for (i = 0; i < (length / 2); i++)
    {
        if (validArray[i] != validArray[length - i - 1])
        {
            isSame = false;
            break;
        }
    }

    free(validArray);
    return isSame;
}
