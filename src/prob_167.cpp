/*
 * 167. Two Sum II - Input array is sorted
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number. The function
 * twoSum should return indices of the two numbers such that they add up to the
 * target, where index1 must be less than index2.
 * Note:
 *  Your returned answers (both index1 and index2) are not zero-based.
 *  You may assume that each input would have exactly one solution and you may
 *  not use the same element twice.
 */
#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    for (int i = 0; i < numbersSize; ++i) {
        if (numbers[i] > target)
            break;
        for (int j = i + 1; j < numbersSize; ++j) {
            if (numbers[i] + numbers[j] == target) {
                int *arr_2sum = (int *)malloc(sizeof(int) * 2);
                arr_2sum[0] = i + 1;
                arr_2sum[1] = j + 1;
                *returnSize = 2;
                return arr_2sum;
            }
        }
    }
    return NULL;
}

int main()
{
    return 0;
}
