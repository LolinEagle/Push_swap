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
	unsigned int	order;
	char			stack;
	struct i_stack	*next;
}					t_stack;

// ft_int.c
t_stack	*ft_intnew(int content, char stack);
int		ft_intsize(t_stack *lst);
void	ft_intclear(t_stack *lst);

// algo.c
int		ft_issort(t_stack *a);
void	put_low_on_top(t_stack **a, t_stack **b);
void	order_a(t_stack *a);

// radix.c
void	ft_radix(t_stack **a, t_stack **b);

// rotate.c push_swap.c
void	rotate(t_stack **a);
void	rotate_rotate(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a);
void	reverse_rotate_rotate(t_stack **a, t_stack **b);
void	print_push_swap(t_stack *a, t_stack *b);
void	swap(t_stack **a);
void	swap_swap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	push_swap(t_stack *a);

#endif
