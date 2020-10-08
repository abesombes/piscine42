/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c	                        :+:      :+:    :+:   */
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

void ft_print_list (t_list *list)
{
	while (list->next != NULL)
	{
		printf("\nlist->data: %i | list->next: %p", *(int *)(list->data), list->next);
		list = list->next;
	}
		printf("\nlist->data: %i | list->next: %p", *(int *)(list->data), list->next);
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
	while (begin_list->next != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i+1);
}

t_list *ft_list_last(t_list *begin_list)
{
	t_list *new_cell;

	while (begin_list->next != NULL)
	{
		new_cell = begin_list;
		begin_list = begin_list->next;
	}
	new_cell = begin_list;

	return(new_cell);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
        t_list *new_cell;
	t_list *list_last;

	list_last = ft_list_last(*begin_list);
        printf("\nlast cell data: %i", *(int*)(list_last->data));
	new_cell = ft_create_elem(data);
	list_last->next = new_cell;
        new_cell->next = NULL;
}


int     main(void)
{
        t_list *beginlist;
        t_list *last_cell;
	int a;
        int b;
	int c;

        a = 15;
        b = 20;
	c = 40;
        beginlist = ft_create_elem((int *)&a);
        printf("\nAdded to beginlist in position [0]: %i, %p", *(int *)(beginlist->data), beginlist->next);
        ft_list_push_front(&beginlist, (int *)&b);
	printf("\nAdded to beginlist in position [0]: %i, %p\n", *(int *)(beginlist->data), beginlist->next);
	printf("\n-------------------------------------------\n");
	printf("\nlist_size: %i", ft_list_size(beginlist));
	printf("\n-------------------------------------------\n");
	ft_print_list(beginlist);
   	ft_list_push_back(&beginlist,(int *)&c);
	last_cell = ft_list_last(beginlist);
	printf("\nAdded to beginlist in last position: %i, %p\n", *(int *)(last_cell->data), last_cell->next);
	printf("\n-------------------------------------------\n");
	printf("\nlist_size: %i", ft_list_size(beginlist));
	printf("\n-------------------------------------------\n");
	ft_print_list(beginlist);
}

