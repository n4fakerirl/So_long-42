/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:56:43 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/04 16:21:11 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_pe(t_game *game)
{
	int	i;
	int	y;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (game->map[i])
	{
		y = 0;
		while (game->map[i][y])
		{
			if (game->map[i][y] == 'P')
				p++;
			else if (game->map[i][y] == 'E')
				e++;
			y++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		return (0);
	return (1);
}

int	check_items(t_game *game)
{
	int	i;
	int	y;
	int	c;

	i = 0;
	c = 0;
	while (game->map[i])
	{
		y = 0;
		while (game->map[i][y])
		{
			if (game->map[i][y] == 'C')
				c++;
			y++;
		}
		i++;
	}
	if (c < 1)
		return (0);
	return (1);
}

void	cut_line(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	while (game->map[y])
	{
		i = 0;
		while (game->map[y][i])
		{
			if (game->map[y][i] == '\n')
				game->map[y][i] = '\0';
			i++;
		}
		y++;
	}
}

int	map_errors(t_game *game, char *file)
{
	int		size;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	size = size_map(file);
	game->map = malloc(sizeof(char *) * (size + 1));
	if (!game->map)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	cut_line(game);
	calculate_size(game);
	if (!flood_fill(game))
		return (0);
	return (1);
}
