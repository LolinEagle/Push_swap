/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:02:19 by frrusso           #+#    #+#             */
/*   Updated: 2022/02/28 16:20:06 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort_first(t_stack **a, t_stack **b, int *i)
{
	int	x;
	int	y;

	y = ft_intsize(a[0]);
	x = -1;
	while (!ft_nopushleft(a[0], i[2]) && ++x < y)
	{
		if ((a[0]->order >> i[2]) % 2 == 0)
			push(a, b);
		else
			rotate(a);
	}
	i[0] = x;
	i[1] = y;
}

void	ft_radix_sort_b(t_stack **a, t_stack **b, int *i)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = ft_intsize(b[0]);
	x = -1;
	while (!ft_nopushleft(b[0], i[2]) && ++x < y)
	{
		if ((b[0]->order >> i[2]) % 2 == 1)
			ft_push(b, a, i, &z);
		else
			ft_rotate(b, a, i);
	}
	i[0] = x;
	i[1] = y;
}

void	ft_radix_sort_a(t_stack **a, t_stack **b, int *i)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = ft_intsize(a[0]);
	x = -1;
	while (!ft_nopushleft(a[0], i[2]) && ++x < y)
	{
		if ((a[0]->order >> i[2]) % 2 == 0)
			ft_push(a, b, i, &z);
		else
			ft_rotate(a, b, i);
	}
	i[0] = x;
	i[1] = y;
}

void	ft_radix(t_stack **a, t_stack **b)
{
	int	i[3];

	i[2] = 0;
	if (!ft_issort(a[0]))
		ft_radix_sort_first(a, b, i);
	while (!ft_istruesort(a[0], b[0]))
	{
		i[2]++;
		ft_radix_sort_b(a, b, i);
		ft_radix_sort_a(a, b, i);
	}
	while (b[0] != NULL)
		push(b, a);
}
