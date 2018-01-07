/* String to Integer (atoi)
 */
#include <limits.h>
#include <stdio.h>
#include <string.h>

int isNum(char c)
{
	return c >= '0' && c <= '9';
}

int myAtoi(char *str)
{
	if (!str || str[0] == '\0')
		return 0;
	long long n = 0;

	// little edgy
	int start = 0;
	while (str[start] == ' ') {
		++start;
	}
	int d;
	if (str[start] == '-') {
		d = -1;
		start += 1;
	} else if (str[start] == '+') {
		d = 1;
		start += 1;
	} else {
		d = 1;
	}
	int digit = 0;
	for (int i = start; str[i] != '\0'; ++i) {
		if (isNum(str[i])) {
			n = n * 10 + str[i] - '0';
			++digit;
		} else {
			break;
		}
		// overfloat
		if (digit > 10)
			break;
	}
	if (n < INT_MIN || n > INT_MAX) {
		if (d == 1)
			return INT_MAX;
		else if (d == -1)
			return INT_MIN;
	}
	return n * d;
}

int main()
{
	char s[] = "18446744073709551617";
	printf("%d\n", myAtoi(s));
	return 0;
}
