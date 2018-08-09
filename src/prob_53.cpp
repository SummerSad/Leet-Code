// 53. Maximum Subarray
#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int *nums, int numsSize)
{
	/* dynamic programing
	 * max of continous array end with i
	 * is arr[i] or max end with i - 1 + arr[i]
	 */
	int *maxEndWith = (int *)malloc(sizeof(int) * numsSize);
	maxEndWith[0] = nums[0];
	int max = nums[0];
	for (int i = 1; i < numsSize; ++i) {
		maxEndWith[i] =
		    nums[i] + (maxEndWith[i - 1] > 0 ? maxEndWith[i - 1] : 0);
		max = max > maxEndWith[i] ? max : maxEndWith[i];
	}

	free(maxEndWith);
	return max;
}

int main()
{
	int nums[] = {1, 2, 3, -4, -5, -6, 7};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d\n", maxSubArray(nums, numsSize));
	return 0;
}