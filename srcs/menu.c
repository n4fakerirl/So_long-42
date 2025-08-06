/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:31:55 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/06 19:14:57 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	loose_screen(t_game *game, int keycode)
{
	int		img_width;
	int		img_height;
	void	*img;
	int		x;
	int		y;

	img_width = 1280;
	img_height = 720;
	img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/lose.xpm", &img_width,
			&img_height);
	x = ((game->map_width * SPRITE_SIZE) - img_width) / 2;
	y = ((game->map_height * SPRITE_SIZE) - img_height) / 2;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, x, y);
	if (keycode == 65307)
		exit(0);
}

void	win_screen(t_game *game, int keycode)
{
	int		img_width;
	int		img_height;
	void	*img;
	int		x;
	int		y;

	img_width = 1280;
	img_height = 720;
	img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/win.xpm", &img_width,
			&img_height);
	x = ((game->map_width * SPRITE_SIZE) - img_width) / 2;
	y = ((game->map_height * SPRITE_SIZE) - img_height) / 2;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, x, y);
	if (keycode == 65307)
		exit(0);
}
