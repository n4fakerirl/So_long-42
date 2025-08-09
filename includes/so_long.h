/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:16:19 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/10 00:22:57 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SPRITE_SIZE 64

typedef struct s_game
{
	char	**map;
	int		map_height;
	int		map_width;
	int		player_posx;
	int		player_posy;
	int		nb_coll;
	int		collected;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	void	*img_wall;
	int		move;
	int		fd;
}			t_game;

void		clear_all(t_game *game);
void		free_map(t_game *game);
int			check_errors(t_game *game);
int			check_pe(t_game *game);
int			check_items(t_game *game);
int			map_errors(t_game *game, char *file);
void		find_p(t_game *game);
void		fill(char **tab, t_game *game, int x, int y);
int			flood_fill(t_game *game);
char		**copy_map(t_game *game);
void		calculate_size(t_game *game);
void		cut_line(t_game *game);
int			size_map(int fd);
int			check_borders(t_game *game);
int			check_sq(t_game *game);
void		put_image(t_game *game);
void		draw_map(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			try_move_up(t_game *game);
int			handle_close(t_game *game);
int			checkptr(void *ptr, t_game *game);

#endif