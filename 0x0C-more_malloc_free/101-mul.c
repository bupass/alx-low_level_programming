#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int is_positive_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int _putchar(char c)
{
    return write(1, &c, 1);
}

void multiply(const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len_result = len1 + len2;
    int *result = calloc(len_result, sizeof(int));

    if (result == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(98);
    }

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int prod = digit1 * digit2;
            int sum = result[i + j + 1] + prod;

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    int start = 0;
    while (start < len_result && result[start] == 0) {
        start++;
    }

    if (start == len_result) {
        _putchar('0');
    } else {
        for (int i = start; i < len_result; i++) {
            _putchar(result[i] + '0');
        }
    }

    _putchar('\n');

    free(result);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Incorrect number of arguments\n");
        return 98;
    }

    if (!is_positive_number(argv[1]) || !is_positive_number(argv[2])) {
        printf("Error: Invalid input, arguments should be positive numbers\n");
        return 98;
    }

    multiply(argv[1], argv[2]);

    return 0;
}
