// Longest Common Prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrefix(const char *str, const char *pre)
{
	if (!str || !pre || strlen(str) < strlen(pre))
		return 0;
	int i;
	for (i = 0; pre[i] != '\0'; ++i) {
		if (str[i] != pre[i])
			break;
	}
	if (pre[i] == '\0')
		return 1;
	return 0;
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	if (!strs || !*strs) {
		char *pre = malloc(1);
		strcpy(pre, "");
		return pre;
	}
	char *pre = malloc(strlen(strs[0]) + 1);
	strcpy(pre, strs[0]);

	while (pre[0] != '\0') {
		int i;
		for (i = 0; i < strsSize; ++i) {
			if (!isPrefix(strs[i], pre)) {
				break;
			}
		}
		if (i == strsSize)
			break;
		pre[strlen(pre) - 1] = '\0';
	}

	return pre;
}

int main()
{
	char **strs = malloc(sizeof(char *) * 4);
	strs[0] = malloc(strlen("ab") + 1);
	strcpy(strs[0], "ab");
	strs[1] = malloc(strlen("abc") + 1);
	strcpy(strs[1], "abc");
	strs[2] = malloc(strlen("abcd") + 1);
	strcpy(strs[2], "abcd");
	strs[3] = malloc(strlen("abcde") + 1);
	strcpy(strs[3], "abcde");

	char *p = longestCommonPrefix(NULL, 4);
	if (p) {
		printf("%s\n", p);
		free(p);
	}

	for (int i = 0; i < 4; ++i) {
		free(strs[i]);
	}
	free(strs);
	return 0;
}
