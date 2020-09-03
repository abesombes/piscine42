/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/25 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_ultimate_div_mod(int a, int b)
{
	int temp;
	
	temp = a;
	a = a / b;
	b = temp % b;
	printf("div: %i et mod: %i", a, b);
}

int 	main(void)
{	
	int a;
	int b;

	a = 23;
	b = 6;
	ft_ultimate_div_mod(a, b);
}
