/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:50:26 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/15 09:19:34 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map != NULL)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		game->map[i] = NULL;
		free(game->map);
	}
}

void	end_game(t_game *game)
{
	clear_all(game);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_printf("Error\nUsage : ./so_long maps/map.ber.\n"), 1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	if (!map_errors(game, av[1]))
		return (free_map(game), free(game), 1);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (free_map(game), free(game), 1);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_width * SPRITE_SIZE,
			game->map_height * SPRITE_SIZE, "SO LONG!");
	if (!game->mlx_win)
		return (free_map(game), free(game), 1);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, handle_close, game);
	put_image(game);
	draw_map(game);
	mlx_loop(game->mlx_ptr);
	end_game(game);
}
