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

int	ft_isbig(char *s)
{
	int		i;
	char	*max;

	i = 0;
	while (s[i] && i <= 11)
		i++;
	if (i < 10 || (i == 10 && s[0] == 43 || s[0] == 45))
		return (0);
	if (i > 11 || (i == 11 && ft_isdigit(s[0])))
		return (1);
	if (s[0] == '-')
		max = "2147483648";
	else
		max = "2147483647";
	if (s[0] == 43 || s[0] == 45)
		s++;
	while (s)
	{
		if (*s <= *max)
			return (1);
		s++;
		max++;
	}
	return (0);
}

int	ft_isint(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == 43 || argv[i][j] == 45)
				j++;
			else
				return (0);
		}
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (0);
		}
		if (ft_isbig(argv[i]))
			return (0);
	}
	return (1);
}

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

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*list;

	if (argc > 2)
	{
		if (!ft_isint(argc, argv))
			write(2, "Error\n", 6);
		else
		{
			first = ft_intnew(ft_atoi(argv[1]), 'a');
			i = 2;
			if (i < argc)
				list = ft_main(first, argv[i]);
			while (++i < argc)
				list = ft_main(list, argv[i]);
			if (!ft_isdup(first))
				push_swap(first);
			else
				write(2, "Error\n", 6);
		}
	}
	return (0);
}
