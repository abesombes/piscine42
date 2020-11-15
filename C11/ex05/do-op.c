/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/09 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char*str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_add(int a, int b)
{
	return (a + b);
}

int ft_minus(int a, int b)
{
	return (a - b);
}

int ft_div(int a, int b)
{
	if (b != 0)
		return (a / b);
	else
	printf("\nStop: division by zero");
	return (0);
}

int ft_mult(int a, int b)
{
	return (a * b);
}

int ft_modulo(int a, int b)
{
	if (b != 0)
		return (a % b);
	else
	printf("\nStop: modulo by zero");
	return (0);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int ft_atoi(char *str)
{
	int sign;
	int i;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && (str[i] == ' ' ||  str[i] == '\v' || str[i] == '\f' \
		|| str[i] == '\t' || str[i] == '\r' || str[i] == '\n'))
			i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (sign * nb);
}

void ft_do_op(char **str)
{
	void *tab[5] = {&ft_add, &ft_minus, &ft_div, &ft_mult, &ft_modulo};
	int (*f)(int, int);
	int res;

	if (ft_strlen(str[2]) != 1)
		write(1, "0\n", 2);
	else 
	{
		if (str[2][0] == '+')
			f = tab[0];
		else if (str[2][0] == '-')
			f = tab[1];
		else if (str[2][0] == '/')
			f = tab[2];
		else if (str[2][0] == '*')
			f = tab[3];
		else if (str[2][0] == '%')
			f = tab[4];
		else
			write(1, "0\n", 2);
		res = 0;
		res = (*f)(ft_atoi(str[1]), ft_atoi(str[3]));
		if (res < 0)
			write(1, "-", 1);
		(res < 0)? ft_putnbr(-res): (ft_atoi(str[3] == 0 && (str[2][0] == '/' || str[2][0] == '/'))?ft_putchar("");ft_putnbr(res);
		write(1, "\n", 1);
	}
}

int 	main (int ac, char **av)
{
	if (ac == 4)
	{
//		printf("\n%i %s %i?", ft_atoi(av[1]), av[2], ft_atoi(av[3]));
		ft_do_op(av);
	}
}
