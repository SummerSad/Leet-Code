/*
 * 67. Add Binary
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b)
{
	int len_sum = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	char *sum = (char *)malloc(sizeof(char) * (len_sum + 1));

	int iterative_sum = 0;
	int iterative_a = strlen(a) - 1;
	int iterative_b = strlen(b) - 1;
	int remember = 0;

	// sum in reverse
	for (; iterative_a >= 0 && iterative_b >= 0;
	     --iterative_a, --iterative_b) {
		int d = a[iterative_a] - '0' + b[iterative_b] - '0' + remember;
		sum[iterative_sum++] = d % 2 + '0';
		remember = d / 2;
	}

	// a not yet finished
	while (iterative_a >= 0) {
		int d = a[iterative_a] - '0' + remember;
		sum[iterative_sum++] = d % 2 + '0';
		remember = d / 2;
		--iterative_a;
	}

	// b not yet finished
	while (iterative_b >= 0) {
		int d = b[iterative_b] - '0' + remember;
		sum[iterative_sum++] = d % 2 + '0';
		remember = d / 2;
		--iterative_b;
	}

	// remember not yet 0
	if (remember != 0) {
		++len_sum;
		sum = (char *)realloc(sum, sizeof(char) * (len_sum + 1));
		sum[iterative_sum++] = remember + '0';
	}
	sum[iterative_sum] = '\0';

	// reserve sum
	for (int i = 0, j = len_sum - 1; i < j; ++i, --j) {
		char temp = sum[i];
		sum[i] = sum[j];
		sum[j] = temp;
	}

	return sum;
}

int main()
{
	char *sum = addBinary("100101", "11011111");
	printf("%s\n", sum);
	free(sum);
	return 0;
}