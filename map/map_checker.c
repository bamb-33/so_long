/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:38:29 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 14:19:39 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	characters(char *map)
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

int	walls(char *map, char **map_two_d)
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
		if ((h == 1 || h == maps_height(map_two_d)) && map[i] != '1')
			return (0);
		else if ((w == 1 || w == maps_width(map_two_d)) && map[i] != '1')
			return (0);
		w++;
		i++;
	}
	return (1);
}

int	rectangular(char *map, char **map_two_d)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (maps_width(map_two_d) == maps_height(map_two_d))
		return (0);
	while (map[i])
	{
		if (!map[i + 1])
			w++;
		if ((map[i] == '\n' || !map[i + 1]) && w != maps_width(map_two_d))
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

int	path_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parsing(char *map)
{
	char	**hm_map;
	char	**map_two_d;

	hm_map = ft_split(map, '\n');
	if (!hm_map)
	{
		free(map);
		exit(1);
	}
	map_two_d = ft_split(map, '\n');
	if (!map_two_d)
	{
		free(map);
		free_two_d_array(hm_map);
		exit(1);
	}
	if (walls(map, hm_map) && characters(map) && rectangular(map, hm_map))
	{
		free(map);
		map_validity(hm_map, map_two_d, starting_position(hm_map), NULL);
		return ;
	}
	free(map);
	ft_putendl_fd("Error", 2);
	exit(1);
}
