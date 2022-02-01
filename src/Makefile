# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 17:22:12 by frrusso           #+#    #+#              #
#    Updated: 2022/01/27 17:49:55 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
LIBFT	=	../libft/libft.a
SRCS	=	main.c push_swap.c	

${NAME}:
	${MAKE} -C ../libft
	${CC} -o ${NAME} ${SRCS} ${LIBFT}

all:${NAME}

clean:
	${MAKE} clean -C ../libft
	${RM} ${NAME}

fclean:clean
	${MAKE} fclean -C ../libft

re:fclean all

.PHONY: all clean fclean re
