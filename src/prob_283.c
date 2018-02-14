// Move 0 to end of arr
#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
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
        return 0;
}
