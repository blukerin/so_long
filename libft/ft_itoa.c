/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:53:59 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/11 13:36:59 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_aux(long numb, int t, char *str)
{
	str[t--] = '\0';
	if (numb == 0)
		str[0] = 0 + '0';
	else if (numb < 0)
	{
		numb = -numb;
		str[0] = '-';
		while (t > 0)
		{
			str[t] = (numb % 10) + '0';
			t--;
			numb = numb / 10;
		}
	}
	else
	{
		while (t >= 0)
		{
			str[t] = (numb % 10) + '0';
			t--;
			numb = numb / 10;
		}
	}
}

static int	ft_numlen(long n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n >= 1)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		t;
	long	numb;
	char	*str;

	numb = (long)n;
	t = ft_numlen(numb);
	str = (char *)malloc((t + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_itoa_aux(numb, t, str);
	return (str);
}
