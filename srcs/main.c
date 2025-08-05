/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:50:26 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/05 21:57:15 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
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
	free(game);
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
	if (!map_errors(game, av[1]))
		return (free_game(game), 1);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, 1900, 1900, "SO LONG!");
	put_image(game, wall);
	draw_map(game, wall);
	mlx_loop(game->mlx_ptr);
	free_game(game);
	free(wall);
}
