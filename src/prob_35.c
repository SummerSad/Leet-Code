/* Search a value in sorted arr
 * if not found
 * find position to insert
 */
#include <stdio.h>

void printArr(int *arr, int size)
{
        for (int i = 0; i < size; ++i) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

int searchInsert(int *nums, int numsSize, int target)
{
        int i = 0;
        while (i < numsSize && nums[i] < target) {
                ++i;
        }
        return i;
}

int main()
{
        int A[] = {1, 3, 5, 6};
        int size = sizeof(A) / sizeof(A[0]);
        int d = searchInsert(A, size, 7);
        printf("%d\n", d);
        return 0;
}
