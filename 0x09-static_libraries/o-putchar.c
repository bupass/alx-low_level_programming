#include <unistd.h>
/**
 * _putchar-write the character to stdout
 * @c the character to print
 *
 * Return on success 1.
 * on error,-1 is returned and errno is set appropriety
 */

int _putchar(char c)
{
    return write(1, &c, 1);
}
