/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:16:19 by ocviller          #+#    #+#             */
/*   Updated: 2025/08/04 18:21:43 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

}			t_game;

// DELETE !
void		print_tab(char **tab);

// TRUE
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

#endif