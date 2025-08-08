/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:56:11 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/09 00:54:33 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	destroy_game(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_player_up)
		mlx_destroy_image(game->mlx_ptr, game->img_player_up);
	if (game->img_player_down)
		mlx_destroy_image(game->mlx_ptr, game->img_player_down);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx_ptr, game->img_player_left);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx_ptr, game->img_player_right);
	if (game->img_collect)
		mlx_destroy_image(game->mlx_ptr, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx_ptr, game->img_enemy);
	if (game->img_menu)
		mlx_destroy_image(game->mlx_ptr, game->img_menu);
}

void	destroy_walls2(t_game *game, t_walls *wall)
{
	if (wall->walls_nodown)
		mlx_destroy_image(game->mlx_ptr, wall->walls_nodown);
	if (wall->full_wall)
		mlx_destroy_image(game->mlx_ptr, wall->full_wall);
	if (wall->walls_corner1)
		mlx_destroy_image(game->mlx_ptr, wall->walls_corner1);
	if (wall->walls_corner2)
		mlx_destroy_image(game->mlx_ptr, wall->walls_corner2);
	if (wall->walls_corner3)
		mlx_destroy_image(game->mlx_ptr, wall->walls_corner3);
	if (wall->walls_corner4)
		mlx_destroy_image(game->mlx_ptr, wall->walls_corner4);
	if (wall->simple_wall)
		mlx_destroy_image(game->mlx_ptr, wall->simple_wall);
}

void	destroy_walls(t_game *game, t_walls *wall)
{
	if (wall->wall_up)
		mlx_destroy_image(game->mlx_ptr, wall->wall_up);
	if (wall->wall_down)
		mlx_destroy_image(game->mlx_ptr, wall->wall_down);
	if (wall->wall_right)
		mlx_destroy_image(game->mlx_ptr, wall->wall_right);
	if (wall->wall_left)
		mlx_destroy_image(game->mlx_ptr, wall->wall_left);
	if (wall->two_walls_ud)
		mlx_destroy_image(game->mlx_ptr, wall->two_walls_ud);
	if (wall->two_walls_lr)
		mlx_destroy_image(game->mlx_ptr, wall->two_walls_lr);
	if (wall->walls_noleft)
		mlx_destroy_image(game->mlx_ptr, wall->walls_noleft);
	if (wall->walls_noright)
		mlx_destroy_image(game->mlx_ptr, wall->walls_noright);
	if (wall->walls_noup)
		mlx_destroy_image(game->mlx_ptr, wall->walls_noup);
	destroy_walls2(game, wall);
}

void	clear_all(t_game *game, t_walls *wall)
{
	if (game->state == 1)
	{
		destroy_game(game);
		destroy_walls(game, wall);
		if (game->img_win)
			mlx_destroy_image(game->mlx_ptr, game->img_win);
		if (game->img_lose)
			mlx_destroy_image(game->mlx_ptr, game->img_lose);
	}
	else if (game->state == 0)
	{
		if (game->img_menu)
			mlx_destroy_image(game->mlx_ptr, game->img_menu);
	}
	else if (game->state == 2 || game->state == 3)
	{
		if (game->img_win)
			mlx_destroy_image(game->mlx_ptr, game->img_win);
		if (game->img_lose)
			mlx_destroy_image(game->mlx_ptr, game->img_lose);
		destroy_game(game);
		destroy_walls(game, wall);
	}
	free_map(game);
}
