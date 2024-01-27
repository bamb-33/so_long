/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2024/01/27 18:11:40 by naadou           ###   ########.fr       */
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
	d.img_d.img = (void ***) malloc (6 * sizeof (void **));
	while (i < 5)
		d.img_d.img[i++] = (void **) malloc (1 * sizeof (void *));
	d.img_d.img[i++] = (void **) malloc (7 * sizeof (void *));
	images_value(d.img_d.img, d);
	window_creation(map, d);
}
