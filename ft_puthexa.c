/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguida <aguida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:29:54 by aguida            #+#    #+#             */
/*   Updated: 2022/11/09 15:38:01 by aguida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		++i;
	while (nb > 0)
	{
		++i;
		nb /= 16;
	}
	return (i);
}

int	ft_puthexa(unsigned long address, char *s)
{
	if (address == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (address > 15)
	{
		ft_puthexa(address / 16, s);
		ft_putchar(s[address % 16]);
	}
	else
		ft_putchar(s[address % 16]);
	return (counter(address));
}
/*
int main()
{
	ft_puthexa(12563, "0123456789abcdef");
}
*/