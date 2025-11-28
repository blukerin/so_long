/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:50:52 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/15 19:12:40 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_element(char c, int *exit, int *player, int *coins)
{
	if (c == 'C')
		*coins = *coins + 1;
	else if (c == 'E')
		*exit = *exit + 1;
	else if (c == 'P')
		*player = *player + 1;
	else if (c != '0' && c != '1')
	{
		ft_printf("Error\nInvalid character\n");
		return (0);
	}
	return (1);
}

static int	elements_map(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;
	int	coins;

	player = 0;
	exit = 0;
	coins = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!check_element(map[i][j], &exit, &player, &coins))
				return (0);
			j++;
		}
		i++;
	}
	if (coins < 1 || exit != 1 || player != 1)
		return (ft_printf("Error\nInvalid number of components\n"), 0);
	return (1);
}

static int	closed_map(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[0][j] != '1' || map[height - 1][j] != '1')
				return (0);
			j++;
		}
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char **map, int height)
{
	char	**copy_map;
	t_point	player;

	copy_map = NULL;
	if (!closed_map(map, height))
	{
		ft_printf("Error\nMap not closed\n");
		return (0);
	}
	if (!elements_map(map))
		return (0);
	if (!duplicate_map(&copy_map, map))
		return (0);
	player = find_player(map);
	flood_fill(copy_map, player.x, player.y);
	if (!check_flood(copy_map))
	{
		free_map(copy_map);
		return (0);
	}
	free_map(copy_map);
	return (1);
}
