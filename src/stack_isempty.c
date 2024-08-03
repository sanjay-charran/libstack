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
