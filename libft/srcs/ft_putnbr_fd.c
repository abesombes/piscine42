/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:29:19 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/19 00:44:14 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;
	char c;

	nb = (n < 0 ? -n : n);
	if (n < 0)
		write(fd, "-", 1);
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + 48;
	write(fd, &c, 1);

}

int main(void)
{
	ft_putnbr_fd(-123456, 2);
}
