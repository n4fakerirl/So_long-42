/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:07:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/15 12:56:40 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_tile(t_game *game, int i, int y)
{
	if (checkptr(game->img_floor, game) && game->map[y][i] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_floor, i
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (checkptr(game->img_wall, game) && game->map[y][i] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_wall, i
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (checkptr(game->img_collect, game) && game->map[y][i] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collect,
			i * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (checkptr(game->img_player, game) && game->map[y][i] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player,
			i * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][i] == 'E')
	{
		if (checkptr(game->img_exit, game) && game->collected == game->nb_coll)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit, i * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(game->img_floor, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_floor, i * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	else
		return ;
}

void	draw_map(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (game->map[y] != NULL)
	{
		i = 0;
		while (game->map[y][i] != '\0')
		{
			find_tile(game, i, y);
			i++;
		}
		y++;
	}
}

void	put_image(t_game *game)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm",
			&width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/collect.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player_down.xpm", &width, &width);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm",
			&width, &width);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/full_wall.xpm", &width, &height);
}
