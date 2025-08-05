/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:10:07 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/05 21:28:36 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	other_tiles2(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_ud, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner1, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_noright, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] == '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_noleft, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_left, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	other_tiles3(game, wall, x, y);
}

void	other_tiles(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->simple_wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_noup, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_nodown, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->full_wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] == '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner2, x * SPRITE_SIZE, y * SPRITE_SIZE);
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
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					wall->two_walls_ud, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					wall->wall_down, x * SPRITE_SIZE, y * SPRITE_SIZE);
		}
	}
	else
	{
		if (game->map[y - 1][x] == '0' && game->map[y + 1][x] == '0'
			&& game->map[y][x + 1] == '0' && game->map[y][x - 1] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->full_wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	other_tiles(game, wall, x, y);
}

void	columns(t_game *game, t_walls *wall, int x, int y)
{
	if (x == 0 && y != 0)
	{
		if (y == (game->map_height - 1))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner4, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x + 1] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_lr, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_left, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	if (x == (game->map_width - 1))
	{
		if (y == (game->map_height - 1))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner3, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (y != 0 && game->map[y][x - 1] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_lr, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (y != 0 && game->map[y][x - 1] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_right, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	last_row(game, wall, x, y);
}

void	find_wall(t_game *game, t_walls *wall, int x, int y)
{
	if (y == 0)
	{
		if (x == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner1, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (x == (game->map_width - 1))
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner2, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_ud, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->wall_up,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	else
		columns(game, wall, x, y);
}
