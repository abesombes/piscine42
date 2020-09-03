/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:34:55 by abesombes         #+#    #+#             */
/*   Updated: 2020/05/21 11:35:22 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_adv_putchar(char c, int k, bool end)
{
	ft_putchar(c);
	if (k == 0 && !end)
		write(1,", ",2);
}

bool 	ft_check_if_sorted(int* p, int* isize)
{
	int z;
	int counter;
	
	counter=0;
	z = *isize+1;
	while (--z>0)
	{
	if (*(p+z)<*(p+z-1))
		counter++;
	}
	if (counter==*isize)
	return(true);
	else
	return(false);
}	

void 	ft_print_combn_rec(int* p, int n, int* isize)
{
	int j;
	int k;
	bool end;

	end = false;
	j = -1;
	while (++j<=9)
	{
		if (n>0)
			ft_print_combn_rec(p, n - 1, isize);

		if (*(p+n)<9)
		{
		*(p+n)=*(p+n)+1;
		if (ft_check_if_sorted(p,isize))
			{
			k = *isize+1;
			if (*(p+k-1)==9-*isize)
				end = 1;
			while (--k>=0)
				ft_adv_putchar(*(p+k)+48,k,end);
			}
		}
		else
		*(p+n)=0;
	}
}

void 	ft_print_combn(int n)
{
	int range[10];
	int initial_size;
	int* q;
	int i;
	
	initial_size = n - 1;
	q = &initial_size;
	i = -1;
	while (++i<=9)
		range[i]=0;
	ft_print_combn_rec(range, n - 1, q);
}


int main(void)
{
	int z;
	z = 5;
	ft_print_combn(z);
}
