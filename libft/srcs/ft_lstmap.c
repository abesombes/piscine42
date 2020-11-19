/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:09:55 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/19 21:56:41 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_elem;
	t_list *tmp;

	(void)del;
	if (!lst || !f)
		return (NULL);
	if (!(new_list = ft_lstnew(f(lst->content))))
		return (NULL);
	tmp = new_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_elem = ft_lstnew(f(lst->content))))
			return (NULL);
		tmp->next = new_elem;
		tmp = tmp->next;
	}
	return (new_list);
}
