/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:15:57 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/19 15:33:05 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!(*alst))
	{
		(*alst) = new;
		return ;
	}
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
}
