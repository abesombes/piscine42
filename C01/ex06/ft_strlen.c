/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/25 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1,&c,1);
}

void 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
	i++;
	str++;
	}
	printf("\nNombre de caracteres: %i\n", i);
}

int 	main(void)
{	
	char str[10] = "hello ami";

	ft_strlen(str);
}
