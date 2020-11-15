/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:50:58 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/06 19:35:22 by alexandre        ###   ########.fr       */
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
	if (!list || ft_is_list_empty(list))
	{
        printf("\nEmpty list!\n");
        return;
    }   
	while (list != NULL)
	{
		printf("data -> [%i] | next -> [%p]\n", *((int *)list->data), (void *)(list->next));
		list = list->next;
	}
}

void ft_list_free(void *data)
{
    free(data);
}

void ft_triple(void *data)
{
    *((int *)data) = (3 * *((int *)data));
}

int	main(int ac, char **av)
{
	t_list *list = NULL;
    t_list *tmp;
    int i;
    //t_list *last_elem;
    int *nb;
    int *nb2;
    int *nb3;
    int *nb4;
    
    //list = 0;
    ft_print_list(list);
    nb = (int *)malloc(sizeof(int));
    nb2 = (int *)malloc(sizeof(int));
    nb3 = (int *)malloc(sizeof(int));
    nb4 = (int *)malloc(sizeof(int));
    *nb = 10;
    *nb2 = 12;
    *nb3 = 5;
    *nb4 = 999;
    list = ft_create_elem((void *)nb);
    ft_list_push_front(&list, (void *)nb2);
    ft_list_push_front(&list, (void *)nb3);
    ft_list_push_back(&list, (void *)nb4);
    printf("size: %i elements\n", ft_list_size(list));
    ft_print_list(list);
    printf("*-----------------------*\n");
    i = 0;
    //tmp = ft_list_at(list, i);
    //printf("\nelem[%i]: [%i] - [%p]\n", i, *((int *)tmp->data), tmp->next);
    ft_list_reverse(&list);
    ft_print_list(list);
    printf("*-----------------------*\n");
    ft_list_foreach(list, &ft_triple);
    ft_print_list(list);
}
