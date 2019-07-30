// #include "../libft.h"
#include "../includes/ft_printf.h"
#include <stdio.h>

//https://github.com/agavrel/42-ft_printf/blob/master/misc/main.c

int	main()
{

	// Char tests
	printf ("printf: %c %c \n", 'a', 65);
	ft_printf("mine: %c %c \n", 'a', 65);
	pf_putchar('\n');
	printf ("printf: %c \n", 'a');
	ft_printf("mine: %c \n", 'a');
	pf_putchar('\n');
	printf("printf: %5c\n", '$');
	ft_printf("mine: %5c\n", '$');
	pf_putchar('\n');
	printf("printf: %10c\n", '$');
	ft_printf("mine: %10c\n", '$');
	pf_putchar('\n');
	printf("printf 2 minus:	%-5c %c\n", '$', '%');
	ft_printf("mine 2 minus: %-5c %c\n", '$', '%');
	pf_putchar('\n');
	// ft_printf ("printf: %d %ld\n", 1977, 650000L);
	// printf ("mine: %d %ld\n", 1977, 650000L);

	// ft_printf("Preceding with blanks: %10d \n", 1977);
	// printf ("Preceding with blanks: %10d \n", 1977);

	// ft_printf("Preceding with zeros: %010d \n", 1977);
	// printf ("Preceding with zeros: %010d \n", 1977);

	// ft_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	// printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);

	// ft_printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);

	// ft_printf("Width trick: %*d \n", 5, 10);
	// printf ("Width trick: %*d \n", 5, 10);

	
	printf ("printf: %s \n", "A string");
	ft_printf ("mine: %s \n", "A string");
	pf_putchar('\n');
	printf("printf: hello, %s \n" , "gavin");
	ft_printf("mine: hello, %s \n" , "gavin");
	pf_putchar('\n');
	//percent sign
	printf("printf: %%\n");
	ft_printf("mine: %%\n");
	
	// system("leaks test"); FOR LATER
	return 0;
}

