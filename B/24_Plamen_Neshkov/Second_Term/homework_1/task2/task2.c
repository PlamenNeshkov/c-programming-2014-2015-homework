#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "stack.h"

int calculate(char *exp);

int main()
{
	char *exp;
	scanf("%s", exp);
	printf("%d", calculate(exp));
	return 0;
}

int calculate(char *exp)
{
	int n = strlen(exp);
	stack_t s;
	stackInit(&s, n);

    int j, result;

	int i, first, second;
	for (i = 0; i < n; i++)
	{
		if ((exp[i] >= '0') && (exp[i] <= '9'))
		{
            stackPush(&s, exp[i] - '0');
		}
		else
		{
			if (s.top < 1)
            {
				fprintf(stderr, "Invalid expression: values not sufficient\n");
				return INT_MIN;
            }
			second = stackPop(&s);
			first = stackPop(&s);
			switch (exp[i])
			{
				case '+':
				    result = first + second;
					stackPush(&s, result);
					break;
				case '-':
					stackPush(&s, first - second);
					break;
				case '*':
					stackPush(&s, first * second);
					break;
				case '/':
					stackPush(&s, first / second);
					break;
			}
		}
		for (j = 0; j <= i; j++)
        {
           printf("Element %d: %d\n", j, s.contents[j]);
        }
        printf("%d\n", s.top);
	}

	if (s.top == 0)
		return s.contents[s.top];
	fprintf(stderr, "Invalid expression: too many values");
	return INT_MIN;
}
