/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:39:20 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/30 12:29:26 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	int	n;

	n = 1;
	write (1, &c, 1);
	return (n);
}

static int	ft_check_param(const char c, va_list arg)
{
	static int	size;

	size = 0;
	if (c == 'c')
		size = size + ft_putchar(va_arg(arg, int));
	else if (c == 's')
		size = size + ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		size = size + ft_putvoid(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		size = size + ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		size = size + ft_putunsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		size = size + ft_puthex_lower(va_arg(arg, unsigned int));
	else if (c == 'X')
		size = size + ft_puthex_upper(va_arg(arg, unsigned int));
	else if (c == '%')
	{
		size++;
		write (1, "%", 1);
	}
	return (size);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start(args, s);
	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			size = size + ft_check_param(s[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			size++;
		}
		i++;
	}
	va_end (args);
	return (size);
}
