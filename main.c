/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2024/01/29 16:04:53 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

t_data	initi(char *map)
{
	int		i;
	t_data	d;

	i = 0;
	d.map = ft_split(map, '\n');
	d.player_status = 1;
	d.enemy_status = (int *) malloc (sizeof(int) * enemy_count(d.map));
	while (i < enemy_count(d.map))
		d.enemy_status[i++] = 1;
	d.mov_counter = 0;
	d.mlx = mlx_init();
	d.img_d.img = (void ***) malloc (6 * sizeof (void **));
	i = 0;
	while (i < 4)
		d.img_d.img[i++] = (void **) malloc (1 * sizeof (void *));
	d.img_d.img[i++] = (void **) malloc (21 * sizeof (void *));
	d.img_d.img[i++] = (void **) malloc (14 * sizeof (void *));
	images_value(d.img_d.img, d, 64, 64);
	return (d);
}

int	main(int ac, char *av[])
{
	int		fd;
	char	*map;
	t_data	d;

	if (ac != 2 || ft_strncmp(".ber", &av[1][ft_strlen(av[1]) - 4], 4))
	{
		ft_putendl_fd("invalid argument", 2);
		return (1);
	}
	fd = open (av[1], O_RDONLY);
	map = get_next_line(fd);
	if (parsing(map) == 0)
	{
		ft_putendl_fd("Error", 2);
		free(map);
		return (1);
	}
	d = initi(map);
	window_creation(map, d);
}
