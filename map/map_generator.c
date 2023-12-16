/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2023/12/16 21:04:13 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	*starting_position(char **map_arr)
{
	int	r;
	int	c;
	int	*arr;

	r = 0;
	arr = (int *) malloc (2 * sizeof(int));
	while (map_arr[r])
	{
		c = 0;
		while (map_arr[r][c])
		{
			if (map_arr[r][c] == 'P')
			{
				arr[0] = r * 50;
				arr[1] = c * 35;
				return (arr);
			}
			c++;
		}
		r++;
	}
	return (0);
}

void	pixels(char *map, t_args data, int w, int h)
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
			data.img_data.img[x][j] = mlx_xpm_file_to_image(data.mlx, "map_blocs/dirt.xpm", &w, &h);
		else if (map[i] == '1')
			data.img_data.img[x][j] = mlx_xpm_file_to_image(data.mlx, "map_blocs/obsedian.xpm", &w, &h);
		else if (map[i] == 'C')
			data.img_data.img[x][j] = mlx_xpm_file_to_image(data.mlx, "map_blocs/apple.xpm", &w, &h);
		else if (map[i] == 'E')
			data.img_data.img[x][j] = mlx_xpm_file_to_image(data.mlx, "map_blocs/dirt.xpm", &w, &h);
		else if (map[i] == 'P')
			data.img_data.img[x][j] = mlx_xpm_file_to_image(data.mlx, "map_blocs/eye_of_ender.xpm", &w, &h);
		if (map[i] == '\n')
		{
			j = 0;
			h_v2 += 50;
			x++;
		}
		else
		{
			mlx_put_image_to_window(data.mlx, data.mlx_window, data.img_data.img[x][j], (w * j), h_v2);
			j++;
		}
		i++;
	}
}
