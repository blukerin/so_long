/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:55:45 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/11 12:50:00 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bool(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	len;
	unsigned int	s_len;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 1;
	s_len = ft_strlen(s1);
	while (s1[i] != '\0' && k == 1)
	{
		if (ft_bool(s1[i], set) == 1)
			i++;
		else
			k = 0;
	}
	k = 1;
	while (k == 1 && s_len > 0)
	{
		if (ft_bool(s1[s_len - 1], set) == 1)
			s_len--;
		else
			k = 0;
		len = s_len - i;
	}
	return (ft_substr(s1, i, len));
}
