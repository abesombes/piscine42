# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesombes <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 12:36:03 by abesombes         #+#    #+#              #
#    Updated: 2020/11/15 11:42:08 by alexandre        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DYNAMICNAME = libft.so
CC = gcc
RM = rm -f
HEADER = srcs/libft.h
SRCS = ${wildcard srcs/*.c}
OBJS = ${SRCS:.c=.o}
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${HEADER}
	${LIBC} $(NAME) ${OBJS}

so: all
	${CC} -o $(DYNAMICNAME) -shared -fPIC ${OBJS}

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
