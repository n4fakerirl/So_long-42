/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:50:26 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/04 18:25:46 by ocviller         ###   ########.fr       */
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
	void *img;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (!map_errors(game, av[1]))
		return (free_game(game), 1);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, 900, 1200, "SO LONG!");
	img = mlx_xpm_file_to_image(game->mlx_ptr, "../assets/floor.xpm", 100, 100);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, 300, 300);
	mlx_loop(game->mlx_ptr);
}
