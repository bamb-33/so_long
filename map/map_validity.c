/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:26:44 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 11:10:31 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_for_exits(char **map, char **hm_map, int *p)
{
	if (map[p[0] - 1][p[1]] == 'E')
		hm_map[p[0] - 1][p[1]] = '1';
	if (map[p[0] + 1][p[1]] == 'E')
		hm_map[p[0] + 1][p[1]] = '1';
	if (map[p[0]][p[1] - 1] == 'E')
		hm_map[p[0]][p[1] - 1] = '1';
	if (map[p[0]][p[1] + 1] == 'E')
		hm_map[p[0]][p[1] + 1] = '1';
}

int	valid_rout(t_node *node, char **map, char **hm_map, int *p)
{
	if (map[p[0] - 1][p[1]] != 'E'
		&& map[p[0] - 1][p[1]] != '1' && hm_map[p[0] - 1][p[1]] != '1')
		node->content[0] = 1;
	if (map[p[0] + 1][p[1]] != 'E'
		&& map[p[0] + 1][p[1]] != '1' && hm_map[p[0] + 1][p[1]] != '1')
		node->content[1] = 1;
	if (map[p[0]][p[1] - 1] != 'E'
		&& map[p[0]][p[1] - 1] != '1' && hm_map[p[0]][p[1] - 1] != '1')
		node->content[2] = 1;
	if (map[p[0]][p[1] + 1] != 'E'
		&& map[p[0]][p[1] + 1] != '1' && hm_map[p[0]][p[1] + 1] != '1')
		node->content[3] = 1;
	check_for_exits(map, hm_map, p);
	return (0);
}

t_node	init(char **hm_map, char **map, int *p, t_node *node)
{
	int		i;
	t_node	new_node;

	i = 0;
	hm_map[p[0]][p[1]] = '1';
	while (i < 4)
		new_node.content[i++] = 0;
	valid_rout(&new_node, map, hm_map, p);
	new_node.content[4] = p[0];
	new_node.content[5] = p[1];
	new_node.previous = node;
	new_node.next = NULL;
	if (node)
		node->next = &new_node;
	return (new_node);
}

int	move(char **hm_map, char **map, int *p, t_node *node)
{
	if (node->content[0] == 1 && hm_map[p[0] - 1][p[1]] != '1')
	{
		map[p[0] - 1][p[1]] = 'P';
		node->content[0] = 0;
	}
	else if (node->content[1] == 1 && hm_map[p[0] + 1][p[1]] != '1')
	{
		map[p[0] + 1][p[1]] = 'P';
		node->content[1] = 0;
	}
	else if (node->content[2] == 1 && hm_map[p[0]][p[1] - 1] != '1')
	{
		map[p[0]][p[1] - 1] = 'P';
		node->content[2] = 0;
	}
	else if (node->content[3] == 1 && hm_map[p[0]][p[1] + 1] != '1')
	{
		map[p[0]][p[1] + 1] = 'P';
		node->content[3] = 0;
	}
	else
		return (0);
	map[p[0]][p[1]] = '0';
	return (1);
}

void	map_validity(char **hm_map, char **map, int *p, t_node *node)
{
	t_node	new_node;
	t_node	*node_sent;

	new_node = init(hm_map, map, p, node);
	node_sent = &new_node;
	while (move(hm_map, map, p, node_sent) == 0)
	{
		if (node_sent->previous == NULL)
		{
			free_two_d_array(map);
			if (path_check(hm_map))
			{
				free_two_d_array(hm_map);
				return ;
			}
			ft_putendl_fd("Error", 2);
			free_two_d_array(hm_map);
			exit(1);
		}
		map[node_sent->content[4]][node_sent->content[5]] = '0';
		node_sent = node_sent->previous;
		map[node_sent->content[4]][node_sent->content[5]] = 'P';
		p = starting_position(map);
	}
	map_validity(hm_map, map, starting_position(map), node_sent);
}
