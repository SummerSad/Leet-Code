#include <limits.h>
#include <stdio.h>

int pow_10(int n)
{
	int val = 1;
	for (int i = 0; i < n; ++i) {
		val *= 10;
	}
	return val;
}

int isPalindrome(int x)
{
	if (x < 0) {
		return 0;
	}

	int digit = 0;
	int dup = x;
	while (dup > 0) {
		dup /= 10;
		++digit;
	}
	for (int i = 0; i < digit / 2; ++i) {
		printf("%d %d\n", x / pow_10(i) % 10,
		       x / pow_10(digit - i - 1) % 10);
		if ((x / pow_10(i) % 10) != (x / pow_10(digit - i - 1)) % 10)
			return 0;
	}
	return 1;
}

int main()
{
	printf("%d\n", isPalindrome(-2147483648));
	return 0;
}
