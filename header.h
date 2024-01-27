/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:03 by naadou            #+#    #+#             */
/*   Updated: 2024/01/27 18:11:43 by naadou           ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	char	**map;
	t_img_d	img_d;
}	t_data;

typedef struct s_node
{
	int		*content;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

//windows
int		maps_height(char *map);
int		maps_width(char *map);
void	direction_movement(char c, t_data *data);
void	window_creation(char *map, t_data data);
// //movement
// void	up(t_data *data, void ***img, int r, int c);
// void	down(t_data *data, void ***img, int r, int c);
// void	left(t_data *data, void ***img, int r, int c);
// void	right(t_data *data, void ***img, int r, int c);
//map
int		*starting_position(char **map_arr);
int	pixels(t_data *data);
bool	parsing(char *map);
void	map_validity(char **hm_map, char **map, int *p, t_node *node);
//image-values
void	images_value(void ***img, t_data data);

// collectibles_check
int collectibles_check(char **map);

#endif