/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:11:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/27 16:09:15 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "header.h"

// void	up(t_data *data, void ***img, int r, int c)
// {
// 	int	w;
// 	int	h;

// 	w = 64;
// 	h = 64;
// 	if (data->map[r - 1][c] == 'C')
// 		data->map[r - 1][c] = '0';
// 	if (data->map[r - 1][c] == 'G')
// 		you_lost();
// 	if (data->map[r - 1][c] == 'E' && collectibles_check(data->map))
// 	{
// 		// you_won();
// 		exit(0);
// 	}
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// 	r -= 1;
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// }

// void	down(t_data *data, void ***img, int r, int c)
// {
// 	int	w;
// 	int	h;

// 	w = 64;
// 	h = 64;
// 	if (data->map[r + 1][c] == 'C')
// 		data->map[r + 1][c] = '0';
// 	if (data->map[r + 1][c] == 'G')
// 		you_lost();
// 	if (data->map[r + 1][c] == 'E' && collectibles_check(data->map))
// 	{
// 		// you_won()
// 		exit(0);
// 	}
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// 	r += 1;
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// }

// void	left(t_data *data, void ***img, int r, int c)
// {
// 	int	w;
// 	int	h;

// 	w = 64;
// 	h = 64;
// 	if (data->map[r][c + 1] == 'C')
// 		data->map[r][c + 1] = '0';
// 	if (data->map[r][c + 1] == 'G')
// 		you_lost();
// 	if (data->map[r][c + 1] == 'E' && collectibles_check(data->map))
// 	{
// 		// you_won()
// 		exit(0);
// 	}
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// 	c += 1;
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// }

// void	right(t_data *data, void ***img, int r, int c)
// {
// 	int	w;
// 	int	h;

// 	w = 64;
// 	h = 64;
// 	if (data->map[r][c - 1] == 'C')
// 		data->map[r][c - 1] = '0';
// 	if (data->map[r][c - 1] == 'G')
// 		you_lost();
// 	if (data->map[r][c - 1] == 'E' && collectibles_check(data->map))
// 	{
// 		// you_won()
// 		exit(0);
// 	}
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// 	c -= 1;
// 	mlx_destroy_image(data->mlx, img[r][c]);
// 	img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
// 	mlx_put_image_to_window(data->mlx, data->mlx_window, img[r][c], c * 64, r * 64);
// }