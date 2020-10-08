# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile 	                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesombes <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 12:36:03 by abesombes         #+#    #+#              #
#    Updated: 2020/10/06 12:36:10 by abesombes        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = rm -f
SRCS = ${wildcard srcs/*.c}
OBJS = ${SRCS:.c=.o}
HDR = includes
LIBC = ar rc
LIBR = ranlib
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HDR}

$(NAME): ${OBJS}
	${LIBC} $(NAME) ${OBJS}
	${LIBR} ${NAME}

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
