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
SRCS	=	ft_isint.c stack.c rotate.c push_swap.c algo.c radix.c main.c
OBJS	=	${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${MAKE} -C ../libft
	${CC} -o ${NAME} ${CFLAGS} ${OBJS} ${LIBFT}

all:${NAME}

clean:
	${MAKE} clean -C ../libft
	${RM} ${OBJS}

fclean:clean
	${MAKE} fclean -C ../libft
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re
