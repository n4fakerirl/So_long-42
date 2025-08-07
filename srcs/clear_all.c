/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:56:11 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/07 16:42:44 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void destroy_game(t_game *game)
{
    mlx_destroy_image(game->mlx_ptr, game->img_floor);
    mlx_destroy_image(game->mlx_ptr, game->img_player_up);
	mlx_destroy_image(game->mlx_ptr, game->img_player_down);
	mlx_destroy_image(game->mlx_ptr, game->img_player_left);
	mlx_destroy_image(game->mlx_ptr, game->img_player_right);
	mlx_destroy_image(game->mlx_ptr, game->img_collect);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_enemy);
}

void destroy_walls(t_game *game, t_walls *wall)
{
    mlx_destroy_image(game->mlx_ptr, wall->wall_up);
	mlx_destroy_image(game->mlx_ptr, wall->wall_down);
	mlx_destroy_image(game->mlx_ptr, wall->wall_right);
	mlx_destroy_image(game->mlx_ptr, wall->wall_left);
	mlx_destroy_image(game->mlx_ptr, wall->two_walls_ud);
	mlx_destroy_image(game->mlx_ptr, wall->two_walls_lr);
	mlx_destroy_image(game->mlx_ptr, wall->walls_noleft);
	mlx_destroy_image(game->mlx_ptr, wall->walls_noright);
	mlx_destroy_image(game->mlx_ptr, wall->walls_noup);
	mlx_destroy_image(game->mlx_ptr, wall->walls_nodown);
	mlx_destroy_image(game->mlx_ptr, wall->full_wall);
	mlx_destroy_image(game->mlx_ptr, wall->walls_corner1);
	mlx_destroy_image(game->mlx_ptr, wall->walls_corner2);
	mlx_destroy_image(game->mlx_ptr, wall->walls_corner3);
	mlx_destroy_image(game->mlx_ptr, wall->walls_corner4);
	mlx_destroy_image(game->mlx_ptr, wall->simple_wall);
}

void clear_all(t_game *game, t_walls *wall)
{
    destroy_game(game);
    destroy_walls(game, wall);
    free(game->wall);
    free_map(game);
}
