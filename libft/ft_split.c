/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:35:27 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/20 10:35:04 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
			count++;
		i = i + j;
	}
	return (count);
}

static char	*ft_strn_dup(const char *source, size_t size)
{
	char	*dup;
	size_t	i;

	if (!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		dup[i] = source[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		count_wd;

	if (!c || !s)
		return (NULL);
	count_wd = ft_count_words(s, c);
	if (!(strs = (char **)malloc((count_wd + 1) * sizeof(char *))))
		return (NULL);
	strs[count_wd] = 0;
	count_wd = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
			strs[count_wd++] = ft_strn_dup(s + i, j - 1);
		i = i + j;
	}
	return (strs);
}
