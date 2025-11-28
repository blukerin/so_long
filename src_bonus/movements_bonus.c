/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:04:25 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/15 19:07:16 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	movement(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'X')
	{
		ft_printf("Game Over.\n");
		close_game(game);
	}
	if (game->map[y][x] == 'E' && game->total_coins == 0)
	{
		ft_printf("¡Victory!\n");
		close_game(game);
	}
	if (game->map[y][x] == 'C')
		game->total_coins--;
	if (game->map[y][x] == 'E')
		game->map[y][x] = 'Z';
	else
		game->map[y][x] = 'P';
	if (game->map[game->player_y][game->player_x] == 'Z')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
}

static int	is_wall(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->height || x < 0 || x >= game->width)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	else
		return (1);
}

void	movement_player(int key, t_game *game)
{
	if (key == 119 || key == 65362)
	{
		if (is_wall(game, game->player_x, game->player_y - 1))
			movement(game, game->player_y - 1, game->player_x);
	}
	else if (key == 115 || key == 65364)
	{
		if (is_wall(game, game->player_x, game->player_y + 1))
			movement(game, game->player_y + 1, game->player_x);
	}
	else if (key == 100 || key == 65363)
	{
		if (is_wall(game, game->player_x + 1, game->player_y))
			movement(game, game->player_y, game->player_x + 1);
	}
	else if (key == 97 || key == 65361)
	{
		if (is_wall(game, game->player_x - 1, game->player_y))
			movement(game, game->player_y, game->player_x - 1);
	}
}
