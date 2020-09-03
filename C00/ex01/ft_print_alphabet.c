 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:34:55 by abesombes         #+#    #+#             */
/*   Updated: 2020/05/21 11:35:22 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1,&c, 1);
}

void 	ft_print_alphabet(void)
{
	char i;
	i = 'a';
	while (i <= 'z')
	{
	ft_putchar(i);
	i++;
	}
}

int 	main(void)
{
	ft_print_alphabet();
	return(0);
}
