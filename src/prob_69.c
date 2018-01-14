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

int main()
{
	printf("%d\n", mySqrt(8));
	return 0;
}
