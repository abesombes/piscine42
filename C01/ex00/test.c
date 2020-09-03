#include <stdio.h>
#include <unistd.h>

void	ft_putaddr(int *str)
{
	printf("L'adresse de a est : %p\n",str);	
}

void 	ft_test(void)
{
	int a;
	int *ptr;

	a = 15;
	ptr=&a;
        printf("L'adresse de a est : %p\n",ptr);        

}

int 	main(void)
{
	ft_test();
}

