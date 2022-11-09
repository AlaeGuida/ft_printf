/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguida <aguida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:04:12 by aguida            #+#    #+#             */
/*   Updated: 2022/11/09 15:13:18 by aguida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	functional_func(const char *s, va_list args)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (*s == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (*s == '%')
		i = ft_putchar('%');
	else if (*s == 'x')
		i = ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		i = ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*s == 'd' || *s == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (*s == 'u')
		i = ft_putunbr(va_arg(args, unsigned int));
	else if (*s == 'p')
	{
		i = ft_putstr("0x");
		i += ft_puthexa(va_arg(args, unsigned long), "0123456789abcdef");
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			i += functional_func(s, args);
			s++;
		}
		else
		{
			i += ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (i);
}
// #include <stdio.h>

// int	main()
// {
// 	char *s = "hello";
// 	ft_printf("%s", s);
// }
