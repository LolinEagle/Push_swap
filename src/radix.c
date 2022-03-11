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

void	ft_radix_sort_a(t_stack **a, t_stack **b, int k)
{
	int	i;
	int	j;

	j = ft_intsize(a[0]);
	i = -1;
	while (++i < j)
	{
		if ((a[0]->order >> k) % 2 == 0)
			push(a, b);
		else
			rotate(a);
	}
}

void	ft_radix_sort_b(t_stack **a, t_stack **b, int k)
{
	int	i;
	int	j;

	j = ft_intsize(b[0]);
	i = -1;
	while (++i < j)
	{
		if ((b[0]->order >> k) % 2 == 1)
			push(b, a);
		else
			rotate(b);
	}
}

void	ft_radix(t_stack **a, t_stack **b)
{
	int	k;

	k = 0;
	if (!ft_issort(a[0]))
		ft_radix_sort_a(a, b, k);
	while (!ft_istruesort(a[0], b[0]))
	{
		k++;
		ft_radix_sort_b(a, b, k);
		ft_radix_sort_a(a, b, k);
	}
	while (b[0] != NULL)
		push(b, a);
}
