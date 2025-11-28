/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:20:15 by bsaldana          #+#    #+#             */
/*   Updated: 2025/04/11 18:26:44 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

static int	count_letters(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && word == 0 && s[i] != '\0')
		{
			count++;
			i++;
			word = 1;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			word = 0;
		}
	}
	return (count);
}

static void	ft_ind(int *index, char const *s, char c)
{
	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	index[3] = count_words(s, c);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		index[4];

	ft_ind(index, s, c);
	matrix = (char **)malloc((index[3] + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[index[3]] = NULL;
	if (index[3] == 0)
		return (matrix);
	while (s[index[1]] != '\0')
	{
		while (s[index[1]] == c && s[index[1]] != '\0')
			index[1]++;
		if (s[index[1]] == '\0')
			break ;
		index[2] = count_letters(&s[index[1]], c);
		matrix[index[0]] = (char *)malloc((index[2] + 1) * sizeof(char));
		if (!matrix[index[0]])
			return (free_memory(matrix), NULL);
		ft_strlcpy(matrix[index[0]], &s[index[1]], index[2] + 1);
		index[1] += index[2];
		index[0]++;
	}
	return (matrix);
}
