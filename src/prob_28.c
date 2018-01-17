// Implement strStr()
#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{
	if (strlen(needle) == 0)
		return 0;
	for (int i = 0; haystack[i + strlen(needle) - 1] != '\0'; ++i) {
		int j;
		for (j = 0; needle[j] != '\0'; ++j) {
			if (haystack[i + j] != needle[j])
				break;
		}
		if (j == strlen(needle))
			return i;
	}
	return -1;
}

int main()
{
	char haystack[] = "ababc";
	char needle[] = "ab3";
	printf("%d\n", strStr(haystack, needle));
	return 0;
}
