/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/28 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putchar_hexa(char c)
{
        int i;
        int a;
        int b;
        char hexbase[16]="0123456789abcdef";

        a = (c / 16);
        b = (c % 16);
        ft_putchar(hexbase[a]);
        ft_putchar(hexbase[b]);
}

void 	ft_print_addr(unsigned long long int addr)
{
	int a;
	unsigned long long int b;
	char tab_addr[12];
	char hexbase[16]="0123456789abcdef";

	a = 11;
	write(1,"0000",4);
	while (addr > 16)
	{
		b = (addr % 16);
		tab_addr[a]=hexbase[b];
		addr = addr / 16;
		a--;
	}
	tab_addr[a]=hexbase[addr % 16];

	a = 0;
	while (a < 12)
		ft_putchar(tab_addr[a++]);
	ft_putchar(':');
	ft_putchar(' ');
}

void ft_print_curraddr(unsigned long long int addr, int sizeleft)
{
	int a;
	char *buffer = (char *)addr;

	ft_print_addr(addr);	
	a = 0;
	while (a < 16 && addr)
	{
		if (a >= sizeleft)
		write(1,"  ",2);
		else
		ft_putchar_hexa(buffer[a]);
		if (a > 0 && a % 2 == 1)
		ft_putchar(' ');
	a++;
	}
	a = 0;
	while (a < 16 && a < sizeleft && addr)
		{

			if ((buffer[a]<32)||(buffer[a]==127))
			ft_putchar('.');
			else
			write(1,&(buffer[a]),1);
			a++;
		}
		ft_putchar('\n');
}

void 	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	
	i = 0;
	while (i < size)
	{
		ft_print_curraddr((unsigned long long int)addr + i, size - i);
		i += 16;
	}

}
int	main(void)
{
	char  string[200] = "Bonjour les aminches\t\n\tc est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. ";

	void *p = &string;
	ft_print_memory(p, 60);
	return (0);
}
