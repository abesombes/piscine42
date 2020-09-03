/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/24 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_ft(int *nbr)
{
	*nbr = 42;
	printf("nbr: %i",*nbr);
}

int 	main(void)
{	
	int a;
	int *ptr;
	
	ptr=&a;	
	ft_ft(ptr);
}
