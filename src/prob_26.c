// Remove Duplicates from Sorted Array
#include <stdio.h>

// return new len
int removeDuplicates(int *nums, int numsSize)
{
	if (!nums || numsSize < 1)
		return 0;
	int len = 1;
	for (int i = 1; i < numsSize; ++i) {
		int j;
		for (j = 0; j < len; ++j) {
			if (nums[i] == nums[j])
				break;
		}
		if (j == len) { // no dup
			nums[len] = nums[i];
			++len;
		}
	}
	return len;
}

int main()
{
	int arr[] = {1, 2, 1, 2, 1, 2, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	int nlen = removeDuplicates(arr, size);
	for (int i = 0; i < nlen; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
