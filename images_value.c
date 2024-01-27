/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:28:24 by naadou            #+#    #+#             */
/*   Updated: 2024/01/27 21:44:41 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	images_value(void ***img, t_data data)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	w = 64;
	h = 64;
	img[0][0] = mlx_xpm_file_to_image(data.mlx, "blocs/0.xpm", &w, &h);
	img[1][0] = mlx_xpm_file_to_image(data.mlx, "blocs/1.xpm", &w, &h);
	img[2][0] = mlx_xpm_file_to_image(data.mlx, "blocs/C.xpm", &w, &h);
	img[3][0] = mlx_xpm_file_to_image(data.mlx, "blocs/E.xpm", &w, &h);
	img[4][0] = mlx_xpm_file_to_image(data.mlx, "blocs/P.xpm", &w, &h);

	img[5][0] = mlx_xpm_file_to_image(data.mlx, "sprite/G/0.xpm", &w, &h);
	img[5][1] = mlx_xpm_file_to_image(data.mlx, "sprite/G/1.xpm", &w, &h);
	img[5][2] = mlx_xpm_file_to_image(data.mlx, "sprite/G/2.xpm", &w, &h);
	img[5][3] = mlx_xpm_file_to_image(data.mlx, "sprite/G/3.xpm", &w, &h);
	img[5][4] = mlx_xpm_file_to_image(data.mlx, "sprite/G/4.xpm", &w, &h);
	img[5][5] = mlx_xpm_file_to_image(data.mlx, "sprite/G/5.xpm", &w, &h);
	img[5][6] = mlx_xpm_file_to_image(data.mlx, "sprite/G/6.xpm", &w, &h);
}