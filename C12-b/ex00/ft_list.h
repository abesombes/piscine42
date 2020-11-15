/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:46:01 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 13:29:08 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>
typedef struct s_list
{
	struct s_list *next;
	void *data;
}               t_list;

t_list  *ft_create_elem(void *data);
//void    ft_list_push_front(t_list **begin_list, void *data);
//int ft_list_size(t_list *begin_list);
//t_list  *ft_list_last(t_list *begin_list);
//void    ft_list_push_back(t_list **being_list, void *data);
//t_list *ft_list_push_strs(int size, char **strs);
//void ft_list_clear(t_list **begin_list, void (*freet_fct)(void *));
//t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
//void ft_list_reverse(t_list **begin_list);
//void ft_list_foreach(t_list **begin_list, void (*f(void *));

#endif
