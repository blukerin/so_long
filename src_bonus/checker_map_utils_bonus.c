/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:53:08 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/13 12:53:09 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				ft_printf("Error\nElement inaccessible\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'X')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

t_point	find_player(char **map)
{
	t_point	pos;
	int		i;
	int		j;

	pos.y = 0;
	pos.x = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int	duplicate_map(char ***copy_map, char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	*copy_map = malloc(sizeof(char *) * (i + 1));
	if (!*copy_map)
		return (0);
	(*copy_map)[i] = NULL;
	i = 0;
	while (map[i] != NULL)
	{
		(*copy_map)[i] = ft_strdup(map[i]);
		if (!(*copy_map)[i])
		{
			while (i-- > 0)
				free((*copy_map)[i]);
			free(*copy_map);
			return (0);
		}
		i++;
	}
	return (1);
}
