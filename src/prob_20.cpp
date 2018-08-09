/*
 * 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * determine if the input string is valid.
 * An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 *  Note that an empty string is also considered valid.
 */

#include <stdio.h>
#include <vector>

using namespace std;

/*
 * Use stack my friend :)
 * If ( { [ push to the stack
 * If ) } ], check if ( { [ exist to pop
 * Otherwise false
 */
bool isValid(char *s)
{
	vector<char> stack_parentheses;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack_parentheses.push_back(s[i]);
		else if (s[i] == ')') {
			if (stack_parentheses.empty() ||
			    stack_parentheses.back() != '(')
				return false;
			stack_parentheses.pop_back();
		} else if (s[i] == ']') {
			if (stack_parentheses.empty() ||
			    stack_parentheses.back() != '[')
				return false;
			stack_parentheses.pop_back();
		} else if (s[i] == '}') {
			if (stack_parentheses.empty() ||
			    stack_parentheses.back() != '{')
				return false;
			stack_parentheses.pop_back();
		}
	}
	if (!stack_parentheses.empty())
		return false;
	return true;
}

int main()
{
	printf("%d\n", isValid("}"));
	return 0;
}