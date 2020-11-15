/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:48:33 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 15:23:09 by alexandre        ###   ########.fr       */
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
void    btree_apply_infix(t_btree *root, void (*applyf)(void *));
void    btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int     btree_depth(t_btree *root, int depth);
int     btree_level_count(t_btree *root);

#endif
