/*
 * 136. Single Number
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 */

#include <stdio.h>

int singleNumber(int *nums, int numsSize)
{
	// sort
	for (int i = 0; i < numsSize; ++i) {
		for (int j = i + 1; j < numsSize; ++j) {
			if (nums[i] > nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	// find the odd
	int odd = -1;
	for (int i = 0; i < numsSize;) {
		if (i + 1 < numsSize && nums[i] == nums[i + 1]) {
			i += 2;
		} else {
			odd = nums[i];
			break;
		}
	}
	return odd;
}

int main(int argc, char **argv)
{
	int nums[] = {1, 2, 3, 3, 2, 1, 5};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d\n", singleNumber(nums, numsSize));
	return 0;
}
