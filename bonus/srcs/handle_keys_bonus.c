/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:27:47 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/09 00:54:41 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	try_move_up(t_game *game, t_walls *wall)
{
	if (game->map[game->player_posy - 1][game->player_posx] != '1')
	{
		if (game->map[game->player_posy - 1][game->player_posx] == 'C')
			game->collected++;
		else if (game->map[game->player_posy - 1][game->player_posx] == 'E')
		{
			if (game->collected == game->nb_coll)
				return (game->state = 2, 1);
		}
		else if (game->map[game->player_posy - 1][game->player_posx] == 'M')
			return (game->state = 3, 0);
		if (game->map[game->player_posy][game->player_posx] != 'E')
			game->map[game->player_posy][game->player_posx] = '0';
		game->player_posy--;
		draw_map(game, wall);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player_up, game->player_posx * SPRITE_SIZE,
			game->player_posy * SPRITE_SIZE);
		game->move++;
		printf("Moves made : %d ^_^\n", game->move);
		print_onscreen(game);
	}
	game->state = 1;
	return (2);
}

int	try_move_down(t_game *game, t_walls *wall)
{
	if (game->map[game->player_posy + 1][game->player_posx] != '1')
	{
		if (game->map[game->player_posy + 1][game->player_posx] == 'C')
			game->collected++;
		else if (game->map[game->player_posy + 1][game->player_posx] == 'E')
		{
			if (game->collected == game->nb_coll)
				return (game->state = 2, 1);
		}
		else if (game->map[game->player_posy + 1][game->player_posx] == 'M')
			return (game->state = 3, 0);
		if (game->map[game->player_posy][game->player_posx] != 'E')
			game->map[game->player_posy][game->player_posx] = '0';
		game->player_posy++;
		draw_map(game, wall);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player_down, game->player_posx * SPRITE_SIZE,
			game->player_posy * SPRITE_SIZE);
		game->move++;
		printf("Moves made : %d ^_^\n", game->move);
		print_onscreen(game);
	}
	game->state = 1;
	return (2);
}

int	try_move_right(t_game *game, t_walls *wall)
{
	if (game->map[game->player_posy][game->player_posx + 1] != '1')
	{
		if (game->map[game->player_posy][game->player_posx + 1] == 'C')
			game->collected++;
		else if (game->map[game->player_posy][game->player_posx + 1] == 'E')
		{
			if (game->collected == game->nb_coll)
				return (game->state = 2, 1);
		}
		else if (game->map[game->player_posy][game->player_posx + 1] == 'M')
			return (game->state = 3, 0);
		if (game->map[game->player_posy][game->player_posx] != 'E')
			game->map[game->player_posy][game->player_posx] = '0';
		game->player_posx++;
		draw_map(game, wall);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player_right, game->player_posx * SPRITE_SIZE,
			game->player_posy * SPRITE_SIZE);
		game->move++;
		printf("Moves made : %d ^_^\n", game->move);
		print_onscreen(game);
	}
	game->state = 1;
	return (2);
}

int	try_move_left(t_game *game, t_walls *wall)
{
	if (game->map[game->player_posy][game->player_posx - 1] != '1')
	{
		if (game->map[game->player_posy][game->player_posx - 1] == 'C')
			game->collected++;
		else if (game->map[game->player_posy][game->player_posx - 1] == 'E')
		{
			if (game->collected == game->nb_coll)
				return (game->state = 2, 1);
		}
		else if (game->map[game->player_posy][game->player_posx - 1] == 'M')
			return (game->state = 3, 0);
		if (game->map[game->player_posy][game->player_posx] != 'E')
			game->map[game->player_posy][game->player_posx] = '0';
		game->player_posx--;
		draw_map(game, wall);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player_left, game->player_posx * SPRITE_SIZE,
			game->player_posy * SPRITE_SIZE);
		game->move++;
		printf("Moves made : %d ^_^\n", game->move);
		print_onscreen(game);
	}
	game->state = 1;
	return (2);
}

int	handle_keypress(int keycode, t_game *game)
{
	game->exit_code = 2;
	if (keycode == 65307)
		return (mlx_loop_end(game->mlx_ptr), 0);
	if (game->state == 0)
		display_menu(game, keycode);
	else if (game->state == 1)
	{
		if (keycode == 119 || keycode == 65362)
			game->exit_code = try_move_up(game, game->wall);
		else if (keycode == 97 || keycode == 65361)
			game->exit_code = try_move_left(game, game->wall);
		else if (keycode == 115 || keycode == 65364)
			game->exit_code = try_move_down(game, game->wall);
		else if (keycode == 100 || keycode == 65363)
			game->exit_code = try_move_right(game, game->wall);
	}
	if (game->exit_code == 0)
		loose_screen(game, 1);
	if (game->exit_code == 1)
		win_screen(game, 1);
	return (0);
}
