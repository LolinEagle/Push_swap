/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:45:48 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/27 17:52:13 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

#include <stdio.h>

t_stack	*ft_intnew(int content)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

// sa	swap a - swap the first 2 elements at the top of stack a.
// sb	swap b - swap the first 2 elements at the top of stack b.
void	swap(t_stack *a)
{
	return ;
}

// ss	sa and sb at the same time.
void	swap_swap(t_stack *a, t_stack *b)
{
	return ;
}

// pa	push a - take the first element at the top of b put it at the top of a.
// pb	push b - take the first element at the top of a put it at the top of b.
void	push(t_stack *a, t_stack *b)
{
	return ;
}

void	push_swap(t_stack *a)
{
	t_stack	*b;

	while (a)
	{
		printf("%i\n", a->content);
		a = a->next;
	}
}
