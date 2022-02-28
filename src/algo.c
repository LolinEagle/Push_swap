/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:10:50 by frrusso           #+#    #+#             */
/*   Updated: 2022/02/16 16:10:55 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_issort(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	put_top_on_low(t_stack **a, t_stack *low)
{
	if (ft_intsize(a[0]) / 2 < ft_intsize(low))
	{
		while (a[0] != low)
			rotate(a);
	}
	else
	{
		while (a[0] != low)
			reverse_rotate(a);
	}
}

void	put_low_on_top(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*low;

	while (a[0]->next)
	{
		low = a[0];
		tmp = a[0]->next;
		while (tmp)
		{
			if (low->content > tmp->content)
				low = tmp;
			tmp = tmp->next;
		}
		put_top_on_low(a, low);
		push(a, b);
	}
	while (b[0] != NULL)
		push(b, a);
}

void	set_order(t_stack *a)
{
	t_stack			*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->order = 0;
		tmp = tmp->next;
	}
}

void	order_a(t_stack *a)
{
	unsigned int	i;
	t_stack			*tmp;
	t_stack			*low;

	set_order(a);
	i = 0;
	while (++i <= ft_intsize(a))
	{
		low = a;
		tmp = a->next;
		while (low->order != 0)
		{
			low = tmp;
			tmp = low->next;
		}
		while (tmp)
		{
			if (low->content > tmp->content && tmp->order == 0)
				low = tmp;
			tmp = tmp->next;
		}
		low->order = i;
	}
}
