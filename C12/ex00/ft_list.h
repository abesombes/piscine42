/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/06 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LIST_H__
#define __FT_LIST_H__

typedef struct s_list
{
	void *data;
	struct s_list *next;
}	t_list;

t_list	*ft_create_elem(void *data);

#endif
