# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandre <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 22:53:04 by alexandre         #+#    #+#              #
#    Updated: 2020/11/13 22:53:24 by alexandre        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_hexdump.c 

OBJS		= ${SRCS:.c=.o}

NAME		= ft_hexdump

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
