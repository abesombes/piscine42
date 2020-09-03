/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/24 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_div_mod(int a, int b, int *div, int *mod)
{

	*div = a / b;
	*mod = a % b;
	printf("div: %i et mod: %i",*div, *mod);
}

int 	main(void)
{	
	int a;
	int b;
	int c;
	int d;
	int *ptr1;
	int *ptr2;

	a = 16;
	b = 3;
	c = 0;
	d = 0;
	ptr1 = &c;
	ptr2 = &d;
	ft_div_mod(a, b, ptr1, ptr2);
}
