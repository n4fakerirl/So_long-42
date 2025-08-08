/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:56:43 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/08 22:08:32 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	check_errors(t_game *game)
{
	cut_line(game);
	calculate_size(game);
	if ((game->map_width * 64) > 1920 || (game->map_height * 64) > 1080)
		return (ft_printf("Error\nMap is too big.\n"), 0);
	if (!check_pe(game))
		return (ft_printf("Error\nRequired : (ONLY) 1 player && 1 exit.\n"), 0);
	if (!check_borders(game))
		return (ft_printf("Error\nMap is not fully closed.\n"), 0);
	if (!check_items(game))
		return (ft_printf("Error\nNot enough collectibles to play.\n"), 0);
	if (!check_sq(game))
		return (ft_printf("Error\nMap must be a square.\n"), 0);
	if (!flood_fill(game))
		return (ft_printf("Error\nCan't access to collectibles/exit.\n"), 0);
	return (1);
}

int	files_err(t_game *game, char *file)
{
	int	fd;
	int	size;

	size = 0;
	game->map = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nEnter a valid file.\n"), -1);
	size = size_map(file);
	if (size == 0)
		return (ft_printf("Error\nFile is empty.\n"), -1);
	return (fd);
}

int	map_errors(t_game *game, char *file)
{
	int		size;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = files_err(game, file);
	if (fd == -1)
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
	if (!check_errors(game))
		return (0);
	return (1);
}
