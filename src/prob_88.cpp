// 88. Merge Sorted Array
// The number of elements initialized in nums1 and nums2 are m and n
// respectively. You may assume that nums1 has enough space(size that is greater
// or equal to m + n) to hold additional elements from nums2.

#include <stdio.h>
#include <stdlib.h>

void merge(int *nums1, int m, int *nums2, int n)
{
	int len = m + n;
	int *sorted_arr = (int *)malloc(sizeof(int) * len);
	int ite_1 = 0;
	int ite_2 = 0;
	int ite_sorted = 0;

	// fill sorted arr
	for (; ite_1 < m && ite_2 < n;) {
		if (nums1[ite_1] < nums2[ite_2]) {
			sorted_arr[ite_sorted++] = nums1[ite_1++];
		} else {
			sorted_arr[ite_sorted++] = nums2[ite_2++];
		}
	}

	// nums1 still
	while (ite_1 < m) {
		sorted_arr[ite_sorted++] = nums1[ite_1++];
	}

	// nums2 still
	while (ite_2 < n) {
		sorted_arr[ite_sorted++] = nums2[ite_2++];
	}

	for (int i = 0; i < len; ++i) {
		nums1[i] = sorted_arr[i];
	}
	free(sorted_arr);
}

int main()
{
	int nums_1[] = {1, 3, 5, 0, 0, 0};
	int nums_2[] = {2, 4, 6};
	int len = sizeof(nums_1) / sizeof(nums_1[0]);
	merge(nums_1, 3, nums_2, 3);
	for (int i = 0; i < len; ++i)
		printf("%d ", nums_1[i]);
	printf("\n");
	return 0;
}