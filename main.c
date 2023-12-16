/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2023/12/16 21:45:14 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*map;
	char	**map_arr;
	t_args	data;

	fd = open ("text.ber", O_RDONLY);
	i = 0;
	map = get_next_line(fd);
	data.map_arr = ft_split(map, '\n');
	for (int j = 0; data.map_arr[j] ; j++)
		printf("%s\n", data.map_arr[j]);
	if (parsing(map) == 0)
	{
		printf("INVALID MAP\n");
		return (0);
	}
	data.mlx = mlx_init();
	data.img_data.img = (void ***) malloc (maps_height(map) * sizeof (void **));
	while (i < maps_height(map))
	{
		data.img_data.img[i] = (void **) malloc (maps_width(map) * sizeof (void *));
		i++;
	}
	window_creation(map, data);
}
