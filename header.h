/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:03 by naadou            #+#    #+#             */
/*   Updated: 2023/12/16 19:12:02 by naadou           ###   ########.fr       */
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
# include "Get-Next-Line/get_next_line.h"

typedef struct s_img_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	***img;
}				t_img_data;

typedef struct s_args {
	void		*mlx;
	void		*mlx_window;
	char		**map_arr;
	t_img_data	img_data;
}	t_args;

//windows
int		maps_height(char *map);
int		maps_width(char *map);
void	direction_movement(char c, t_args *data, int w, int h);
void	window_creation(char *map, t_args data);
//map
int		*starting_position(char **map_arr);
void	pixels(char *map, t_args data, int w, int h);
bool	parsing(char *map);

#endif