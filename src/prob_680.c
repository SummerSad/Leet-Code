/* Given a non-empty string s, you may delete at most one character.
 * Judge whether you can make it a palindrome.
 * The string will only contain lowercase characters a-z.
 */
#include <stdio.h>
#include <string.h>

int validPalindromeNoDup(char *s, char from, char to)
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
		printf("%c %c\t", s[i], s[j]);
		if (s[i] != s[j]) {
			int a = validPalindromeNoDup(s, i + 1, j);
			int b = validPalindromeNoDup(s, i, j - 1);
			if (a == 1 || b == 1)
				return 1;
			return 0;
		} else {
			++i, --j;
		}
	}
	return 1;
}

int main()
{
	char t[] = "vkjtmxzlpurgthxqxvokfcvdjgpvryculxhmyqbwyiogzcrwghbbssessgp"
		   "bwdyfjjtobigtnmmrvkfixfjoknpsixljlhhruwllvsvekeiwqqkezjwffx"
		   "qspfzikxftycyorrjyhnojdabogmdttzgxpyliwcadpfaqprfvwhsrkngqo"
		   "xisvjjeivmypzzevoyznekbiowuoiuadgwtkcujkvsgeiwhwrnzdywuuvco"
		   "luuywljnacgoyezzeyogcanjlwyuulocvuuwydznrwhwiegsvkjucktwgda"
		   "uiouwoibkenzyovezzpymviejjvsixoqgnkrshwvfrpqafpdacwilypxgzt"
		   "tdmgobadjonhyjrroycytfxkizfpsqxffwjzekqqwiekevsvllwurhhljyl"
		   "xispnojfxifkvrmmntgibotjjfydwbpgssessbbhgwrczgoiywbqymhxluc"
		   "yrvpgjdvcfkovxqxhtgruplzxmtjkv";
	char s[] = "knpsixljlhhruwllvsvekeiwqqkezjwffx"
		   "qspfzikxftycyorrjyhnojdabogmdttzgxpyliwcadpfaqprfvwhsrkngqo"
		   "xisvjjeivmypzzevoyznekbiowuoiuadgwtkcujkvsgeiwhwrnzdywuuvco"
		   "luuywljnacgoyezzeyogcanjlwyuulocvuuwydznrwhwiegsvkjucktwgda"
		   "uiouwoibkenzyovezzpymviejjvsixoqgnkrshwvfrpqafpdacwilypxgzt"
		   "tdmgobadjonhyjrroycytfxkizfpsqxffwjzekqqwiekevsvllwurhhljyl"
		   "xispn";
	printf("%d\n", validPalindrome(t));
	return 0;
}
