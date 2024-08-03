#include "stack.h"

bool stack_isempty(StackPtr top)
{
	if (top == NULL)
	{
		return STACK_IS_EMPTY;
	}
	else
	{
		return STACK_IS_NOT_EMPTY;
	}
}
