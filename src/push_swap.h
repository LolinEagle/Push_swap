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

# include "../libft/libft.h"

typedef struct i_stack
{
	int				content;
	unsigned int	order;
	char			stack;
	struct i_stack	*next;
}					t_stack;

// ft_isint.c	3 functions
int		ft_isbig(char *s);
int		ft_isnewint(char *argv);
int		ft_isint(int argc, char **argv);

// stack.c		4 functions
t_stack	*ft_intnew(int content, char stack);
t_stack	*ft_intlast(t_stack *lst);
int		ft_intsize(t_stack *lst);
void	ft_intclear(t_stack **lst);

// algo.c		4 functions
int		ft_issort(t_stack *a);
void	ft_order_a(t_stack *a);
void	ft_put_low_on_top(t_stack **a, t_stack **b);

// radix.c		1 functions
void	ft_radix(t_stack **a, t_stack **b);

// rotate.c 	4 functions
void	rotate(t_stack **a);
void	rotate_rotate(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a);
void	reverse_rotate_rotate(t_stack **a, t_stack **b);

// push_swap.c	4 functions
void	swap(t_stack **a);
void	swap_swap(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	push_swap(t_stack *a, int argc);

// main.c		5 functions

#endif
