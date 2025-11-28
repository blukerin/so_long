/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:53:10 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/08 15:52:27 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	i;

	dest_l = ft_strlen((const char *) dest);
	src_l = ft_strlen(src);
	i = 0;
	if (size <= dest_l)
		return (size + src_l);
	while (i < size - dest_l - 1 && src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (dest_l + src_l);
}
