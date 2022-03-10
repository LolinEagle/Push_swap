/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:06:52 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/10 16:06:58 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nopushleft(t_stack *a, int k)
{
	while (a->next)
	{
		if ((a->order >> k) % 2 == 1)
			return (0);
		a = a->next;
	}
	if ((a->order >> k) % 2 == 1)
		return (0);
	return (1);
}

void	ft_push(t_stack **a, t_stack **b, int *i, int *z)
{
	if (i[0] < i[1])
	{
		rotate(a);
		z[0]++;
	}
	else
	{
		if (z[0])
		{
			while (z[0]--)
				reverse_rotate(a);
		}
		push(a, b);
	}
}

void	ft_rotate(t_stack **a, t_stack **b, int *i)
{
	if (++i[0] < i[1])
		rotate_rotate(a, b);
	else
		rotate(a);
}
