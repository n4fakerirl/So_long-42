/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:31:55 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/09 00:54:47 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	loose_screen(t_game *game, int init)
{
	int	img_width;
	int	img_height;
	int	x;
	int	y;

	img_width = 1280;
	img_height = 720;
	if (init == 0)
	{
		game->img_lose = mlx_xpm_file_to_image(game->mlx_ptr, "assets/lose.xpm",
				&img_width, &img_height);
		checkptr(game->img_lose, game);
		return ;
	}
	checkptr(game->img_lose, game);
	x = ((game->map_width * SPRITE_SIZE) - img_width) / 2;
	y = ((game->map_height * SPRITE_SIZE) - img_height) / 2;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_lose, x, y);
}

void	win_screen(t_game *game, int init)
{
	int	img_width;
	int	img_height;
	int	x;
	int	y;

	img_width = 1280;
	img_height = 720;
	if (init == 0)
	{
		game->img_win = mlx_xpm_file_to_image(game->mlx_ptr, "assets/win.xpm",
				&img_width, &img_height);
		checkptr(game->img_win, game);
		return ;
	}
	checkptr(game->img_win, game);
	x = ((game->map_width * SPRITE_SIZE) - img_width) / 2;
	y = ((game->map_height * SPRITE_SIZE) - img_height) / 2;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_win, x, y);
}

void	home_screen(t_game *game, int init)
{
	int	img_width;
	int	img_height;
	int	x;
	int	y;

	img_width = 1280;
	img_height = 720;
	game->img_menu = mlx_xpm_file_to_image(game->mlx_ptr, "assets/so_long.xpm",
			&img_width, &img_height);
	checkptr(game->img_menu, game);
	x = ((game->map_width * SPRITE_SIZE) - img_width) / 2;
	y = ((game->map_height * SPRITE_SIZE) - img_height) / 2;
	if (init == 0)
	{
		return ;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_menu, x, y);
}
