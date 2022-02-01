/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:41:35 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/27 17:45:34 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

t_int	*ft_main(t_int *list, char *argv)
{
	t_int	*list_tmp;

	list_tmp = ft_intnew(ft_atoi(argv));
	list->next = list_tmp;
	return (list_tmp);
}

int	main(int argc, char **argv)
{
	int		i;
	t_int	*first;
	t_int	*list;

	if (argc > 2)
	{
		first = ft_intnew(ft_atoi(argv[1]));
		i = 2;
		if (i < argc)
		{
			list = ft_main(first, argv[i]);
			i++;
		}
		while (i < argc)
		{
			list = ft_main(list, argv[i]);
			i++;
		}
		push_swap(first);
	}
	return (0);
}
