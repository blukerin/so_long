/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:02:50 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/15 19:05:19 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_size_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(game->mlx, &x, &y);
	if ((game->height * 64) > y || (game->width * 64) > x)
	{
		ft_printf("Error\nMap too big\n");
		close_game(game);
	}
}

int	handle_keys(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 119 || key == 97 || key == 100 || key == 115)
		movement_player(key, game);
	else if (key == 65362 || key == 65364 || key == 65363 || key == 65361)
		movement_player(key, game);
	else if (key == 65307)
		close_game(game);
	return (0);
}

static void	close_game_2(t_game *game)
{
	if (game->img_exit2)
		mlx_destroy_image(game->mlx, game->img_exit2);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_coin != NULL)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	close_game_2(game);
	exit(0);
}

void	game_to_null(t_game *game)
{
	game->win = NULL;
	game->img_coin = NULL;
	game->img_enemy = NULL;
	game->img_exit2 = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_wall = NULL;
}
