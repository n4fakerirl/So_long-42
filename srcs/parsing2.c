/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:05:59 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/04 16:24:15 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_p(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_posy = y;
				game->player_posx = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	fill(char **tab, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_width)
		return ;
	if (tab[y][x] == 'X' || (tab[y][x] != 'P' && tab[y][x] != 'C'
			&& tab[y][x] != 'E' && tab[y][x] != '0'))
		return ;
	tab[y][x] = 'X';
	fill(tab, game, x + 1, y);
	fill(tab, game, x - 1, y);
	fill(tab, game, x, y + 1);
	fill(tab, game, x, y - 1);
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	flood_fill(t_game *game)
{
	char	**copy;
	int		i;
	int		y;

	copy = copy_map(game);
	find_p(game);
	fill(copy, game, game->player_posx, game->player_posy);
	y = 0;
	while (copy[y])
	{
		i = 0;
		while (copy[y][i])
		{
			if (copy[y][i] != '1' && copy[y][i] != 'X')
				return (free(copy), 0);
			i++;
		}
		y++;
	}
	free(copy);
	return (1);
}
