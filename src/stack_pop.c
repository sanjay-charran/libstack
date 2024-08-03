#include "stack.h"

StackPtr stack_pop(StackPtr top, void *data, unsigned char *ret)
{
	StackPtr new_top;
	
	if (stack_isempty(top))
	{
		(*ret) = STACK_POP_ERROR_EMPTY_STACK;
		data = NULL;
		return top;
	}
	
	new_top = top->next;
	data = top->data;
	
	(*ret) = ((data == NULL)?
			 (STACK_POP_SUCCESS_NULL_DATA):
			 (STACK_POP_SUCCESS));
	
	free(top);
	
	return new_top;
}
