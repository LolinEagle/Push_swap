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

#include "push_swap.h"

// #include <stdio.h>// printf

// void	print_push_swap(t_stack *a, t_stack *b)
// {
// 	t_stack	*c;

// 	if (a)
// 	{
// 		printf("[a_size=%i]", ft_intsize(a));
// 		c = a;
// 		while (c)
// 		{
// 			printf("{%i[%i]}", c->content, c->order);
// 			c = c->next;
// 		}
// 	}
// 	if (b)
// 	{
// 		printf("[b_size=%i]", ft_intsize(b));
// 		c = b;
// 		while (c)
// 		{
// 			printf("{%i[%i]}", c->content, c->order);
// 			c = c->next;
// 		}
// 	}
// 	printf("\n");
// }

// sa	swap a - swap the first 2 elements at the top of stack a.
// sb	swap b - swap the first 2 elements at the top of stack b.
void	swap(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (!a[0] || a[0]->next == NULL)
		return ;
	b = a[0];
	a[0] = a[0]->next;
	b->next = a[0]->next;
	a[0]->next = b;
	write(1, "s", 1);
	write(1, &a[0]->stack, 1);
	write(1, "\n", 1);
}

// ss	sa and sb at the same time.
void	swap_swap(t_stack **a, t_stack **b)
{
	t_stack	*c;

	if (!a[0] || a[0]->next == NULL || !b[0] || b[0]->next == NULL)
		return ;
	c = a[0];
	a[0] = a[0]->next;
	c->next = a[0]->next;
	a[0]->next = c;
	c = b[0];
	b[0] = b[0]->next;
	c->next = b[0]->next;
	b[0]->next = c;
	write(1, "ss\n", 3);
}

// pb	push b - take the first element of a put it at the top of b.
// pa	push a - take the first element of b put it at the top of a.
void	push(t_stack **a, t_stack **b)
{
	t_stack	*c;

	if (!a[0])
		return ;
	c = a[0];
	a[0] = a[0]->next;
	if (c->stack == 'a')
		c->stack = 'b';
	else
		c->stack = 'a';
	c->next = b[0];
	b[0] = c;
	write(1, "p", 1);
	write(1, &c->stack, 1);
	write(1, "\n", 1);
}

void	push_swap(t_stack *a, int argc)
{
	t_stack	*b;

	b = NULL;
	if (!ft_issort(a))
	{
		ft_order_a(a);
		if (argc <= 13)
			ft_put_low_on_top(&a, &b);
		else
			ft_radix(&a, &b);
	}
}
