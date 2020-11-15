/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:18:17 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/11 15:53:58 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void ft_putstr(char *str, int output)
{
    while (*str)
        write(output, str++, 1);
}

int main(int ac, char **av)
{
    int fd;
    int ret;
    char buf[BUF_SIZE + 1];

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            ft_putstr("Cannot read file.\n", STDERR_FILENO);
            return (-1);
        }
        while ((ret = read(fd, buf, BUF_SIZE)))
        {
        buf[ret] = '\0';
        ft_putstr(buf, STDOUT_FILENO);
        }
        if (close(fd) == -1)
            return (-1);
    }
    else if (ac == 1)
        ft_putstr("File name missing.\n", STDERR_FILENO);
    else if (ac > 2)
        ft_putstr("Too many arguments.\n", STDERR_FILENO);
    return (0);
}
