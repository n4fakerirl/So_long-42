/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:50:26 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/08 21:56:52 by ocviller         ###   ########.fr       */
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

void	init_gamewall(t_game *game, t_walls *wall)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(wall, 0, sizeof(t_walls));
}

void	end_game(t_game *game, t_walls *wall)
{
	clear_all(game, wall);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(wall);
	free(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	*game;
	t_walls	*wall;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	wall = malloc(sizeof(t_walls));
	if (!wall || !game)
		return (1);
	init_gamewall(game, wall);
	if (!map_errors(game, av[1]))
		return (free_map(game), free(game), free(wall), 1);
	game->wall = wall;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (free_map(game), free(game), free(wall), 1);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_width * SPRITE_SIZE,
			game->map_height * SPRITE_SIZE, "SO LONG!");
	if (!game->mlx_win)
		return (free_map(game), free(game), free(wall), 1);
	mlx_key_hook(game->mlx_win, handle_keypress, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, handle_close, game);
	home_screen(game, 1);
	mlx_loop(game->mlx_ptr);
	end_game(game, wall);
}
