# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandre <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 16:46:56 by alexandre         #+#    #+#              #
#    Updated: 2020/11/11 16:47:38 by alexandre        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_cat.c 

OBJS		= ${SRCS:.c=.o}

NAME		= ft_cat

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
				gcc ${CFLAGS} $^ -o $@

.c.o:
				gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
