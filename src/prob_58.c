// Length of Last Word
#include <stdio.h>

int lengthOfLastWord(char *s)
{
	if (!s)
		return 0;
	for (char *prev = s; *prev != '\0'; ++prev) {

		// skip space
		while (*prev == ' ') {
			++prev;
		}
		// no word
		if (*prev == '\0')
			return 0;
		// find a word
		char *cur = prev + 1;
		while (*cur != ' ' && *cur != '\0') {
			++cur;
		}
		// check last word
		char *end = cur;
		while (*end == ' ') {
			++end;
		}
		if (*end == '\0')
			return cur - prev;
	}
	return 0;
}

int main()
{
	char s[] = "  a world  ";
	printf("%d\n", lengthOfLastWord(s));
	return 0;
}
