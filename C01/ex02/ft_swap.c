/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/24 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_swap(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
	printf("a: %i et b: %i",*a, *b);
}

int 	main(void)
{	
	int a;
	int b;
	int *ptr1;
	int *ptr2;

	a = 50;
	b = 100;
	ptr1=&a;
	ptr2= &b;
	ft_swap(ptr1, ptr2);
}
