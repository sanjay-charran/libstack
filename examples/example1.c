/*	test using type int for data	*/

#include <stdio.h>
#include "stack.h"

void *test_stack_alloc(void)
{
	void *new = malloc(sizeof(int));
	return new;
}

void test_stack_dealloc(void *data)
{
	 free(data);
	 return;
}

int main(void)
{
	StackPtr top = NULL;
	int *one, *two, *three, *four, *popped;
	unsigned char ret;
	
	if (stack_isempty(top))
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack is not empty\n");
	}
	
	one = test_stack_alloc();
	(*one) = 1;
	top = stack_push(top, one);	
	printf("Pushed \"%i\" onto stack\n", (*one));
	
	if (stack_isempty(top))
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack is not empty\n");
	}
	
	two = test_stack_alloc();
	(*two) = 2;
	top = stack_push(top, two);
	printf("Pushed \"%i\" onto stack\n", (*two));
	
	top = stack_pop(top, (void **)&popped, &ret);
	
	printf("Popped \"%i\" from stack\n", (*popped));
	test_stack_dealloc(popped);
	
	top = stack_pop(top, (void **)&popped, &ret);
	printf("Popped \"%i\" from stack\n", (*popped));
	test_stack_dealloc(popped);
	
	if (stack_isempty(top))
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack is not empty\n");
	}
	
	three = test_stack_alloc();
	(*three) = 3;
	top = stack_push(top, three);
	printf("Pushed \"%i\" onto stack\n", (*three));
	
	four = test_stack_alloc();
	(*four) = 4;
	top = stack_push(top, four);
	printf("Pushed \"%i\" onto stack\n", (*four));
	
	stack_deallocate(top, &test_stack_dealloc);
	printf("Deallocated Existing Stack\n");
	
	return 0;
}
