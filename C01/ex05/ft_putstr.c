/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c         	                        :+:      :+:    :+:   */
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

void 	ft_putstr(char *str)
{
	while (*str)
	{
	ft_putchar(*str);
	str++;
	}
}

int 	main(void)
{	
	char str[5] = "hello";

	ft_putstr(str);
}
