/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:40:42 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 23:44:47 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int curr_lvl = 0;
int is_1st[] = {1};

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first))
{
    if (!root)
        return;
    curr_lvl++;
    applyf(root->item, curr_lvl, is_1st[curr_lvl]);
    //curr_lvl++;
    printf("Curr Level: %i - |%i|%i|\n", curr_lvl, is_1st[0], is_1st[1]);
    //curr_lvl--;
    btree_apply_by_level(root->left, applyf);
    //curr_lvl--;
    is_1st[curr_lvl] = 0;
    btree_apply_by_level(root->right, applyf);
    curr_lvl--;
}
