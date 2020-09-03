/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/28 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr_dec_to_hexa(char c)
{
	int i;
	int a;
	int b;
	char hexbase[16]="0123456789abcdef";
	
	a = (c / 16);
	b = (c % 16);
	ft_putchar('\\');
	ft_putchar(hexbase[a]);	
	ft_putchar(hexbase[b]);
}

void 	ft_putstr_non_printable(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[j]!='\0')
		j++;
	while (str[i]!='\0')
	{
		if ((str[i]>=32)&&(str[i]!=127))
			ft_putchar(str[i]);
		else
			ft_putstr_dec_to_hexa(str[i]);
		i++;
	}
}

int	main(void)
{
	char *str;

	str="test\nforce4";
	ft_putstr_non_printable(str);
}

