int wildcmp(char *s1, char *s2)
{
    /* If both strings are empty, they are considered identical */
    if (*s1 == '\0' && *s2 == '\0')
        return 1;

    /* If the current characters match, move to the next characters */
    if (*s1 == *s2)
        return wildcmp(s1 + 1, s2 + 1);

    /* If the wildcard '*' is encountered in s2, try all possibilities */
    if (*s2 == '*')
    {
        /* Skip the '*' in s2 and try to match the remaining s2 with each character of s1 */
        if (wildcmp(s1, s2 + 1))
            return 1;

        /* If the above attempt fails, try to match the remaining s1 with the remaining s2 */
        if (*s1 != '\0' && wildcmp(s1 + 1, s2))
            return 1;
    }

    /* If none of the conditions are satisfied, the strings are not identical */
    return 0;
}
