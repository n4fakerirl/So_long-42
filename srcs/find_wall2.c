/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:28:39 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/05 21:29:26 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	other_tiles4(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (game->map[y][x - 1] != '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner4, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] == '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->walls_corner3, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
}

void	other_tiles3(t_game *game, t_walls *wall, int x, int y)
{
	if (y != 0 && y != (game->map_height - 1) && x != 0 && x != (game->map_width
			- 1))
	{
		if (game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] != '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, wall->wall_up,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] == '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_right, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] != '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->wall_down, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (game->map[y][x - 1] != '1' && game->map[y][x + 1] != '1'
			&& game->map[y - 1][x] == '1' && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				wall->two_walls_lr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	other_tiles4(game, wall, x, y);
}
