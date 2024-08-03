#include "stack.h"

void stack_deallocate(StackPtr top, stack_deallocate_callback cb)
{
	StackPtr p, temp;
	
	for (p = top;p != NULL;)
	{
		/*	handle data deallocation via callback func	*/
		cb(p->data);
		free(data);
		
		temp = p;
		p = p->next;
		free(temp);
	}
	
	return;
}
