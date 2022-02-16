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

	if (ft_issort(a[0]))
		return ;
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
