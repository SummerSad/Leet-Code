#include <stdio.h>

int mySqrt(int x)
{
	if (x <= 0)
		return 0;
	// Newton algorithm
	long long d = x;
	while (d * d > x) {
		d = (x / d + d) / 2;
	}
	return d;
}

int isPerfectSquare(int num)
{
	int d = mySqrt(num);
	if (d * d == num)
		return 1;
	return 0;
}

int main()
{
	printf("%d\n", isPerfectSquare(16));
	return 0;
}
