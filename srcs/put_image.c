/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:07:20 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/06 17:05:26 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_tile(t_game *game, t_walls *wall, int i, int y)
{
	if (game->map[y][i] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_floor, i
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][i] == '1')
		find_wall(game, wall, i, y);
	else if (game->map[y][i] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collect,
			i * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][i] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player_down, i * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][i] == 'E')
	{
		if (game->collected == game->nb_collec)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit, i * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_floor, i * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	else if (game->map[y][i] == 'M')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_enemy, i
			* SPRITE_SIZE, y * SPRITE_SIZE);
}

void	draw_map(t_game *game, t_walls *wall)
{
	int	i;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		i = 0;
		while (game->map[y][i] != '\0')
		{
			find_tile(game, wall, i, y);
			i++;
		}
		y++;
	}
}

void	find_img_wall(t_walls *wall, t_game *game, int height, int width)
{
	wall->wall_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_down.xpm", &width, &height);
	wall->wall_up = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall_up.xpm",
			&width, &height);
	wall->wall_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_right.xpm", &width, &height);
	wall->wall_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_left.xpm", &width, &height);
	wall->walls_nodown = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/walls_nodown.xpm", &width, &height);
	wall->walls_noup = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/walls_noup.xpm", &width, &height);
	wall->walls_noright = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/walls_noright.xpm", &width, &height);
	wall->walls_noleft = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/walls_noleft.xpm", &width, &height);
	wall->walls_corner2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_corner2.xpm", &width, &height);
	wall->walls_corner3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_corner3.xpm", &width, &height);
	wall->walls_corner4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_corner4.xpm", &width, &height);
	wall->simple_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/simple_wall.xpm", &width, &height);
}

void	put_image_2(t_game *game, t_walls *wall, int height, int width)
{
	wall->two_walls_lr = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/two_walls_lr.xpm", &width, &height);
	wall->two_walls_ud = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/two_walls_ud.xpm", &width, &height);
	wall->walls_corner1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall_corner1.xpm", &width, &height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx_ptr, "assets/enemy.xpm",
			&width, &height);
}

void	put_image(t_game *game, t_walls *wall)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm",
			&width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/collect.xpm", &width, &height);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player_down.xpm", &width, &width);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player_up.xpm", &width, &width);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player_left.xpm", &width, &width);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player_right.xpm", &width, &width);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm",
			&width, &width);
	wall->full_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/full_wall.xpm", &width, &height);
	put_image_2(game, wall, height, width);
	find_img_wall(wall, game, height, width);
}
