/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:44:22 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/17 13:28:10 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	copy_map(char **map, char *ber, int width)
{
	int		fd;
	char	*line;
	int		i;
	int		size;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening the file\n");
		return (0);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size = ft_strlen(line);
		if (line[size - 1] == '\n')
			line [size - 1] = '\0';
		ft_strlcpy(map[i], line, width + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (1);
}

static char	**alloc_lines(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
		{
			while (i > 0)
			{
				i--;
				free(map[i]);
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static char	**memory_map(int fd, int *width, int *height)
{
	char	**matrix;
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (*width == -1)
			*width = len;
		free(line);
		if (*width != len)
			*width = -2;
		*height = *height + 1;
		line = get_next_line(fd);
	}
	if (*width == -2)
		return (ft_printf("Error\nNot rectangular map\n"), NULL);
	matrix = malloc(sizeof(char *) * (*height + 1));
	if (!matrix)
		return (NULL);
	matrix[*height] = NULL;
	return (matrix);
}

char	**functs_map(char *ber)
{
	char	**map;
	int		width;
	int		heigth;
	int		fd;

	map = NULL;
	width = -1;
	heigth = 0;
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = memory_map(fd, &width, &heigth);
	close(fd);
	if (!map)
		return (NULL);
	map = alloc_lines(map, width, heigth);
	if (!map)
		return (NULL);
	copy_map(map, ber, width);
	if (!validate_map(map, heigth))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (file[len - 1] != 'r')
		return (0);
	if (file[len - 2] != 'e')
		return (0);
	if (file[len - 3] != 'b')
		return (0);
	if (file[len - 4] != '.')
		return (0);
	return (1);
}
