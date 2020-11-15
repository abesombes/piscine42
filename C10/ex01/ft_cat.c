/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:47:47 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/11 23:06:10 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <libgen.h>
#define BUF_SIZE 4096

extern  int errno;

void ft_putstr(char *str, int output)
{
    while (*str)
        write(output, str++, 1);
}

void ft_display_file(char *filename, char *bin)
{
    int fd;
    int ret;
    char buf[BUF_SIZE + 1];
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr(bin, STDERR_FILENO);
        ft_putstr(": ", STDERR_FILENO);
        ft_putstr(filename, STDERR_FILENO);
        ft_putstr(": ", STDERR_FILENO);
        ft_putstr(strerror(errno), STDERR_FILENO);
        ft_putstr("\n", STDERR_FILENO);
        return;
    }
    while ((ret = read(fd, buf, BUF_SIZE)))
    {
        buf[ret] = '\0';
        ft_putstr(buf, STDOUT_FILENO);
    }
    close(fd);
}

void ft_readstdin(void)
{
    char buf[2];
    int ret;
    
    while ((ret = read(0, buf, 1)) && buf[0] != 4)
    {
        buf[ret] = '\0';
        ft_putstr(buf, STDOUT_FILENO);
    }
}   

int main(int ac, char **av)
{
    char *bin;
    int i;

    i = 0;
    bin = basename(av[0]);
    if (ac == 2)
        ft_display_file(av[1], bin);
    else if (ac == 1)
        ft_readstdin();
    else if (ac > 2)
    {
        while (++i < ac)
        {
            if (av[i][0] == '-' && !av[i][1])
                ft_readstdin();
            else
                ft_display_file(av[i], bin);
        }
    }
    return (0);
}
