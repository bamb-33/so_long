/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:03 by naadou            #+#    #+#             */
/*   Updated: 2024/01/21 20:22:41 by naadou           ###   ########.fr       */
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

//windows
int		maps_height(char *map);
int		maps_width(char *map);
void	direction_movement(char c, t_data *data, int w, int h);
void	window_creation(char *map, t_data data);
//map
int		*starting_position(char **map_arr);
void	pixels(char *map, t_data data, int w, int h);
bool	parsing(char *map);

// collectibles_check
int collectibles_check(char **map);

#endif