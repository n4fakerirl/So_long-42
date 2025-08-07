/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:56:11 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/07 15:34:08 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_walls(t_walls *wall)
{
	if (!wall)
		return ;
	free(wall->wall_up);
	free(wall->wall_down);
	free(wall->wall_right);
	free(wall->wall_left);
	free(wall->two_walls_ud);
	free(wall->two_walls_lr);
	free(wall->walls_noleft);
	free(wall->walls_noright);
	free(wall->walls_noup);
	free(wall->walls_nodown);
	free(wall->full_wall);
	free(wall->walls_corner1);
	free(wall->walls_corner2);
	free(wall->walls_corner3);
	free(wall->walls_corner4);
	free(wall->simple_wall);
	free(wall);
}

void	free_game_set(t_game *game)
{
	free_map(game);
	free(game->img_floor);
	free(game->img_player_up);
	free(game->img_player_down);
	free(game->img_player_left);
	free(game->img_player_right);
	free(game->img_collect);
	free(game->img_exit);
	free(game->img_enemy);
}

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
	mlx_destroy_image(game->mlx_ptr, game->wall);
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
    free_game_set(game);
    free_walls(wall);
    free(game->wall);
    mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    mlx_destroy_display(game->mlx_ptr);
    free(game);
    free(wall);
    printf("TEST\n");
    exit(0);
    printf("TEST\n");
}
