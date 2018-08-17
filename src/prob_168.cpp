/* 168. Excel Sheet Column Title
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB
 * ...
 */
#include <stdio.h>
#include <stdlib.h>

char *convertToTitle(int n)
{
	char *column_title = (char *)malloc(sizeof(char) * 1);
	int ite = 0;
	while (n > 0) {
		int mod = n % 26;
		if (mod == 0) {
			n -= 26;
			mod = 26;
		}
		char c = mod + 'A' - 1;
		column_title =
		    (char *)realloc(column_title, sizeof(char) * (ite + 1));
		column_title[ite] = c;
		++ite;
		n /= 26;
	}
	column_title = (char *)realloc(column_title, sizeof(char) * (ite + 1));
	column_title[ite] = '\0';
	// reverse
	for (int i = 0, j = ite - 1; i < j; ++i, --j) {
		char temp = column_title[i];
		column_title[i] = column_title[j];
		column_title[j] = temp;
	}
	return column_title;
}

int main()
{
	char *column_title = convertToTitle(701);
	printf("%s\n", column_title);
	free(column_title);
	return 0;
}
