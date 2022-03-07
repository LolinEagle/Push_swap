/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:53:42 by frrusso           #+#    #+#             */
/*   Updated: 2022/02/03 13:53:46 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_intnew(int content, char stack)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->content = content;
	res->order = 0;
	res->stack = stack;
	res->next = NULL;
	return (res);
}

t_stack	*ft_intlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
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

void	ft_intclear(t_stack **lst)
{
	t_stack	*tmp;

	while (lst[0])
	{
		tmp = lst[0]->next;
		free(lst[0]);
		lst[0] = tmp;
	}
	free(lst[0]);
}
