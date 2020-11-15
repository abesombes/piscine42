/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:54:07 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/15 00:55:59 by alexandre        ###   ########.fr       */
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

int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void ft_hex(unsigned char c)
{
    char t[2];
    char base[16] = "0123456789abcdef";
    t[0] = 0;
    t[1] = 0;
    t[1] = base[c % 16];
    c = c / 16;
    t[0] = base[c % 16];
    write(1, &t[0], 1);
    write(1, &t[1], 1);
}

void ft_putchar (char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void ft_puterr(char *str)
{
    while (*str)
        write(2, str++, 1);
}

void ft_putnbr_hex(unsigned int nbr)
{
    int i;
    char t[8];
    char base[16] = "0123456789abcdef";    
    
    i = -1;
    while (++i < 8)
        t[i] = '0'; 
    i = 8;
    while (nbr > 15 && i >= 0)
    {
        t[--i] = base[nbr % 16];
        nbr = nbr / 16;
    }
    t[--i] = base[nbr % 16];
    i = -1;
    while (++i <= 7)
        write(1, &t[i], 1);
}

void    ft_hexdump_stdin(char *data)
{
    int i;
    int j;
    int size;

    i = 0;
    if (ft_strcmp(data, "\0") == 0)
        return;
    size = ft_strlen((char *)data);
    while (i < size)
    {
        j = -1;
        ft_putnbr_hex(i);
        ft_putstr("  ");
        while (++j < 16)
        {
            data[i + j] ? ft_hex(data[i + j]) : ft_putstr("  ");
            ft_putstr((j == 7 ? "  ": " "));
        }
        j = -1;
        ft_putstr(" |");
        while (++j < 16)
            if (data[i + j])
                ft_putchar((data[i + j] < 32 || data[i + j] > 126) ? '.': data[i + j]);
        ft_putstr("|\n");
        i = i + 16;
    }
    ft_putnbr_hex(size);
    ft_putchar('\n');
}

char *ft_readstdin(void)
{
    char *input;
    char *tmp;
    char buf[2];
    int ret;
    int count_eot;

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
    ft_hexdump_stdin(input);
    return (input);
}   

char *ft_display_file(char *filename, char *bin)
{
    int fd;
    int ret;
    char *input;
    char *tmp;
    char buf[4096];

    input = "\0";
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_puterr(bin);
        ft_puterr(": ");
        ft_puterr(filename);
        ft_puterr(": ");
        ft_puterr(strerror(errno));
        ft_puterr("\n");
    }
    else
        while ((ret = read(fd, buf, BUF_SIZE)))
        {
            buf[ret] = '\0';
            tmp = ft_strcpy(input, "");
            input = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ret + 1));
            input = ft_strcpy(tmp, buf);
            free(tmp);
        }
    if (fd != -1)
        close(fd);
    return (input);
}



void    ft_hexdump(char *data)
{
    int i;
    int j;
    int size;

    i = 0;
    if (ft_strcmp(data, "\0") == 0)
        return;
    size = ft_strlen((char *)data);
    while (i < size)
    {
        j = -1;
        ft_putnbr_hex(i);
        ft_putstr("  ");
        while (++j < 16)
        {
            data[i + j] ? ft_hex(data[i + j]) : ft_putstr("  ");
            ft_putstr((j == 7 ? "  ": " "));
        }
        j = -1;
        ft_putstr(" |");
        while (++j < 16)
            if (data[i + j])
                ft_putchar((data[i + j] < 32 || data[i + j] > 126) ? '.': data[i + j]);
        ft_putstr("|\n");
        i = i + 16;
    }
    ft_putnbr_hex(size);
    ft_putchar('\n');
}

int main(int ac, char **av)
{
    char *bin;
    char *input;
    char *tmp;
    int i;

    input = "\0";
    if (ac >= 1)
        bin = basename(av[0]);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'C' && !av[1][2])
        ft_readstdin(); 
    if (ac >= 3 && av[1][0] == '-' && av[1][1] == 'C' && !av[1][2])
    {   
        i = 1; 
        while (++i < ac)
        {
            tmp = ft_strcpy(input, ""); 
            if (ft_strcmp(ft_display_file((char*)av[i], bin), "\0") != 0)
            {
                input = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(ft_display_file((char *)av[i], bin)) + 1));
                input = ft_strcpy(tmp, ft_display_file((char *)av[i], bin));
            } 
            free(tmp);
        }
        ft_hexdump(input);
    }
     return (0);
}
