/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:03:38 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/08 13:27:33 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest_s;
	unsigned char	*src_s;

	i = 0;
	if ((!dest && !src) || dest == src)
		return (dest);
	dest_s = (unsigned char *)dest;
	src_s = (unsigned char *)src;
	while (i < n)
	{
		dest_s[i] = src_s[i];
		i++;
	}
	return (dest);
}
