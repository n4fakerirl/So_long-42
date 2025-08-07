/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:50:26 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/07 15:32:10 by ocviller         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	*game;
	t_walls	*wall;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	wall = malloc(sizeof(t_walls));
	if (!wall)
		return (1);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	wall = malloc(sizeof(t_walls));
	ft_memset(wall, 0, sizeof(t_walls));
	if (!map_errors(game, av[1]))
		return (free_map(game), free(game), 1);
	game->wall = wall;
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_width * SPRITE_SIZE, game->map_height * SPRITE_SIZE, "SO LONG!");
	game->state = 0;
	game->move = 0;
	game->collected = 0;
	mlx_key_hook(game->mlx_win, handle_keypress, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, handle_close, game);
	home_screen(game);
	mlx_loop(game->mlx_ptr);
	clear_all(game, wall);
}
