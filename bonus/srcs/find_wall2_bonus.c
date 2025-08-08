/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:28:39 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/09 00:54:27 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	other_tiles4(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (checkptr(wall->walls_corner4, game) && game->map[y][x - 1] != '1'
			&& game->map[y][x + 1] == '1' && game->map[y - 1][x] == '1'
			&& game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner4, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->walls_corner3, game) && game->map[y][x
			- 1] == '1' && game->map[y][x + 1] != '1' && game->map[y
			- 1][x] == '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner3, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
}

void	other_tiles3(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (checkptr(wall->wall_up, game) && game->map[y][x - 1] == '1'
			&& game->map[y][x + 1] == '1' && game->map[y - 1][x] != '1'
			&& game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->wall_up,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->wall_right, game) && game->map[y][x - 1] == '1'
			&& game->map[y][x + 1] != '1' && game->map[y - 1][x] == '1'
			&& game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_right, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->wall_down, game) && game->map[y][x - 1] == '1'
			&& game->map[y][x + 1] == '1' && game->map[y - 1][x] == '1'
			&& game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_down, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->two_walls_lr, game) && game->map[y][x
			- 1] != '1' && game->map[y][x + 1] != '1' && game->map[y
			- 1][x] == '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_lr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	other_tiles4(game, wall, x, y);
}

void	center_map2(t_game *game, t_walls *wall, int x, int y)
{
	if (checkptr(wall->walls_noleft, game) && game->map[y][x - 1] == '1'
		&& game->map[y][x + 1] != '1' && game->map[y - 1][x] != '1'
		&& game->map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			wall->walls_noleft, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (checkptr(wall->wall_left, game) && game->map[y][x - 1] != '1'
		&& game->map[y][x + 1] == '1' && game->map[y - 1][x] == '1'
		&& game->map[y + 1][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->wall_left, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
}

void	other_tiles2(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (checkptr(wall->two_walls_ud, game) && game->map[y][x - 1] == '1'
			&& game->map[y][x + 1] == '1' && game->map[y - 1][x] != '1'
			&& game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_ud, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->walls_corner1, game) && game->map[y][x
			- 1] != '1' && game->map[y][x + 1] == '1' && game->map[y
			- 1][x] != '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner1, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->walls_noright, game) && game->map[y][x
			- 1] != '1' && game->map[y][x + 1] == '1' && game->map[y
			- 1][x] != '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_noright, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			center_map2(game, wall, x, y);
	}
	other_tiles3(game, wall, x, y);
}

void	center_map(t_game *game, t_walls *wall, int x, int y)
{
	if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1' && game->map[y
		- 1][x] != '1' && game->map[y + 1][x] != '1'
		&& checkptr(wall->full_wall, game))
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->full_wall, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][x - 1] == '1' && game->map[y][x + 1] != '1'
		&& game->map[y - 1][x] != '1' && game->map[y + 1][x] == '1'
		&& checkptr(wall->walls_corner2, game))
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			wall->walls_corner2, x * SPRITE_SIZE, y * SPRITE_SIZE);
}
