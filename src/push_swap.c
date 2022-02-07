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

#include <stdio.h>// printf

void	print_push_swap(t_stack *a, t_stack *b)
{
	t_stack	*c;

	printf("[a_size=%i]", ft_intsize(a));
	c = a;
	while (c)
	{
		printf("{%i}", c->content);
		c = c->next;
	}
	printf("[b_size=%i]", ft_intsize(b));
	c = b;
	while (c)
	{
		printf("{%i}", c->content);
		c = c->next;
	}
	printf("\n");
}

// sa	swap a - swap the first 2 elements at the top of stack a.
// sb	swap b - swap the first 2 elements at the top of stack b.
void	swap(t_stack **a)
{
	t_stack	*b;

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
	write(1, &a[0]->stack, 1);
	write(1, "\n", 1);
}

void	push_swap(t_stack *a)
{
	t_stack	*b;

	b = ft_intnew(0, 'b');
	b->next = ft_intnew(1, 'b');
	print_push_swap(a, b);
	swap(&a);
	print_push_swap(a, b);
	swap(&b);
	print_push_swap(a, b);
	swap_swap(&a, &b);
	print_push_swap(a, b);
	push(&a, &b);
	print_push_swap(a, b);
	push(&b, &a);
	print_push_swap(a, b);
	// rotate(&a);
	// print_push_swap(a, b);
	// rotate(&b);
	// print_push_swap(a, b);
	// rotate_rotate(&a, &b);
	// print_push_swap(a, b);
	// reverse_rotate(&a);
	// print_push_swap(a, b);
	// reverse_rotate(&b);
	// print_push_swap(a, b);
	// reverse_rotate_rotate(&a, &b);
}
