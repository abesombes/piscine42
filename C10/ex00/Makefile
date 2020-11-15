# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexandre <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 14:43:52 by alexandre         #+#    #+#              #
#    Updated: 2020/11/11 15:27:29 by alexandre        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CC = gcc
RM = rm -f
SRCS = ft_display_file.c
OBJS = ft_display_file.o
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

ft_display_file.o : ft_display_file.c
	 ${CC} ${CFLAGS} -o ${OBJS} -c ${SRCS}  

$(NAME): ${OBJS}
	 ${CC} ${CFLAGS} -o ${NAME} ${OBJS} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

.PHONY: all clean fclean re
