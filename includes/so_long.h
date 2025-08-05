/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:16:19 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/05 21:29:38 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
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
	int		nb_collec;
	int		collected;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}			t_game;

typedef struct s_walls
{
	void	*wall_up;
	void	*wall_down;
	void	*wall_right;
	void	*wall_left;
	void	*two_walls_ud;
	void	*two_walls_lr;
	void	*walls_noleft;
	void	*walls_noright;
	void	*walls_noup;
	void	*walls_nodown;
	void	*full_wall;
	void	*walls_corner1;
	void	*walls_corner2;
	void	*walls_corner3;
	void	*walls_corner4;
	void	*simple_wall;
}			t_walls;

int			check_errors(t_game *game);
void		free_game(t_game *game);
int			check_pe(t_game *game);
int			check_items(t_game *game);
int			map_errors(t_game *game, char *file);
void		find_p(t_game *game);
void		fill(char **tab, t_game *game, int x, int y);
int			flood_fill(t_game *game);
char		**copy_map(t_game *game);
void		calculate_size(t_game *game);
void		cut_line(t_game *game);
int			size_map(char *file);
int			check_borders(t_game *game);
int			check_sq(t_game *game);
void		put_image(t_game *game, t_walls *wall);
void		find_wall(t_game *game, t_walls *wall, int x, int y);
void		draw_map(t_game *game, t_walls *wall);
void		other_tiles3(t_game *game, t_walls *wall, int x, int y);

#endif