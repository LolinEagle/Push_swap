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

typedef struct d_list
{
	int				content;
	struct d_list	*next;
}					t_int;

t_int	*ft_intnew(int content);
void	push_swap(t_int *list);

#endif
