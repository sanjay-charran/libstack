/*
 * Copyright (c) 2024 Sanjay Charran
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Sanjay Charran <sanjaycharran@gmail.com>
 * Date: 2024/08/03 (YYYY/MM/DD)
 */

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


StackPtr		stack_push(StackPtr, void *);
StackPtr		stack_pop(StackPtr, void **, unsigned char *);
unsigned char	stack_isempty(StackPtr);
void			stack_deallocate(StackPtr, stack_deallocate_callback);

#endif	/*	__STACK_H__	*/
