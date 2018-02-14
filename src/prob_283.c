// Move 0 to end of arr
#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
        int newSize = numsSize;
        for (int i = 0; i < newSize;) {
                if (nums[i] == 0) {
                        --newSize;
                        for (int j = i; j < newSize; ++j) {
                                nums[j] = nums[j + 1];
                        }
                        nums[newSize] = 0;
                } else {
                        ++i;
                }
        }
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
        int A[] = {0, 1, 0, 3, 12};
        int size = sizeof(A) / sizeof(A[0]);
        moveZeroes(A, size);
        printArr(A, size);
        return 0;
}
