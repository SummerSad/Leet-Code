// Maximum Subarray
#include <stdio.h>

int sum(int *arr, int from, int to)
{
        int sum = 0;
        for (int i = from; i <= to; ++i) {
                sum += arr[i];
        }
        return sum;
}

int maxSubArray(int *nums, int numsSize)
{
        int max = sum(nums, 0, numsSize - 1);
        for (int i = numsSize - 1; i >= 0; --i) {
                for (int j = 0; j <= numsSize - i - 1; ++j) {
                        if (max < sum(nums, j, j + i))
                                max = sum(nums, j, j + i);
                }
        }
        return max;
}

int main()
{
        int A[] = {-2,1};
        int size = sizeof(A) / sizeof(A[0]);
        printf("%d\n", maxSubArray(A, size));
        return 0;
}
