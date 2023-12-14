/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2023/12/14 12:27:11 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*map;
	t_args	data;

	data.mlx = mlx_init();
	fd = open ("text.ber", O_RDONLY);
	map = get_next_line(fd);
	window_creation(map, data);
	printf("here\n");
}