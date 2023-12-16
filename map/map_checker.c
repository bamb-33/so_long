/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:38:29 by naadou            #+#    #+#             */
/*   Updated: 2023/12/15 20:13:15 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static bool	characters_check(char *map)
{
	int	i;
	int	counter_e;
	int	counter_p;
	int	flag;

	i = 0;
	counter_e = 0;
	counter_p = 0;
	flag = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			counter_e++;
		else if (map[i] == 'P')
			counter_p++;
		else if (map[i] == 'C')
			flag = 1;
		i++;
	}
	if (counter_e == 1 && counter_p == 1 && flag == 1)
		return (1);
	return (0);
}

static bool	check_walls(char *map)
{
	int	i;
	int	w;
	int	h;

	w = 1;
	h = 1;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			w = 1;
			h++;
		}
		if ((h == 1 || h == maps_height(map)) && map[i] != '1')
			return (0);
		else if ((w == 1 || w == maps_width(map)) && map[i] != '1')
			return (0);
		w++;
		i++;
	}
	return (1);
}

static bool	rectangular_check(char *map)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (maps_width(map) <= maps_height(map))
		return (0);
	while (map[i])
	{
		if (!map[i + 1])
			w++;
		if ((map[i] == '\n' || !map[i + 1]) && w != maps_width(map))
			return (0);
		if (map[i] == '\n')
		{
			w = 0;
			i++;
			continue ;
		}
		i++;
		w++;
	}
	return (1);
}

bool	parsing(char *map)
{
	if (check_walls(map) && characters_check(map) && rectangular_check(map))
		return (1);
	return (0);
}
