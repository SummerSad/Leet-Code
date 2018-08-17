/* 171. Excel Sheet Column Number
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 */

#include <stdio.h>

int titleToNumber(char *s)
{
	int n = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		n *= 26;
		n += s[i] - 'A' + 1;
	}
	return n;
}

int main()
{
	printf("%d\n", titleToNumber("ZY"));
	return 0;
}
