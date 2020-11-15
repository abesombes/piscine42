/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:50:58 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 12:47:34 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list* ft_new_list(void)
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
    int nb;

    nb = 10;
	list = ft_create_elem((void *)&nb);
    ft_print_list(list);
}
