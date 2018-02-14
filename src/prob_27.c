// Remove element in arrays
#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
	int newSize = numsSize;
	for (int i = 0; i < newSize;) {
		if (nums[i] == val) {
			--newSize;
			for (int j = i; j < newSize; ++j) {
				nums[j] = nums[j + 1];
			}
		} else {
			++i;
		}
	}
	return newSize;
}

void printArr(int *arr, int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int A[] = {3, 2, 1, 3};
	int size = sizeof(A) / sizeof(A[0]);
	int newSize = removeElement(A, size, 3);
	printArr(A, newSize);
	return 0;
}
