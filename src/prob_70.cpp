/*
 * 70. Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 */

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
	int *climb_arr = (int *)malloc(sizeof(int) * (n + 1));
	climb_arr[0] = 0;
	climb_arr[1] = 1;
	climb_arr[2] = 2;
	for (int i = 3; i <= n; ++i) {
		climb_arr[i] = climb_arr[i - 1] + climb_arr[i - 2];
	}
	int result = climb_arr[n];
	free(climb_arr);
	return result;
}

int main()
{
	printf("%d\n", climbStairs(10));
	return 0;
}