/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:10:09 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:37 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_upper(unsigned int num) //%X
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
		i = i + ft_puthex_upper(num / 16);
	i = i + ft_putchar(hex[num % 16]);
	return (i);
}

int	ft_puthex_lower(unsigned long long num) //%x
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		i = i + ft_puthex_lower(num / 16);
	i = i + ft_putchar(hex[num % 16]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
	{
		size = size + ft_putstr("-2147483648");
		return (size);
	}
	if (n == 0)
	{
		size = size + ft_putchar('0');
		return (size);
	}
	if (n < 0)
	{
		size = size + ft_putchar('-');
		n = -n;
	}
	size = size + ft_putunsigned((unsigned int)n);
	return (size);
}

int	ft_putunsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = size + ft_putchar('0');
	else
	{
		if (n / 10 != 0)
			size = size + ft_putunsigned(n / 10);
		size = size + ft_putchar((n % 10) + '0');
	}
	return (size);
}

int	ft_putvoid(void *n)
{
	int	size;

	size = 0;
	if (n == NULL)
		size = size + write (1, "(nil)", 5);
	else
	{
		size = size + write (1, "0x", 2);
		size = size + ft_puthex_lower((unsigned long long)n);
	}
	return (size);
}
