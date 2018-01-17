/* Compare Version Numbers
 * 0.1 < 1.1 < 2.1 < 2.1.1
 */
#include <stdio.h>
#include <string.h>

int getNum(char *version, int from, int *to)
{
	int n = 0;
	int i;
	for (i = from; version[i] != '.' && i < strlen(version); ++i) {
		n = n * 10 + version[i] - '0';
	}
	// next minor version
	if (version[i] == '.')
		*to = i + 1;
	else
		*to = strlen(version);
	return n;
}

int compareVersion(char *version1, char *version2)
{
	int i = 0, i_to;
	int j = 0, j_to;
	while (version1[i] != '\0' || version2[j] != '\0') {
		int num1 = getNum(version1, i, &i_to);
		int num2 = getNum(version2, j, &j_to);
		if (num1 < num2)
			return -1;
		if (num1 > num2)
			return 1;
		i = i_to;
		j = j_to;
	}
	return 0;
}

int main()
{
	char s1[] = "02.0";
	char s2[] = "2.0.1";
	printf("%d\n", compareVersion(s1, s2));
	return 0;
}
