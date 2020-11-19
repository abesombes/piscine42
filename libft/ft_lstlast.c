/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:02:03 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/19 12:12:57 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *last_elem;

	if (!lst)
		return (NULL);
	while (lst)
	{
		last_elem = lst;
		lst = lst->next;
	}
	return (last_elem);
}
