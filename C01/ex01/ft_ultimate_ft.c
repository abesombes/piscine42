/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/24 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_ft(int *********nbr)
{
	*********nbr = 42;
	printf("nbr: %i",*********nbr);
}

int 	main(void)
{	
	int a;
	int *ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;
	int *********ptr9;
	
	a = 42;
	ptr1=&a;
	ptr2=&ptr1;
	ptr3=&ptr2;
	ptr4=&ptr3;
	ptr5=&ptr4;
	ptr6=&ptr5;
	ptr7=&ptr6;
	ptr8=&ptr7;
	ptr9=&ptr8;	
	ft_ft(ptr9);
}
