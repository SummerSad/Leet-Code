// Valid Palindrome
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// consider c1 and c2 are alphanumeric characters
// and ignoring cases
int isSameChar(char c1, char c2)
{
	return toupper(c1) == toupper(c2);
}

int isAlphaChar(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	       (c >= '0' && c <= '9');
}

int isPalindrome(char *s)
{
	for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		while (!isAlphaChar(s[i])) {
			++i;
		}
		while (!isAlphaChar(s[j])) {
			--j;
		}
		if (i < j && !isSameChar(s[i], s[j]))
			return 0;
	}
	return 1;
}

int main()
{
	char s[] = ".,";
	printf("%d\n", isPalindrome(s));
	return 0;
}
