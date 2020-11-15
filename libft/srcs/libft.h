/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:40:20 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/15 12:35:05 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
void ft_bzero(void *s, size_t n);
int ft_isalpha(int c);

#endif
