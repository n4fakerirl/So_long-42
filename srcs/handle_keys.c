/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:27:47 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/07 17:31:42 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_onscreen(t_game *game)
{
	char	*count;

	count = ft_itoa(game->move);
	if (!count)
		return ;
	mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF1493, count);
	free(count);
}

int	try_move_up(t_game *game, t_walls *wall)
{
	if (game->map[game->player_posy - 1][game->player_posx] != '1')
	{
		if (game->map[game->player_posy - 1][game->player_posx] == 'C')
			game->collected++;
		else if (game->map[game->player_posy - 1][game->player_posx] == 'E')
		{
			if (game->collected == game->nb_collec)
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
			if (game->collected == game->nb_collec)
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
			if (game->collected == game->nb_collec)
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
			if (game->collected == game->nb_collec)
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

int	display_menu(t_game *game, int keycode)
{
	if (keycode == 65307)
		return (mlx_loop_end(game->mlx_ptr), 0);
	else if (keycode == 32)
	{
		game->state = 1;
		put_image(game, game->wall);
		draw_map(game, game->wall);
		return (0);
	}
	return (1);
}

int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	exit_code;

	exit_code = 2;
	if (keycode == 65307)
		return (mlx_loop_end(game->mlx_ptr), 0);
	if (game->state == 0)
		display_menu(game, keycode);
	else if (game->state == 1)
	{
		if (keycode == 119 || keycode == 65362) // HAUT
			exit_code = try_move_up(game, game->wall);
		else if (keycode == 97 || keycode == 65361) // GAUCHE
			exit_code = try_move_left(game, game->wall);
		else if (keycode == 115 || keycode == 65364) // BAS
			exit_code = try_move_down(game, game->wall);
		else if (keycode == 100 || keycode == 65363) // DROITE
			exit_code = try_move_right(game, game->wall);
	}
	if (exit_code == 0)
		loose_screen(game);
	if (exit_code == 1)
		win_screen(game);
	return (0);
}
