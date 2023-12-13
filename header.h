/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:03 by naadou            #+#    #+#             */
/*   Updated: 2023/12/13 20:19:15 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_args {
	void	*mlx;
	void	*mlx_window;
	void	*img;
} t_args ;

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>


size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int len_read);
char	*get_next_line(int fd);

int	maps_height(char *map);
int	maps_width(char *map);
void	window_creation(int w, int h, t_args data);

#endif