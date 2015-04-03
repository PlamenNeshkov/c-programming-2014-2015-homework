#include <stdio.h>
#include <string.h>
#include "stack.h"

int isPair(char opening, char closing);
int isBalanced(char *exp);

int main()
{
	char *exp;
	scanf("%s", exp);
	printf("%d", isBalanced(exp));
	return 0;
}

int isPair(char opening, char closing)
{
	if ((opening == '(') && (closing == ')'))
		return 1;
	if ((opening == '{') && (closing == '}'))
		return 1;
	if ((opening == '[') && (closing == ']'))
		return 1;
	return 0;
}

int isBalanced(char *exp)
{
	int n = 10;
	stack_t s;
	stackInit(&s, n);

	int i;
	for (i = 0; i < n; i++)
	{
		if ((exp[i] == '(') || (exp[i] == '{') || (exp[i] == '['))
		{
			stackPush(&s, exp[i]);
		}
		else if ((exp[i] == ')') || (exp[i] == '}') || (exp[i] == ']'))
		{
			if (stackIsEmpty(&s) || !isPair(s.contents[s.top], exp[i]))
			{
				return -1;
			}
			else
				stackPop(&s);
		}
	}

	return stackIsEmpty(&s) ? 0 : -1;
}

