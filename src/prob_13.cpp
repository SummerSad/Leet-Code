/*
 * 13. Roman to Integer
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 */

#include <stdio.h>

int romanToInt(char *s)
{
	int value = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == 'M')
			value += 1000;
		else if (s[i] == 'D')
			value += 500;
		else if (s[i] == 'C') {
			if (s[i + 1] == 'D') {
				value += 400;
				++i;
			} else if (s[i + 1] == 'M') {
				value += 900;
				++i;
			} else
				value += 100;
		} else if (s[i] == 'L')
			value += 50;
		else if (s[i] == 'X') {
			if (s[i + 1] == 'L') {
				value += 40;
				++i;
			} else if (s[i + 1] == 'C') {
				value += 90;
				++i;
			} else
				value += 10;
		} else if (s[i] == 'V')
			value += 5;
		else if (s[i] == 'I') {
			if (s[i + 1] == 'V') {
				value += 4;
				++i;
			} else if (s[i + 1] == 'X') {
				value += 9;
				++i;
			} else
				value += 1;
		}
	}
	return value;
}

int main()
{
	printf("%d\n", romanToInt("MCMXCIV"));
	return 0;
}