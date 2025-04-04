/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:51:52 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/04/04 17:53:08 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putstr(char *str)
{
	int len = 0;
	int	i = 0;
	
	if (!str)
	{
		len = write(1, "(null) ",  6);
		return (len);
	}
	while(str[i])
	{
		len += write(1, &str[i], 1);
		i++;	
	}
	return (len);
}

int	ft_putnbr(int nbr, int base)
{
	int				len = 0;
	unsigned int	temp_nbr = 0;
	char			*hexa = "0123456789abcdef";
	
	if (nbr < 0 &&  base == 10)
	{
		len += write(1, "-", 1);
		temp_nbr = -nbr;
	}
	else
		temp_nbr = (unsigned int)nbr;
	if (temp_nbr >=  (unsigned int)base)
		len += ft_putnbr((temp_nbr / base), base);
	len += write(1, &hexa[temp_nbr % base], 1);
	return (len);
}



int ft_printf(const char *str, ...)
{
	va_list(args);
	int	len = 0;
	int	i = 0;
	
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				len += ft_putnbr(va_arg(args, int), 10);
			else if (str[i] == 'x')
				len += ft_putnbr(va_arg(args, int), 16);
			else if (str[i] == '%')
				len += write(1, "%", 1);
		}
		else
	
	  	len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>
#include <limits.h>

int main (void)
{
	int og;
	int new;

    char *str = "space cow";
    printf("\n");
    printf("Testing ft_prints(string)\n");  ///////////////////////////////////////
    printf("\n");

    og = printf("Og printf : %s", str);
	printf("\n");
	new = ft_printf("my printf : %s", str);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	char long_str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    og = printf("Og printf : %s", long_str);
	printf("\n");
	new = ft_printf("my printf : %s", long_str);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");


    char str2[] = " it's a trap!!! , run you fools.";

    og = printf("Og printf : %s", str2);
	printf("\n");
	new = ft_printf("my printf : %s", str2);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

    og = printf("Og printf : %s", "");
	printf("\n");
	new = ft_printf("my printf : %s", "");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %s %s", "-", "4");
	printf("\n");
	new = ft_printf("my printf : %s %s", "-", "4");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

    og = printf("Og printf : %s %s%s", "-", "4", "2");
	printf("\n");
	new = ft_printf("my printf : %s %s%s", "-", "4", "2");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	char *hmm = NULL;

	og = printf("Og printf : %s", hmm);
	printf("\n");
	new = ft_printf("my printf : %s", hmm);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	printf("\n");
	printf("Testing ft_printd (Decimal base 10)\n");  /////////////////////////////////////
	printf("\n");

	printf("Testing ft_printd (Positive numbers)\n");


	int nbr1 = 42;

	og = printf("Og printf : %d", nbr1);
	printf("\n");
	new = ft_printf("my printf : %d", nbr1);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %d", INT_MAX);
	printf("\n");
	new = ft_printf("my printf : %d", INT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	printf("\n");
	printf("Testing ft_printd (Negative numbers)\n");

	int nbr2 = -42;

	og = printf("Og printf : %d", nbr2);
	printf("\n");
	new = ft_printf("my printf : %d", nbr2);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	int nbr3 = -1000000;

	og = printf("Og printf : %d", nbr3);
	printf("\n");
	new = ft_printf("my printf : %d", nbr3);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %d", -50000454);
	printf("\n");
	new = ft_printf("my printf : %d", -50000454);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %d", INT_MIN);
	printf("\n");
	new = ft_printf("my printf : %d", INT_MIN);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");



	printf("\n");
	printf("Testing ft_printx (Hexadecimal)\n");  //////////////////////////////
	printf("\n");

	unsigned nbr6 = 420;

	og = printf("Og printf : %x", nbr6);
	printf("\n");
	new = ft_printf("my printf : %x", nbr6);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", 17);
	printf("\n");
	new = ft_printf("my printf : %x", 17);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", 999999);
	printf("\n");
	new = ft_printf("my printf : %x", 999999);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", 4294967293u);
	printf("\n");
	new = ft_printf("my printf : %x", 4294967293u);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", 0);
	printf("\n");
	new = ft_printf("my printf : %x", 0);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", INT_MAX);
	printf("\n");
	new = ft_printf("my printf : %x", INT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", UINT_MAX);
	printf("\n");
	new = ft_printf("my printf : %x", UINT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	printf("\n");
	printf("Testing ft_printx (Negative numbers)\n");

	og = printf("Og printf : %x", -100);
	printf("\n");
	new = ft_printf("my printf : %x", -100);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", -17);
	printf("\n");
	new = ft_printf("my printf : %x", -17);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", INT_MIN);
	printf("\n");
	new = ft_printf("my printf : %x", INT_MIN);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %x", -150);
	printf("\n");
	new = ft_printf("my printf : %x", -150);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	printf("\n");
	printf("Testing ft_print (Percent sign)\n");  //////////////////////////////
	printf("\n");

	og = printf("Og printf : %%");
	printf("\n");
	new = ft_printf("my printf : %%");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %% %%");
	printf("\n");
	new = ft_printf("my printf : %% %%");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

	og = printf("Og printf : %% %% %%");
	printf("\n");
	new = ft_printf("my printf : %% %% %%");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

} */