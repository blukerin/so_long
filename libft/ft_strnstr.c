/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:11:26 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/09 12:10:13 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_finder(const char *big, const char *little, size_t len, size_t i)
{
	unsigned int	j;

	j = 0;
	while (big[i + j] && little[j] && big[i + j] == little[j] && (i + j) < len)
		j++;
	if (little[j] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)(big));
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			if (ft_finder(big, little, len, i) == 1)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
