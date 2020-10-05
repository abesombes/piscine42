/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/04 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_abs(int a)
{
	if (a >= 0)
		return(a);
	else
		return(-a);
}

int has_bq_in_diags(char **av, int x, int y)
{
	int size;
	int i;
	int j;
	int in_btw;
	int fail;

	size = ft_strlen(av[1]);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (av[i + 1][j] == 'Q' || av[i+1][j] == 'B')
			{
				if (ft_abs(i - x) == ft_abs(j - y))
				{
					in_btw = 0;
					fail = 0;
					if ((i > x) && (j > y))
							while(++in_btw < ft_abs(i - x))
								if (av[x + in_btw + 1][y + in_btw] == 'R' || av[x + in_btw + 1][y + in_btw] == 'P')
									fail = 1;
					if ((i > x) && (j < y))
							while(++in_btw < ft_abs(i - x))
								if (av[x + in_btw + 1][y - in_btw] == 'R' || av[x + in_btw + 1][y - in_btw] == 'P')
									fail = 1;
					if ((i < x) && (j > y))
							while(++in_btw < ft_abs(i - x))
								if (av[x - in_btw + 1][y + in_btw] == 'R' || av[x - in_btw + 1][y + in_btw] == 'P')
									fail = 1;;
					if ((i < x) && (j < y))
							while(++in_btw < ft_abs(i - x))
								if (av[x - in_btw + 1][y - in_btw] == 'R' || av[x - in_btw + 1][y - in_btw] == 'P')
									fail = 1;
					if (fail == 0)
						return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int has_rq_in_rows_lines(char **av, int x, int y)
{
	int size;
	int i;
	int j;
	int in_btw;
	int fail;

	size = ft_strlen(av[1]);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (av[i + 1][j] == 'R' || av[i + 1][j] == 'Q')
			{
				if (i == x || j == y)
				{
					in_btw = -1;
					fail = 0;
					if (i > x)
						while (++in_btw < i - x)
							if(av[x + 1 + in_btw][y] == 'P' || av[x + 1 + in_btw][y] == 'B')
								fail = 1;
					if (i < x)
						while (++in_btw < x - i)
							if(av[x + 1 - in_btw][y] == 'P' || av[x + 1 - in_btw][y] == 'B')
								fail = 1;
					if (j > y)
						while (++in_btw < j - y)
							if(av[x + 1][y + in_btw] == 'P' || av[x + 1][y + in_btw] == 'B')
								fail = 1;
					if (j < y)
						while (++in_btw < y - j)
							if(av[x + 1][y - in_btw] == 'P' || av[x + 1][y - in_btw] == 'B')
								fail = 1;
					if (fail == 0)
						return (1);
				}
			}
			j++;
		}
		i++;
	}
return (0);
}

int has_pawn_in_checkpos(char **av, int x, int y)
{
	int size;

	size = ft_strlen(av[1]);
	if (x + 2 <= size && y + 1 <= size && av[x+2][y+1] == 'P')
		return (1);
	if (x + 2 <= size && y - 1 <= size && av[x+2][y-1] == 'P')
		return (1);
	if (x >= 0 && y + 1 <= size && av[x][y+1] == 'P')
		return (1);
	if (x >= 0 && y - 1 >= 0 && av[x][y-1] == 'P')
		return (1);
	return (0);
}

void check_mate(char **av)
{
	int size;
	int i;
	int j;
	int k_x;
	int k_y;

	size = ft_strlen(av[1]);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (av[i+1][j] == 'K')
			{
				k_x = i;
				k_y = j;
			}
			j++;
		}
		i++;
	}
	if ((has_bq_in_diags(av, k_x, k_y)) || (has_pawn_in_checkpos(av, k_x, k_y)) || (has_rq_in_rows_lines(av, k_x, k_y)))
		write(1, "Success", 7);
	else
		write(1, "Fail", 4);
}

int 	main(int ac, char **av)
{
	if (ac >= 2)
	{
		check_mate(av);
	}
	write(1, "\n", 1);
}
