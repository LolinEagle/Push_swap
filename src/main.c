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

#include "push_swap.h"

int	ft_isdup(t_stack *first)
{
	t_stack	*list;

	while (first->next != NULL)
	{
		list = first->next;
		while (list)
		{
			if (first->content == list->content)
				return (1);
			list = list->next;
		}
		first = first->next;
	}
	return (0);
}

t_stack	*ft_main(t_stack *list, char *argv)
{
	t_stack	*list_tmp;

	list_tmp = ft_intnew(ft_atoi(argv), 'a');
	list->next = list_tmp;
	return (list_tmp);
}

int	ft_parsing(int argc, char ***argv)
{
	int		i;
	char	*argv0;

	argv0 = argv[0][0];
	i = 0;
	while (argv[0][1][i])
	{
		if (argv[0][1][i] == ' ')
		{
			argv[0] = ft_split(argv[0][1], ' ');
			argv[0][0] = argv0;
			i = 1;
			while (argv[0][i])
				i++;
			return (i);
		}
		i++;
	}
	return (argc);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*list;

	if (argc == 2)
		argc = ft_parsing(argc, &argv);
	if (argc > 1)
	{
		if (!ft_isint(argc, argv))
			ft_putendl_fd("Error", 2);
		else
		{
			first = ft_intnew(ft_atoi(argv[1]), 'a');
			i = 2;
			if (i < argc)
				list = ft_main(first, argv[i]);
			while (++i < argc)
				list = ft_main(list, argv[i]);
			if (!ft_isdup(first))
				push_swap(first, argc);
			else
				ft_putendl_fd("Error", 2);
			ft_intclear(&first);
		}
	}
}
