/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/25 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int int_a;
	int int_b;
	int *int1;
	int *int2;

	int_a = 5;
	int_b = 10;
	int1 = &int_a;
	int2 = &int_b;
	ft_swap(int1, int2);
	printf("\nint1: %i et int2: %i\n", *int1, *int2);
}
