/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:38:58 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/20 22:20:03 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void *tmp;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
