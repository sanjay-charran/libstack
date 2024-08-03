#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>

/*	stack_pop error codes	*/
#define STACK_POP_SUCCESS 			0
#define STACK_POP_SUCCESS_NULL_DATA 1
#define STACK_POP_ERROR_EMPTY_STACK 2

/*	stack_isempty returns	*/
#define STACK_IS_EMPTY		1
#define STACK_IS_NOT_EMPTY	0

/*	callback func for entire stack deallocation for handling nested dynamically
	allocated structure data */
typedef void (*stack_deallocate_callback)(void *);

typedef struct stack
{
	void			*data;
	struct stack	*next;
}Stack, *StackPtr;


StackPtr	stack_push(StackPtr, void *);
StackPtr	stack_pop(StackPtr, void *, unsigned char *);
bool		stack_isempty(StackPtr);
void		stack_deallocate(StackPtr, stack_deallocate_callback);

#endif	/*	__STACK_H__	*/
