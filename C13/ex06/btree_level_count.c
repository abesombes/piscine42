/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:00:17 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 15:22:56 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int ft_max(int a, int b)
{
    return (a >= b ? a : b);
}

int btree_depth(t_btree *root, int depth)
{
    if (!root)
        return (depth);
    printf("MAX: %i - left = %p et right = %p\n", depth, root->left, root->right);
    return(ft_max(btree_depth(root->left, depth + 1), btree_depth(root->right, depth + 1)));
}

int btree_level_count(t_btree *root)
{
    return (btree_depth(root, 0));
}
