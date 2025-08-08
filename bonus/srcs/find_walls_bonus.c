/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:10:07 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/09 00:00:58 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	other_tiles(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] == '1'
			&& checkptr(wall->simple_wall, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->simple_wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] != '1'
			&& checkptr(wall->walls_noup, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_noup, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] == '1'
			&& checkptr(wall->walls_nodown, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_nodown, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			center_map(game, wall, x, y);
	}
	other_tiles2(game, wall, x, y);
}

void	last_row(t_game *game, t_walls *wall, int x, int y)
{
	if (y == (game->map_height - 1))
	{
		if (x != 0 && x != (game->map_width - 1))
		{
			if (game->map[y - 1][x] != '1')
			{
				if (checkptr(wall->two_walls_ud, game))
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						wall->two_walls_ud, x * SPRITE_SIZE, y * SPRITE_SIZE);
			}
			else if (checkptr(wall->wall_down, game))
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					wall->wall_down, x * SPRITE_SIZE, y * SPRITE_SIZE);
		}
	}
	else
	{
		if (checkptr(wall->full_wall, game) && game->map[y - 1][x] == '0'
			&& game->map[y + 1][x] == '0' && game->map[y][x + 1] == '0'
			&& game->map[y][x - 1] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->full_wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	other_tiles(game, wall, x, y);
}

void	columns2(t_game *game, t_walls *wall, int x, int y)
{
	if (y == (game->map_height - 1) && checkptr(wall->walls_corner3, game))
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			wall->walls_corner3, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (checkptr(wall->two_walls_lr, game) && y != 0 && game->map[y][x
		- 1] != '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			wall->two_walls_lr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (y != 0 && game->map[y][x - 1] == '1' && checkptr(wall->wall_right,
			game))
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->wall_right,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	columns(t_game *game, t_walls *wall, int x, int y)
{
	if (x == 0 && y != 0)
	{
		if (y == (game->map_height - 1) && checkptr(wall->walls_corner4, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner4, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->two_walls_lr, game) && game->map[y][x
			+ 1] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_lr, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (checkptr(wall->wall_left, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_left, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	if (x == (game->map_width - 1))
		columns2(game, wall, x, y);
	last_row(game, wall, x, y);
}

void	find_wall(t_game *game, t_walls *wall, int x, int y)
{
	if (y == 0)
	{
		if (x == 0 && checkptr(wall->walls_corner1, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner1, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (x == (game->map_width - 1) && checkptr(wall->walls_corner2,
				game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner2, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y + 1][x] != '1')
		{
			if (checkptr(wall->two_walls_ud, game))
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					wall->two_walls_ud, x * SPRITE_SIZE, y * SPRITE_SIZE);
		}
		else if (checkptr(wall->wall_up, game))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->wall_up,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	else
		columns(game, wall, x, y);
}
