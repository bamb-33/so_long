/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 14:06:18 by naadou           ###   ########.fr       */
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
	if (!d.map)
		free_previous(&d, map, 0);
	d.player_status = 1;
	d.enemy_status = (int *) malloc (sizeof(int) * enemy_count(d.map));
	if (!d.enemy_status)
		free_previous(&d, map, 1);
	while (i < enemy_count(d.map))
		d.enemy_status[i++] = 1;
	d.mov_counter = 0;
	d.mlx = mlx_init();
	if (!d.mlx)
		free_previous(&d, map, 2);
	images_value(map, &d, 64, 64);
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
	if (fd == -1)
		return (1);
	map = get_next_line(fd);
	if (!map)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	d = initi(map);
	parsing(map);
	window_creation(&d);
}
