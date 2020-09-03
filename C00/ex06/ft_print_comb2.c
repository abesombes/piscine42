/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
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

void 	ft_special_putchar(int c, int d)
{
	ft_putchar(c / 10 + 48);
	ft_putchar(c % 10 + 48);
	write(1," ",1);
	ft_putchar(d / 10 + 48);
	ft_putchar(d % 10 + 48); 
	if (c!=98||d!=99)
	write(1,", ",2);
}

void 	ft_print_comb2(void)
{
	int i;
	int j;
	i = 0;
	j = 1;
	while (i<=99)
	{
		while (j<=99)
		{
			if (j>i)
		        ft_special_putchar(i, j);
			j++;
		}	
	j=0;
	i++;
	}
}

int 	main(void)
{
	ft_print_comb2();
}
