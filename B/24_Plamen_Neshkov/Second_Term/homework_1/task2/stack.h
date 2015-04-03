#ifndef STACK_H
#define STACK_H
	typedef int stackElement_t;
	typedef struct {
		stackElement_t *contents;
		int top;
		int maxSize;
	} stack_t;

	void stackInit(stack_t *stackP, int maxSize);
	void stackDestroy(stack_t *stackP);
	int stackIsEmpty(stack_t *stackP);
	int stackIsFull(stack_t *stackP);
	void stackPush(stack_t *stackP, stackElement_t element);
	stackElement_t stackPop(stack_t *stackP);
#endif
