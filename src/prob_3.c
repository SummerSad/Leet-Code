/* Longest Substring
 * Without Repeating Characters
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDup(const char *from, const char *to)
{
	if (!from || from[0] == '\0' || from > to)
		return 0;
	int len = to - from + 1;
	for (int i = 1; i < len; ++i) {
		for (int j = 0; j < i; ++j) {
			if (from[j] == from[i])
				return 1;
		}
	}
	return 0;
}

int lengthOfLongestSubstring(const char *s)
{
	int len = strlen(s);
	int max = 0;
	for (int i = 0; i < len; ++i) {
		int j = i + 1;
		while (j < len) {
			if (isDup(s + i, s + j))
				break;
			else
				++j;
		}
		if (j - i > max)
			max = j - i;
	}
	return max;
}

int main()
{
	char s[] = "pwwkew";
	printf("%d\n", lengthOfLongestSubstring(s));
	return 0;
}
