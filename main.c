/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2024/01/21 20:33:45 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	int		i;
	int		fd;
	char	*map;
	t_data	d;

	if (ac != 2)
	{
		ft_putendl_fd("invalid number of arguments", 2);
		return (1);
	}
	i = 0;
	fd = open (av[1], O_RDONLY);
	map = get_next_line(fd);
	d.map = ft_split(map, '\n');
	if (parsing(map) == 0)
	{
		printf("Error\n");
		return (0);
	}
	d.mlx = mlx_init();
	d.img_d.img = (void ***) malloc (maps_height(map) * sizeof (void **));
	while (i < maps_height(map))
		d.img_d.img[i++] = (void **) malloc (maps_width(map) * sizeof (void *));
	window_creation(map, d);
}
