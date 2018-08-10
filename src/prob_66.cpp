// 66. Plus One
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	if (digitsSize == 0)
		return NULL;
	*returnSize = digitsSize;
	int *digitsPlusOne = (int *)malloc(sizeof(int) * (*returnSize));
	// copy in reverse 1 2 3 => new 3 2 1
	for (int i = 0; i < (*returnSize); ++i) {
		digitsPlusOne[i] = digits[(*returnSize) - 1 - i];
	}

	// lowest + 1
	int d = digitsPlusOne[0] + 1;
	digitsPlusOne[0] = d % 10;
	int remember = d / 10;

	// other + remember
	for (int i = 1; i < (*returnSize); ++i) {
		d = digitsPlusOne[i] + remember;
		digitsPlusOne[i] = d % 10;
		remember = d / 10;
	}

	// 9 + 1 = 10 => array need to realloc
	if (remember != 0) {
		++(*returnSize);
		digitsPlusOne =
		    (int *)realloc(digitsPlusOne, sizeof(int) * (*returnSize));
		digitsPlusOne[(*returnSize) - 1] = remember;
	}

	// reverse in right order
	for (int i = 0, j = (*returnSize) - 1; i < j; ++i, --j) {
		int temp = digitsPlusOne[i];
		digitsPlusOne[i] = digitsPlusOne[j];
		digitsPlusOne[j] = temp;
	}
	return digitsPlusOne;
}

int main()
{
	int digits[] = {1, 9, 9, 9};
	int digitsSize = sizeof(digits) / sizeof(digits[0]);
	int returnSize;
	int *digitsPlusOne = plusOne(digits, digitsSize, &returnSize);
	for (int i = 0; i < returnSize; ++i) {
		printf("%d", digitsPlusOne[i]);
	}
	printf("\n");
	free(digitsPlusOne);
	return 0;
}