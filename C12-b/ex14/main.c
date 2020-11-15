/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:50:58 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/08 16:15:45 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ft_new_list(void)
{
    return (0);
}

int ft_is_list_empty(t_list *list)
{
    if (list == NULL)
        return (1);
    return (0);
}

int ft_listlen(t_list *list)
{
    int size;

    if (!ft_is_list_empty(list))
        while (list)
        {
            size++;
            list = list->next;
        }
    return (size);
}

void	ft_print_list(t_list *list)
{
    if (!list || ft_is_list_empty(list))
    {
        printf("\nEmpty list!\n");
        return;
    }   
    while (list != NULL)
    {
        printf("data -> [%i] | next -> [%p]\n", *((int *)list->data), (void *)(list->next));
        list = list->next;
    }
}

void ft_list_free(void *data)
{
    free(data);
}

void    ft_triple(void *data)
{
    *((int *)data) = (3 * *((int *)data));
}

void    set_to_minus_99(void *element)
{
    *((int *)element) = -99;
}

int     compare_modulo(void *data, void *data_ref)
{
    return (*((int *)data) % *((int *)data_ref));
}

void    delete_element(void *element)
{
        printf("element:: %d\n", *((int *)element));
            free(element);
}

int ft_intcmp(void *data1, void *data2)
{
    return (*((int*)data1) - *((int *)data2));
}

int	main(int ac, char **av)
{
    t_list *list = NULL;
    t_list *list2 = NULL;
    t_list *tmp;
    t_list *res;
    int i;
    int *modulo;
    //t_list *last_elem;
    int *nb;
    int *nb2;
    int *nb3;
    int *nb4;
    int *nb5;
    int *nb6;

    //list = 0;
    ft_print_list(list);
    nb = (int *)malloc(sizeof(int));
    nb2 = (int *)malloc(sizeof(int));
    nb3 = (int *)malloc(sizeof(int));
    nb4 = (int *)malloc(sizeof(int));
    nb5 = (int *)malloc(sizeof(int));
    nb6 = (int *)malloc(sizeof(int));
    *nb = 1;
    *nb2 = 4;
    *nb3 = 10;
    *nb4 = -5;
    *nb5 = -1;
    *nb6 = 99;
    list2 = ft_create_elem((void *)nb5);
    ft_list_push_front(&list2, (void *)nb6);
    list = ft_create_elem((void *)nb);
    ft_list_push_front(&list, (void *)nb2);
    ft_list_push_front(&list, (void *)nb3);
    ft_list_push_back(&list, (void *)nb4);
    printf("size: %i elements\n", ft_list_size(list));
    ft_print_list(list);
    printf("*-----------------------*\n");
    //ft_print_list(list2);
    //printf("*-----------------------*\n");
    i = 0;
    //tmp = ft_list_at(list, i);
    //printf("\nelem[%i]: [%i] - [%p]\n", i, *((int *)tmp->data), tmp->next);
    //ft_list_reverse(&list);
    //ft_print_list(list);
    //printf("*-----------------------*\n");
    // ft_list_foreach(list, &ft_triple);
    //ft_print_list(list);
    //printf("*-----------------------*\n");
    modulo = (int *)malloc(sizeof(int));
    *modulo = 3;
    //ft_list_foreach_if(list, &set_to_minus_99, modulo, &compare_modulo);
    //res = ft_list_find(list, modulo, &compare_modulo); 
    //if (res)
    //    printf("\nelem: [%i] - [%p]\n", *((int *)res->data), res->next);
    //ft_print_list(list);
    //    ft_list_remove_if(&list, modulo, &compare_modulo, &ft_list_free);
    // if (list)
    //ft_list_merge(&list, list2);
    ft_list_sort(&list, &ft_intcmp);
    ft_print_list(list);
}
