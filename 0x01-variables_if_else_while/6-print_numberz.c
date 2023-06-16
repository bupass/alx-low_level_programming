/*
 * File: 6-print_numberz.c
 * Auth: symon Abok
 */
#include <stdio.h>
/**
 * main - Prints all single digit numbers of base 10 starting from 0,
 *        only using putchar and without char variables.
 *
 * Return: 0 if successful, non-zero otherwise.
 * Return: Always 0.
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	putchar('\n');

	return (0);
}
