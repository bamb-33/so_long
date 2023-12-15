/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2023/12/15 16:11:17 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pixels(char *map, t_args data)
{
	int	i;
	int	j;
	int	w;
	int	h;
	int	h_v2;

	i = 0;
	j = 0;
	w = 35;
	h = 50;
	h_v2 = 0;
	while (map[i])
	{
		if (map[i] == '0')
			data.img_data.img = mlx_xpm_file_to_image(data.mlx, "map_blocs/dirt.xpm", &w, &h);
		else if (map[i] == '1')
			data.img_data.img = mlx_xpm_file_to_image(data.mlx, "map_blocs/obsedian.xpm", &w, &h);
		else if (map[i] == 'C')
			data.img_data.img = mlx_xpm_file_to_image(data.mlx, "map_blocs/apple.xpm", &w, &h);
		else if (map[i] == 'E')
			data.img_data.img = mlx_xpm_file_to_image(data.mlx, "map_blocs/dirt.xpm", &w, &h);
		else if (map[i] == 'P')
			data.img_data.img = mlx_xpm_file_to_image(data.mlx, "map_blocs/dirt.xpm", &w, &h);
		if (map[i] == '\n')
		{
			j = 0;
			h_v2 += 50;
		}
		else
		{
			mlx_put_image_to_window(data.mlx, data.mlx_window, data.img_data.img, (w * j), h_v2);
			j++;
		}
		printf("%d ----- %d\n", w * j, h_v2);
		i++;
	}
}
