/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:03 by naadou            #+#    #+#             */
/*   Updated: 2023/12/15 15:48:24 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <string.h>

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_args {
	void		*mlx;
	void		*mlx_window;
	t_img_data	img_data;
}	t_args;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int len_read);
char	*get_next_line(int fd);

int		maps_height(char *map);
int		maps_width(char *map);
void	window_creation(char *map, t_args data);

void	pixels(char *map, t_args data);

#endif