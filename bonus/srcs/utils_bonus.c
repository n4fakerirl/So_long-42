/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:01:08 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/15 13:05:34 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	checkptr(void *ptr, t_game *game)
{
	if (ptr == NULL)
	{
		mlx_loop_end(game->mlx_ptr);
		clear_all(game, game->wall);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		ft_printf("Error.\nSome assets are missing.\n");
		free(game->mlx_ptr);
		free(game->wall);
		free(game);
		exit(0);
	}
	return (1);
}

void	print_onscreen(t_game *game)
{
	char	*count;

	count = ft_itoa(game->move);
	if (!count)
		return ;
	mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF1493, count);
	free(count);
}

int	display_menu(t_game *game, int keycode)
{
	if (keycode == 65307)
		return (mlx_loop_end(game->mlx_ptr), 0);
	else if (keycode == 32)
	{
		game->state = 1;
		put_image(game, game->wall);
		draw_map(game, game->wall);
		return (1);
	}
	return (1);
}

int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}
