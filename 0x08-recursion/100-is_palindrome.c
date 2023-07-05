#include <stdio.h>

int is_palindrome(char *s)
{
    char *end; /* Declare the variable 'end' at the beginning of the function */

    if (s == NULL)
        return 0;

    if (*s == '\0')
        return 1;

    end = s;
    while (*(end + 1) != '\0')
        end++;

    while (s < end)
    {
        if (*s != *end)
            return 0;
        s++;
        end--;
    }

    return 1;
}

int main(void)
{
    int r;

    r = is_palindrome("level");
    printf("%d\n", r);
    r = is_palindrome("redder");
    printf("%d\n", r);
    r = is_palindrome("test");
    printf("%d\n", r);
    r = is_palindrome("step on no pets");
    printf("%d\n", r);
    return 0;
}
