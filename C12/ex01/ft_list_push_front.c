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
