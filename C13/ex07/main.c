/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:04:18 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 22:03:04 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <assert.h>
void btree_print(t_btree *tr)
{
    printf("[%i]\n", *((int*)tr->item));
    if (tr->left != 0)
    {
        printf("/\n");
        btree_print(tr->left);
    }
    if (tr->right != 0)
    {
        printf("\\\n");
        btree_print(tr->right);
    }
    return;
}

void ft_triple(void *data)
{
    *(int *)data = *(int *)data * 3;
}

int ft_intcmp(void *data1, void *data2)
{
    return((*(int *)data1) - (*(int *)data2));
}

void ft_transfo(void *item, int current_level, int is_first)
{
    int *magicnb;

    magicnb = malloc(sizeof(int));
    *magicnb = -99;
    printf("BEFORE TRANSFO: %i\n", *((int *)item));
    if (is_first == 1)
        *((int *)item) = (*(int *)item) * 10;
    else
        *((int *)item) = (*((int *)item)) * current_level;
    printf("AFTER TRANSFO: %i\n", *((int *)item));
}

int main(void)
{
    int *nb;
    int *nb2;
    int *nb3;
    int *nb4;
    int *nb5;
    int *nb6;
    int *nb7;
    int *nb8;
    int *nb9;
    int *nb10;
    void (*f)(void*, int, int);
    //char *item = "Hello, world!";
    t_btree *emptynode = NULL;
    t_btree *node;
    t_btree *node2;
    t_btree *node3;
    t_btree *node4;
    t_btree *node5;
    t_btree *node6;
    t_btree *node7;
    t_btree *node8;
    t_btree *node9;
    t_btree *node10;

    f = &ft_transfo;
    nb = malloc(sizeof(int));
    nb2 = malloc(sizeof(int));
    nb3 = malloc(sizeof(int));
    nb4 = malloc(sizeof(int));
    nb5 = malloc(sizeof(int));
    nb6 = malloc(sizeof(int));
    nb7 = malloc(sizeof(int));
    nb8 = malloc(sizeof(int));
    nb9 = malloc(sizeof(int));
    nb10 = malloc(sizeof(int));
    *nb = 5;
    *nb2 = 10;
    *nb3 = 15;
    *nb4 = 20;
    *nb5 = 25;
    *nb6 = 30;
    *nb7 = 35;
    *nb8 = 40;
    *nb9 = 45;
    *nb10 = 50;
    node = btree_create_node(nb);
    node2 = btree_create_node(nb2);
    node3 = btree_create_node(nb3);
    node4 = btree_create_node(nb4);
    node5 = btree_create_node(nb5);
    node6 = btree_create_node(nb6);
    node7 = btree_create_node(nb7);
    node8 = btree_create_node(nb8);
    node9 = btree_create_node(nb9);
    node10 = btree_create_node(nb10);
    node6->left = node3;
    node6->right = node8;
    node8->left = node7;
    node8->right = node9;
    node9->right = node10;
    node3->left = node2;
    node3->right = node4;
    node2->left = node;
    node4->right = node5;
    if (emptynode)
        btree_print(emptynode);
    if (node6)
        btree_print(node6);
    printf("*--------------------------*\n");
    //btree_insert_data(&emptynode, nb8, &ft_intcmp);
    //btree_insert_data(&node, nb8, &ft_intcmp);
    //btree_apply_suffix(node, &ft_triple);
    //printf("*--------------------------*\n");
    //btree_print(node);
    //printf("Element trouvé? %i", *(int *)btree_search_item(node, nb3, &ft_intcmp));
    ft_transfo(node6->item, 1, 0);
    btree_apply_by_level(node6, &ft_transfo);
    btree_print(node6);
    //btree_search_item(node, nb2, &ft_intcmp);
    //btree_print(emptynode);
    free(node6);
}
