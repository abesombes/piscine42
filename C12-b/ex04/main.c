/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:50:58 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 19:41:39 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ft_new_list(void)
{
	return (0);
}

int ft_is_list_empty(t_list *list)
{
	if (list == NULL)
		return (1);
	return (0);
}

int ft_listlen(t_list *list)
{
	int size;

	if (!ft_is_list_empty(list))
		while (list)
		{
			size++;
			list = list->next;
		}
	return (size);
}

void	ft_print_list(t_list *list)
{
	if (!list)
		printf("\nEmpty list!\n");
	while (list)
	{
		printf("data -> [%i] | next -> [%p]\n", *((int *)(list->data)), (void *)(list->next));
		list = list->next;
	}
}

int	main(void)
{
	t_list *list;
    t_list *last_elem;
    //int nb;
    //int nb2;
    //int nb3;
    int nb4;
    
    //nb = 10;
    //nb2 = 12;
    //nb3 = 5;
	nb4 = 999;
    list = 0;
    //list = ft_create_elem((void *)&nb);
    //ft_list_push_front(&list, (void *)&nb2);
    //ft_list_push_front(&list, (void *)&nb3);
    ft_list_push_back(&list, (void *)&nb4);
    printf("size: %i elements\n", ft_list_size(list));
    last_elem = ft_list_last(list);
    printf("last elem: data -> [%i] | next => [%p]\n", *((int *)last_elem->data), (void *)(last_elem->next)); 
    ft_print_list(list);
}
