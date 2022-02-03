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

void	print_push_swap(t_stack *a, t_stack *b)
{
	t_stack	*c;

	printf("\n[a_size=%i]", ft_intsize(a));
	c = a;
	while (c)
	{
		printf("{%i}", c->content);
		c = c->next;
	}
	printf("\n");
}

// sa	swap a - swap the first 2 elements at the top of stack a.
// sb	swap b - swap the first 2 elements at the top of stack b.
void	swap(t_stack *a)
{
	t_stack	*b;
	
	if (!a || a->next == NULL)
		return ;//(a);
	b = a;
	a = a->next;
	b->next = a->next;
	a->next = b;
	write(1, "s", 1);
	write(1, &a->stack, 1);
	write(1, "\n", 1);
	//return (a);
}

// ss	sa and sb at the same time.
// void	swap_swap(t_stack *a, t_stack *b)
// {
// 	return ;
// }

// pb	push b - take the first element of a put it at the top of b.
// pa	push a - take the first element of b put it at the top of a.
void	push(t_stack *a, t_stack *b)
{
	t_stack	*c;

	if (!a)
		return ;
	c = a;
	a = a->next;
	if (c->stack == 'a')
		c->stack = 'b';
	else
		c->stack = 'a';
	c->next = b;
	b = c;
	write(1, "p", 1);
	write(1, &a->stack, 1);
	write(1, "\n", 1);
	// return (a);
}

void	push_swap(t_stack *a)
{
	t_stack	*b;

	print_push_swap(a, b);
	swap(a);
	print_push_swap(a, b);
	//push(a, b);
	//print_push_swap(a, b);
}
