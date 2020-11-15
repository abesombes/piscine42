/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:45:10 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/13 00:02:34 by alexandre        ###   ########.fr       */
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
    char *line;
    int i;
    int j;

    //printf("malloc size: %i", ft_strlen(dest) + ft_strlen(src) + 1);
    if (!(line = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1))))
        return (0);
    i = -1;
    j = -1;
    while (dest[++i])
        line[i] = dest[i];
    while (src[++j])
        line[i + j] = src[j];
    line[i + j] = '\0';
    return (line);
}
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
        ft_putstr(buf, STDOUT_FILENO);
    }
    close(fd);
}

void ft_readstdin(void)
{
    char **line;
    char buf[2];
    int ret;
    int count_eot;
    int count_lf;

    count_lf = 0;
    count_eot = 0;
    line = (char **)malloc(sizeof(char*) * 11);
    ret = -1;
    while (++ret < 10)
        line[ret] = malloc(30000);
    while ((ret = read(0, buf, 1)) && !(buf[0] == 4 && count_eot >= 1))
    {
        if (buf[0] == 4)
            count_eot++;
        buf[ret] = '\0';
        if (buf[0] == '\n')
            count_lf = ((count_lf >= 9)? 0: count_lf + 1); 
        else
        {
            line[count_lf] = ft_strcpy(line[count_lf], buf);
            line[count_lf + 1][0] = '\0';
        }    
    }
    ret = 0;
    while (ret < 10 && line[ret] && line[ret][0] != '\0')
    {
        ft_putstr(line[ret], STDOUT_FILENO);
        ft_putstr("\n", STDOUT_FILENO);
        ret++;
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
