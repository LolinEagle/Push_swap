/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:53:42 by frrusso           #+#    #+#             */
/*   Updated: 2022/02/03 13:53:46 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

t_stack	*ft_intnew(int content, char stack)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->content = content;
	res->stack = stack;
	res->next = NULL;
	return (res);
}

int	ft_intsize(t_stack *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_intlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_intdelone(t_stack *lst)
{
	if (lst)
		free(lst);
}

void	ft_intclear(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_intdelone(lst);
		lst = tmp;
	}
}
