/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:45:10 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/13 20:19:40 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#define BUF_SIZE 4096

extern  int errno;

int ft_strlen(char *str)
{
    int i;

    i = -1;
    while (str[++i]);
    return (i);
}

char *ft_strcpy(char *dest, char *src)
{
    char *input;
    int i;
    int j;

    if (!(input = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1))))
        return (0);
    i = -1;
    j = -1;
    while (dest[++i])
        input[i] = dest[i];
    while (src[++j])
        input[i + j] = src[j];
    input[i + j] = '\0';
    return (input);
}

void ft_putstr(char *str, int output)
{
    while (*str)
        write(output, str++, 1);
}

int ft_atoi(char *str, char *bin)
{
    int res; 
    int i;

    i = -1;
    res = 0;
    while (str[++i] >= '0' && str[i] <= '9')
        res = res * 10 + str[i] - 48;
    if (i != ft_strlen(str))
        {
            ft_putstr(bin, STDERR_FILENO);
            ft_putstr(": invalid number of bytes: ", STDERR_FILENO);
            ft_putstr("‘", STDERR_FILENO);
            ft_putstr(str, STDERR_FILENO);
            ft_putstr("’\n", STDERR_FILENO);
            return (0);
        }
    return (res);
}

void ft_trim_10lastlines(char *input)
{
    int i;
    int count_lf;

    count_lf = 0;
    i = ft_strlen(input) + 1;
    while (--i >= 0 && count_lf < 11)
    {
        if (input[i] == '\n')
            count_lf++;
    }
    if (input[i+1] == '\n')
        i++;
    while (++i < ft_strlen(input))
            write(1, &(input[i]), STDOUT_FILENO);
}

void ft_trim_n_lastoctets(char *input, int nb)
{
    int i;
    int size;

    size = ft_strlen(input);
    i = size - nb - 1;
    while (++i < size)
            write(1, &(input[i]), STDOUT_FILENO);
}

void ft_display_file(char *option, int nb, char *filename, char *bin)
{
    int fd;
    int ret;
    char *input;
    char *tmp;
    char buf[BUF_SIZE + 1];

    input = "\0";
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr(bin, STDERR_FILENO);
        ft_putstr(": cannot open '", STDERR_FILENO);
        ft_putstr(filename, STDERR_FILENO);
        ft_putstr("' for reading: ", STDERR_FILENO);
        ft_putstr(strerror(errno), STDERR_FILENO);
        ft_putstr("\n", STDERR_FILENO);
        return;
    }
    while ((ret = read(fd, buf, BUF_SIZE)))
    {
        buf[ret] = '\0';
        tmp = ft_strcpy(input, "");
        input = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ret + 1));
        input = ft_strcpy(tmp, buf);
        free(tmp); 
    }
    if (option[0] == '-' && option[1] == 'l')
        ft_trim_10lastlines(input);
    if (option[0] == '-' && option[1] == 'c')
        ft_trim_n_lastoctets(input, nb);
    close(fd);
}

void ft_readstdin(char *option, char *bin, int nb)
{
    char *input;
    char *tmp;
    char buf[2];
    int ret;
    int count_eot;
   
    (void)bin;
    (void)nb;
    count_eot = 0;
    input = "\0";
    while ((ret = read(0, buf, 1)) && !(buf[0] == 4 && count_eot >= 1))
    {
        if (buf[0] == 4)
            count_eot++;
        buf[ret] = '\0';
        tmp = ft_strcpy(input, "");
        input = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 2));
        input = ft_strcpy(tmp, buf);
        free(tmp);
    }
    if (option[0] == '-' && option[1] == 'l')
        ft_trim_10lastlines(input);
    if (option[0] == '-' && option[1] == 'c')
        ft_trim_n_lastoctets(input, nb);
}   

int main(int ac, char **av)
{
    char *bin;
    int i;
    
    i = 0;
    bin = basename(av[0]);
    if (ac == 2)
        ft_display_file("-l", 10, av[1], bin);
    else if (ac == 1) 
        ft_readstdin("-l", bin, 10);
    else if (ac >= 3 && av[1][0] == '-' && av[1][1] == 'c' && ft_atoi(av[2], bin) > 0)
        while (++i < ac)
        {
            i = i + (i == 1 ? 2: 0);
            if (i > 3)
                ft_putstr("\n", STDERR_FILENO);
            ft_putstr("==> ", STDERR_FILENO);
            ft_putstr((av[i][0] == '-'? "standard input" : av[i]), 2);
            ft_putstr(" <==\n", STDERR_FILENO);
            if (av[i][0] == '-' && !av[i][1])
                ft_readstdin("-c", bin, ft_atoi(av[2], bin));
            else
                ft_display_file("-c", ft_atoi(av[2], bin), av[i], bin);
        }
    else if (ac >= 3)
        while (++i < ac)
        {
            if (i > 1)
                ft_putstr("\n", STDERR_FILENO);
            ft_putstr("==> ", STDERR_FILENO);
            ft_putstr((av[i][0] == '-'? "standard input" : av[i]), 2);
            ft_putstr(" <==\n", STDERR_FILENO);
            if (av[i][0] == '-' && !av[i][1])
                ft_readstdin("-l", bin, 10);
            else
                ft_display_file("-l", 10, av[i], bin);
        }
    return (0);
}
