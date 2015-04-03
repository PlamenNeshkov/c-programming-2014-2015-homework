#include <stdlib.h>

typedef char stackElement_t;

typedef struct {
    stackElement_t *contents;
    int top;
    int maxSize;
} stack_t;

void stackInit(stack_t *stackP, int maxSize)
{
	stackElement_t *newContents;

	newContents = (stackElement_t *) malloc(sizeof(stackElement_t) * maxSize);

	if (newContents == NULL)
		exit(EXIT_FAILURE);

	stackP->contents = newContents;
	stackP->maxSize = maxSize;
	stackP->top = -1;
}

void stackDestroy(stack_t *stackP)
{
	free(stackP->contents);

	stackP->contents = NULL;
	stackP->maxSize = 0;
	stackP->top = -1;
}

int stackIsEmpty(stack_t *stackP)
{
	return stackP->top < 0;
}

int stackIsFull(stack_t *stackP)
{
	return stackP->top >= stackP->maxSize - 1;
}

void stackPush(stack_t *stackP, stackElement_t element)
{
	if (stackIsFull(stackP))
		exit(EXIT_FAILURE);

	stackP->contents[++stackP->top] = element;
}

stackElement_t stackPop(stack_t *stackP)
{
	if (stackIsEmpty(stackP))
		exit(EXIT_FAILURE);

	return stackP->contents[stackP->top--];
}
