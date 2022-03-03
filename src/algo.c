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

void	ft_order_a(t_stack *a)
{
	unsigned int	i;
	t_stack			*tmp;
	t_stack			*low;

	i = 0;
	while (++i <= ft_intsize(a))
	{
		low = a;
		while (low->order != 0)
			low = low->next;
		tmp = low->next;
		while (tmp)
		{
			if (low->content > tmp->content && tmp->order == 0)
				low = tmp;
			tmp = tmp->next;
		}
		low->order = i;
	}
	tmp = a;
	while (tmp)
	{
		tmp->order--;
		tmp = tmp->next;
	}
}

void	ft_put_top_on_low(t_stack **a, t_stack *low)
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

void	ft_put_low_on_top(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*low;

	while (a[0]->next && !ft_issort(a[0]))
	{
		if (ft_issort(a[0]->next) && ft_intlast(a[0])->order < a[0]->order)
			rotate(a);
		if (a[0]->order > a[0]->next->order)
			swap(a);
		low = a[0];
		tmp = a[0]->next;
		while (tmp)
		{
			if (low->content > tmp->content)
				low = tmp;
			tmp = tmp->next;
		}
		ft_put_top_on_low(a, low);
		if (ft_issort(a[0]))
			break ;
		push(a, b);
	}
	while (b[0] != NULL)
		push(b, a);
}
