/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:03 by naadou            #+#    #+#             */
/*   Updated: 2024/01/30 13:11:10 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_img_d
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	***img;
}				t_img_d;

typedef struct s_free
{
	int	*i_add;
	int	*j_add;
	int	**r_l_add;
	int	*k_add;
}				t_free;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	char	**map;
	int		mov_counter;
	int		player_status;
	int		*enemy_status;
	t_img_d	img_d;
	t_free	to_free_in_the_end;
}	t_data;

typedef struct s_node
{
	int				*content;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

//windows
int		maps_height(char *map);
int		maps_width(char *map);
void	window_creation(char *map, t_data data);
//movement
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
//map
bool	parsing(char *map);
void	map_validity(char **hm_map, char **map, int *p, t_node *node);
int		valid_rout(t_node *node, char **map, char **hm_map, int *p);
bool	path_check(char **map);
//image-values
void	images_value(t_data *d, int w, int h);

// collectibles_check
int		collectibles_check(t_data *d);
//map_generator
int		*starting_position(char **map_arr);
int		enemy_count(char **map);
int		pixels(t_data *data);
int		get_enemy_index(char **map, int w, int h);

//player_sprite
void	player_sprites(void ***img, t_data *d, int w, int h);
//enemy_sprite
void	enemy_sprites(void ***img, t_data *d, int w, int h);
//utils
void	save_variables(t_data *d, int *i, int *j, int **r_l);
//free
void	free_all(t_data *d, int flag);
void	free_two_d_array(char **strs);

#endif