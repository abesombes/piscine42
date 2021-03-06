/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:39:19 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/22 14:39:19 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>
#include <stdlib.h>


t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list->next = 0;
	list->data = data;
	return (list);
}

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == 0)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	new_list->next = (*begin_list);
	*begin_list = new_list;
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	t_list	*list;
	t_list	*last;

	list = ft_create_elem(0);
	index = 0;
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = index;
		ft_list_push_front(&list, (void *)malloced_index);
		index++;
	}
	last = ft_list_last(list);
	printf("last malloced index: %d\n", *((int *)list->data));
}
