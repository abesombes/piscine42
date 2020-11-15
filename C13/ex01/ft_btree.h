/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:48:33 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 11:49:50 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
#define FT_BTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_btree
{
    void *item;
    struct s_btree *left;
    struct s_btree *right;
}               t_btree;

t_btree *btree_create_node(void *item);
void    btree_apply_prefix(t_btree *root, void (*applyf)(void *));

#endif
