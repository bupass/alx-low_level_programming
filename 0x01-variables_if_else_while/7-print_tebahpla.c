/*
 * 
 * 
 */
#include <stdio.h>
/**
 * main - Prints the lowercase alphabet in reverse.
 *
 * Return: 0 if successful, non-zero otherwise.
 * Return: Always 0.
 */
int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
		putchar(letter);

	putchar('\n');

	return (0);
}
