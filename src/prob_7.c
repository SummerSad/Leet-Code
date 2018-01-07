/* Reverse Integer
 * return 0 when overflow
 */
#include <limits.h>
#include <stdio.h>

int reverse(int x)
{
	int positive = x >= 0 ? 1 : -1;
	long long rev = 0; // make rev big enough
	x *= positive;     // make x > 0
	while (x > 0) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	rev *= positive;
	if (rev < INT_MIN || rev > INT_MAX)
		return 0;
	return rev;
}

int main()
{
	int n = -2147483412;
	reverse(n);
	printf("%d\n", reverse(n));
	return 0;
}
