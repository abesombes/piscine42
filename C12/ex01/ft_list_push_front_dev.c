/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
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

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *cell_to_add;

	cell_to_add = ft_create_elem(data);
	cell_to_add->next = *begin_list;
	*begin_list = cell_to_add;
}

void ft_print_list(t_list *list)
{
	while (!list->next)
	{
		printf("\nlist->data = %i| list-> next = %p", *(int *)(list->data), list->next);
		list = list->next;
	}
}

int main(void)
{
	t_list *beginlist;
//	t_list *list_dup;
	int a;
	int b;

	a = 15;
	b = 20;
	beginlist = ft_create_elem((int *)&a);
//	list_dup = beginlist;
	printf("\nbeginlist: %i, %p", *(int *)(beginlist->data), beginlist->next);
	ft_list_push_front(&beginlist, (int *)&b);
	printf("\nbeginlist: [0] %i, %p", *(int *)(beginlist->data), beginlist->next);
	beginlist = beginlist->next;
	printf("\nbeginlist: [1] %i, %p\n", *(int *)(beginlist->data), beginlist->next);
//	ft_print_list(list_dup);
}
