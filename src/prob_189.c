// Rotate array
#include <stdio.h>

void printArr(int *arr, int size)
{
        for (int i = 0; i < size; ++i) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void reverse(int *arr, int from, int to)
{
        for (int i = from, j = to; i < j; ++i, --j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
}

void rotate(int *nums, int numsSize, int k)
{
        k %= numsSize;
        reverse(nums, 0, numsSize - k - 1);
        reverse(nums, numsSize - k, numsSize - 1);
        reverse(nums, 0, numsSize - 1);
}

int main()
{
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        int size = sizeof(arr) / sizeof(arr[0]);
        rotate(arr, size, 3);
        printArr(arr, size);
        return 0;
}
