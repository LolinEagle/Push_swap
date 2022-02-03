/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:36:31 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/27 17:50:45 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>// write read
# include <stdlib.h>// malloc free exit

typedef struct i_stack
{
	int				content;
	char			stack;
	struct i_stack	*next;
}					t_stack;

// ft_int.c
t_stack	*ft_intnew(int content, char stack);
int		ft_intsize(t_stack *lst);
void	ft_intadd_front(t_stack **lst);
void	ft_intadd_last(t_stack **lst);
void	ft_intclear(t_stack *lst);

// rotate.c
void	rotate(t_stack *a);
void	rotate_rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *a);
void	reverse_rotate_rotate(t_stack *a, t_stack *b);

// push_swap.c
void	push_swap(t_stack *a);

#endif
