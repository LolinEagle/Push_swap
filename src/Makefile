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
	${CC} -o ${NAME} ${CFLAGS} ${SRCS} ${LIBFT}

all:${NAME}

clean:
	${MAKE} clean -C ../libft

fclean:clean
	${MAKE} fclean -C ../libft
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re
