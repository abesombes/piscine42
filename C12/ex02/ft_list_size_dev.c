/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/07 17:28:36 by abesombes        ###   ########.fr       */
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

void ft_list_push_front(t_list **begin_list, void *data)
{
        t_list *cell_to_add;

        cell_to_add = ft_create_elem(data);
        cell_to_add->next = *begin_list;
        *begin_list = cell_to_add;
}

int ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

int     main(void)
{
        t_list *beginlist;
	t_list *list_dup;
	t_list *list;
	t_list *emptylist;
        int a;
        int b;
	int index;

	index = 0;
        a = 15;
        b = 20;
        beginlist = ft_create_elem((int *)&a);
        printf("\nbeginlist: %i, %p", *(int *)(beginlist->data), beginlist->next);
        ft_list_push_front(&beginlist, (int *)&b);
	list_dup=beginlist;
        printf("\nbeginlist: [0] %i, %p", *(int *)(beginlist->data), beginlist->next);
	beginlist = beginlist->next;
	printf("\nbeginlist: [1] %i, %p\n", *(int *)(beginlist->data), beginlist->next);
	printf("\nlist size: %i", ft_list_size(list_dup));
	list = ft_create_elem(0);
	while (index++ < 10)
		ft_list_push_front(&list, 0);
	printf("size: %d\n", ft_list_size(list));
	emptylist = NULL;
	printf("size empty list: %d\n", ft_list_size(emptylist));
}

