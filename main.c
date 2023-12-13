/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2023/12/13 20:21:34 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*map;
	t_args	data;

	data.mlx = mlx_init();
	fd = open ("text.ber", O_RDONLY);
	map = get_next_line(fd);
	window_creation(maps_width(map) * 50, maps_height(map) * 100, data);
	printf("here\n");
}