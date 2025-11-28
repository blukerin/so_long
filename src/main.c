/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:24:26 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/15 18:39:04 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	t_game	game;

	if (argc == 2)
	{
		if (!check_file(argv[1]))
		{
			ft_printf("Error\nIncorrect file format\n");
			return (1);
		}
		map = functs_map(argv[1]);
		if (!map)
			return (1);
		start_game(&game, map);
	}
	else
		ft_printf("Invalid arguments\n");
	return (0);
}
