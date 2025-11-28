/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:38:21 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/15 15:38:22 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*get_image(t_game *game, char c)
{
	if (c == '1')
		return (game->img_wall);
	else if (c == '0')
		return (game->img_floor);
	else if (c == 'P')
		return (game->img_player);
	else if (c == 'E')
		return (game->img_exit);
	else if (c == 'C')
		return (game->img_coin);
	else if (c == 'Z')
		return (game->img_exit2);
	else if (c == 'X')
		return (game->img_enemy);
	return (NULL);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	void	*img;
	char	*movements;

	y = 0;
	movements = NULL;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = get_image(game, game->map[y][x]);
			mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

static void	player_window_coins(char **map, t_game *game)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	game->total_coins = coins;
	game->height = i;
	game->width = ft_strlen(map[0]);
}

static void	game_stats(t_game *game, char **map)
{
	int		w;
	int		h;
	void	*mlx;
	void	*m;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("Error al inicializar MLX\n");
		return ;
	}
	h = 64;
	w = 64;
	game->mlx = mlx;
	player_window_coins(map, game);
	game->map = map;
	game->moves = 0;
	m = game->mlx;
	game->img_wall = mlx_xpm_file_to_image(m, "textures/tree.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(m, "textures/fond.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(m, "textures/npc.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(m, "textures/exit.xpm", &w, &h);
	game->img_coin = mlx_xpm_file_to_image(m, "textures/poke.xpm", &w, &h);
	game->img_exit2 = mlx_xpm_file_to_image(m, "textures/exit_npc.xpm", &w, &h);
	game->img_enemy = mlx_xpm_file_to_image(m, "textures/enemy.xpm", &w, &h);
}

void	start_game(t_game *game, char **map)
{
	int	w;
	int	h;

	game_to_null(game);
	game_stats(game, map);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_coin || !game->img_enemy)
	{
		ft_printf("Error while loading images\n");
		close_game(game);
	}
	h = game->height * 64;
	w = game->width * 64;
	check_size_map(game);
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
	{
		ft_printf("Error al abrir la ventana\n");
		close_game(game);
	}
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_key_hook(game->win, handle_keys, game);
	draw_map(game);
	mlx_loop(game->mlx);
}
