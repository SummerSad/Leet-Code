/* Given a non-empty string s, you may delete at most one character.
 * Judge whether you can make it a palindrome.
 * The string will only contain lowercase characters a-z.
 */
#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int from, int to)
{
	char *i, *j;
	for (i = s + from, j = s + to; i < j; ++i, --j) {
		if (*i != *j)
			return 0;
	}
	return 1;
}

int validPalindrome(char *s)
{
	int i = 0;
	int j = strlen(s) - 1;

	while (i < j) {
		if (s[i] != s[j]) {
			return isPalindrome(s, i + 1, j) ||
			       isPalindrome(s, i, j - 1);
		} else {
			++i, --j;
		}
	}
	return 1;
}

int main()
{
	return 0;
}
