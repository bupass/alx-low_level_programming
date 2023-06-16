/*
 * File: 9-print_comb.c
 * Auth: abok
 */
#include <stdio.h>
/**
 * main - Prints all possible combinations of single-digit numbers.
 *
 * Return: 0 if successful, non-zero otherwise.
 * Return: Always 0.
 */
int main(void)
{
	int num = 0;

	while (1)
	for (num = 0; num <= 9; num++)
	{
		putchar((num % 10) + '0');
		if (num == 9)
		{
			break;
		}
		else
		{
			putchar(44);
			putchar(32);
		}
		num++;
			continue;

		putchar(',');
		putchar(' ');
	}

	putchar('\n');

	return (0);
}
