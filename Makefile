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
RM		=	rm
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
SRCS	=	main.c push_swap.c
OBJS	=	${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${CC} -o ${NAME} ${OBJS} 

all:${NAME}

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY: all clean fclean re
