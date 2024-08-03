#include "stack.h"

StackPtr stack_push(StackPtr top, void *new_data)
{
	StackPtr new = malloc(sizeof(Stack));
	new->data = new_data;
	new->next = top;
	return new;
}
