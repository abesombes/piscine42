/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c	                                :+:      :+:    :+:   */
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

t_list *ft_list_last(t_list *begin_list)
{
	t_list *next_cell;

	while (begin_list->next)
	{
		next_cell = begin_list;
		begin_list = begin_list->next;
	}
	next_cell = begin_list;
	return(next_cell);
}

void ft_list_print(t_list *list)
{
	while(list->next)
	{
	printf("\ncell: %i %p", *(int *)list->data, list->next); 
	list = list->next;
	}
	printf("\ncell: %i %p\n", *(int *)list->data, list->next); 
}

int     main(void)
{
        t_list *beginlist;
	t_list *list_last;
        int a;
        int b;
	int c;

        a = 15;
        b = 20;
	c = 30;
        beginlist = ft_create_elem((int *)&a);
        printf("\nadded in position 0 of beginlist: %i, %p", *(int *)(beginlist->data), beginlist->next);
        ft_list_push_front(&beginlist, (int *)&b);
        printf("\nadded in position 0 of beginlist: %i, %p", *(int *)(beginlist->data), beginlist->next);
        ft_list_push_front(&beginlist, (int *)&c);
	printf("\nadded in position 0 of nbeginlist: %i, %p\n", *(int *)(beginlist->data), beginlist->next);
	printf("\n--------------------------------");
	list_last = ft_list_last(beginlist);
	printf("\nlast_cell: %i, %p", *(int *)(list_last->data), list_last->next);
	printf("\n--------------------------------");
	ft_list_print(beginlist);
//	beginlist = beginlist->next;

}

