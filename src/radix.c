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

#include "../libft/libft.h"
#include "push_swap.h"

void	ft_radix(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (!ft_issort(a[0]))
	{
		j = ft_intsize(a[0]);
		i = -1;
		while (++i < j)
		{
			if ((a[0]->order >> k) % 2 == 0)
				push(a, b);
			else
				rotate(a);
		}
		while (b[0] != NULL)
			push(b, a);
		k++;
	}
}
