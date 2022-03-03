/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:35:49 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/01 14:35:53 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isbig(char *s)
{
	int		i;
	char	*max;

	i = 0;
	while (s[i] && i <= 11)
		i++;
	if (i < 10 || (i == 10 && (s[0] == 43 || s[0] == 45)))
		return (0);
	if (i > 11 || (i == 11 && ft_isdigit(s[0])))
		return (1);
	if (s[0] == '-')
		max = "2147483648";
	else
		max = "2147483647";
	if (s[0] == 43 || s[0] == 45)
		s++;
	i = 11;
	while (--i && *s >= *max)
	{
		if (*s > *max)
			return (1);
		s++;
		max++;
	}
	return (0);
}

int	ft_isnewint(char *argv)
{
	int	j;

	j = 0;
	if (argv[j])
	{
		if (ft_isdigit(argv[j]))
			j++;
		else if ((argv[j] == 43 || argv[j] == 45) && ft_isdigit(argv[j + 1]))
			j++;
		else
			return (0);
	}
	while (argv[j])
	{
		if (ft_isdigit(argv[j]))
			j++;
		else
			return (0);
	}
	return (1);
}

int	ft_isint(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isnewint(argv[i]))
			return (0);
		if (ft_isbig(argv[i]))
			return (0);
	}
	return (1);
}
