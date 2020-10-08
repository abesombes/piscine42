/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c		                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/08 17:28:36 by abesombes        ###   ########.fr       */
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

void ft_list_print (t_list *list)
{
	printf("\n-----------------------------------------");
	while (list->next != NULL)
	{
		printf("\nlist->data: %i | list->next: %p", *(int *)(list->data), list->next);
		list = list->next;
	}
		printf("\nlist->data: %i | list->next: %p", *(int *)(list->data), list->next);

	printf("\n-----------------------------------------");
}
void ft_list_print_str (t_list *list)
{
	int count;

	count = 0;
	while (list->next != NULL)
	{
		printf("\nlist->str[%i]: $%s$", count, (char *)(list->data));
		list = list->next;
		count++;
	}
		printf("\nlist->str: %s | list->next: %p", (char *)(list->data), list->next);
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
	return (i + 1);
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
        printf("\nlast_cell->data: %i | last_cell->next: %p", *(int*)(list_last->data), list_last->next);
	new_cell = ft_create_elem(data);

	ft_list_print(*begin_list);
	list_last->next = new_cell;
        new_cell->next = NULL;
	ft_list_print(*begin_list);
}


t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *list_push;
	int i;

	list_push = ft_create_elem(strs[size]);
	i = 0;
	while (i <= size)
	{
		ft_list_push_front(&list_push, (void *)strs[i]);
		i++;
	}
	return (list_push);
}

void free_data(void* element)
{
	printf("element:: %d\n", *((int *) element));
	free(element);
}

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *element;
	t_list *last_element;

	element = begin_list;
	while (element->next)
	{
		(*free_fct)(element->data);
		last_element = element;
		element = element->next;
		free(last_element);
	}
	(*free_fct)(element->data);
	free(element);

}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int  i;

	i = 0;
	while (begin_list->next && i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	if (i == ft_list_size(begin_list))
	{
		begin_list = begin_list->next;
		return (begin_list);
	}
	else
		return (begin_list);
}

int     main(void)
{
	t_list *list;
	t_list *element;
	int i;
	int		*index;
	int		*malloced_index;

	index = malloc(sizeof(int));
	*index = 0;
//	printf("\nindex: %i", *index);
	list = ft_create_elem(index);
	ft_list_print(list);
	(*index)++;
	while (*index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = *index;
		printf("\nmalloced_index: %i", *index);
		ft_list_push_back(&list, malloced_index);
		//ft_list_print(list);
		(*index)++;
	}
//	ft_list_clear(list, &free_data);
	ft_list_print(list);
	i = 1;
	while (i < 10)
	{
		element = ft_list_at(list, i);
		printf("\nelement data at position %i: %i", i, *(int *)(element->data));
		i++;
	}
}

