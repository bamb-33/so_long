/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2024/01/21 20:16:21 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	*starting_position(char **map_arr)
{
	int	w;
	int	h;
	int	*arr;

	w = 0;
	arr = (int *) malloc (2 * sizeof(int));
	while (map_arr[w])
	{
		h = 0;
		while (map_arr[w][h])
		{
			if (map_arr[w][h] == 'P')
			{
				arr[0] = w;
				arr[1] = h;
				return (arr);
			}
			h++;
		}
		w++;
	}
	return (0);
}

void	pixels(char *map, t_data data, int w, int h)
{
	int	i;
	int	j;
	int	x;
	int	h_v2;

	i = 0;
	j = 0;
	x = 0;
	h_v2 = 0;
	while (map[i])
	{
		if (map[i] == '0')
			data.img_d.img[x][j] = mlx_xpm_file_to_image(data.mlx, "blocs/0.xpm", &w, &h);
		else if (map[i] == '1')
			data.img_d.img[x][j] = mlx_xpm_file_to_image(data.mlx, "blocs/1.xpm", &w, &h);
		else if (map[i] == 'C')
			data.img_d.img[x][j] = mlx_xpm_file_to_image(data.mlx, "blocs/C.xpm", &w, &h);
		else if (map[i] == 'E')
			data.img_d.img[x][j] = mlx_xpm_file_to_image(data.mlx, "blocs/E.xpm", &w, &h);
		else if (map[i] == 'P')
			data.img_d.img[x][j] = mlx_xpm_file_to_image(data.mlx, "blocs/P.xpm", &w, &h);
		if (map[i] == '\n')
		{
			j = 0;
			h_v2 += 64;
			x++;
		}
		else
		{
			mlx_put_image_to_window(data.mlx, data.mlx_window, data.img_d.img[x][j], (w * j), h_v2);
			j++;
		}
		i++;
	}
}
