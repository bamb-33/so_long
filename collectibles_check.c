/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:20:50 by naadou            #+#    #+#             */
/*   Updated: 2024/01/28 19:19:11 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	collectibles_check(t_data *d)
{
	int			i;
	int			j;
	void		***img;
	static int	flag;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j++] == 'C')
				return (0);
		}
		i++;
	}
	i = 64;
	if (flag == 0)
	{
		img = d->img_d.img;
		mlx_destroy_image(d->mlx, img[3][0]);
		img[3][0] = mlx_xpm_file_to_image(d->mlx, "blocs/E1.xpm", &i, &i);
		flag = 1;
	}
	return (1);
}
