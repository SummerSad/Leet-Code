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
	for (int i = start; str[i] != '\0'; ++i) {
		if (isNum(str[i]))
			n = n * 10 + str[i] - '0';
		else
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
	char s[] = "9223372036854775809";
	printf("%d\n", myAtoi(s));
	return 0;
}
