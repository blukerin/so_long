/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:07:27 by bsaldana          #+#    #+#             */
/*   Updated: 2025/09/24 13:07:30 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include "libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		total_coins;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;
	void	*img_exit2;
	void	*img_enemy;
}	t_game;

int		handle_keys(int key, void *param);
int		close_game(t_game *game);
char	**functs_map(char *ber);
int		validate_map(char **map, int height);
int		duplicate_map(char ***copy_map, char **map);
t_point	find_player(char **map);
void	flood_fill(char **map, int x, int y);
int		check_flood(char **map);
void	draw_map(t_game *game);
void	movement(t_game *game, int y, int x);
void	start_game(t_game *game, char **map);
int		check_file(char *file);
void	free_map(char **map);
void	movement_player(int key, t_game *game);
void	check_size_map(t_game *game);
void	game_to_null(t_game *game);

#endif