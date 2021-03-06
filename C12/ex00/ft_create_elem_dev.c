/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/06 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list 	*ft_create_elem(void *data)
{
	t_list *list;

	if (!(list=(t_list *)malloc(sizeof(t_list))))
		return NULL;
	list->data = data;
	list->next = NULL;
	return (list);
}

int	main(void)
{
	int	data;
	void *ptr;
	t_list	*list;

	data = 10;
	ptr = &data;
	list = ft_create_elem(ptr);
	printf("list->data: %i\n", (*(int *)(list->data)));
	printf("list->next: %p\n", list->next);
}
