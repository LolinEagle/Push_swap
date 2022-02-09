/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:51:28 by frrusso           #+#    #+#             */
/*   Updated: 2022/02/02 15:51:30 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

// ra	rotate a - shift up all elements of stack a by 1.
// rb	rotate b - shift up all elements of stack b by 1.
void	rotate(t_stack **a)
{
	t_stack	*b;
	t_stack	*c;

	if (!a[0] || a[0]->next == NULL)
		return ;
	b = a[0];
	a[0] = a[0]->next;
	b->next = NULL;
	c = a[0];
	while (c->next)
		c = c->next;
	c->next = b;
	write(1, "r", 1);
	write(1, &a[0]->stack, 1);
	write(1, "\n", 1);
}

// rr	ra and rb at the same time.
void	rotate_rotate(t_stack **a, t_stack **b)
{
	t_stack	*c;
	t_stack	*d;

	if (!a[0] || a[0]->next == NULL || !b[0] || b[0]->next == NULL)
		return ;
	c = a[0];
	a[0] = a[0]->next;
	c->next = NULL;
	d = a[0];
	while (d->next)
		d = d->next;
	d->next = c;
	c = b[0];
	b[0] = b[0]->next;
	c->next = NULL;
	d = b[0];
	while (d->next)
		d = d->next;
	d->next = c;
	write(1, "rr\n", 3);
}

// rra	reverse rotate a - shift down all elements of stack a by 1.
// rrb	reverse rotate b - shift down all elements of stack b by 1.
void	reverse_rotate(t_stack **a)
{
	t_stack	*b;
	t_stack	*c;

	if (!a[0] || a[0]->next == NULL)
		return ;
	b = a[0];
	while (b->next->next)
		b = b->next;
	c = b->next;
	b->next = NULL;
	c->next = a[0];
	a[0] = c;
	write(1, "rr", 2);
	write(1, &a[0]->stack, 1);
	write(1, "\n", 1);
}

// rrr	rra and rrb at the same time.
void	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	t_stack	*c;
	t_stack	*d;

	if (!a[0] || a[0]->next == NULL || !b[0] || b[0]->next == NULL)
		return ;
	c = a[0];
	while (c->next->next)
		c = c->next;
	d = c->next;
	c->next = NULL;
	d->next = a[0];
	a[0] = d;
	c = b[0];
	while (c->next->next)
		c = c->next;
	d = c->next;
	c->next = NULL;
	d->next = b[0];
	b[0] = d;
	write(1, "rrr\n", 4);
}
