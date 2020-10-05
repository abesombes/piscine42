/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c	            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/25 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}


int ft_conv_to_int(char *str)
{
	int i;
	int res;
	int sign;

	res = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i])
	{
		res = str[i] - 48 + 10 * res;
//		printf("\ni = %i | str[i] = %c | res = %i", i, str[i], res);
		i++;
	}
	return (res*sign);
}

void ft_putnbr(int res)
{
	char tmp;

	if (res < 0)
	{
		ft_putchar('-');
		res = -res;
	}

	if (res > 9)
	{
		ft_putnbr(res / 10);
		tmp = res % 10 + '0';
		write(1, &tmp, 1);
	}
	else if (res < 10)
	{
		tmp = res + '0';
		write(1, &tmp, 1);
	}
}

int main(int ac, char **av)
{
	int int1;
	int int2;
	int res;

	res = 0;
	if (ac == 4)
	{
		int1 = ft_conv_to_int(av[1]);
		int2 = ft_conv_to_int(av[3]);
		if (av[2][0] == '+')
			res = int1 + int2;
		if (av[2][0] == '-')
			res = int1 - int2;
		if (av[2][0] == '*')
			res = int1 * int2;
		if ((av[2][0] == '/') && (int2 != 0))
			res = int1 / int2;
		if ((av[2][0] == '%') && (int2 != 0))
			res = int1 % int2;
		ft_putnbr(res);
	}
	write(1, "\n", 1);
}
