/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:27:11 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/04 18:04:40 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	calculate_size(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (game->map[0][i])
		i++;
	game->map_width = i;
	while (game->map[y])
		y++;
	game->map_height = y;
}

int	size_map(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	check_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_sq(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (game->map[i])
	{
		len = (int)ft_strlen(game->map[i]);
		if (len != game->map_width)
			return (0);
		i++;
	}
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
	game->nb_collec = c;
	return (1);
}
