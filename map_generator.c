/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2023/12/14 21:19:10 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar_fd(char c, int fd, int *values)
{
	int	i;

	i = 0;
	while (i < values[0])
	{
		write (fd, &c, sizeof(char));
		i++;
	}
}

int	*calculate(char *map)
{
	int	w;
	int	h;
	int	*values;

	values = (int *) malloc (4 * sizeof(int));
	w = maps_width(map);
	h = maps_height(map);
	values[0] = 1020 / w;
	values[1] = 1020 - values[0];
	values[2] = 720 / h;
	values[3] = 720 - values[2];
	return (values);
}

void	map_generator(char *map)
{
	int		i;
	int		j;
	int		fd;
	int		*values;
	char	*str;

	i = 0;
	j = 0;
	values = calculate(map);
	fd = open ("map_template.txt", O_RDONLY);
	str = get_next_line(fd);
	close (fd);
	fd = open("game_map.xpm", O_CREAT | O_RDWR, 0644);
	write (fd, str, strlen(str));
	calculate(map);
	while (map[i])
	{
		if (i == 0 && j == 0)
			write (fd, "\"", 1);
		if (map[i] == '\n')
		{
			write (fd, "\",\n", 3);
			if (j < values[2])
				i = i - maps_width(map) - 1;
			else
				j = 0;
			if (i == -1 || map[i] == '\n')
				write (fd, "\"", 1);
			i++;
			j++;
		}
		if (map[i] == '0')
			ft_putchar_fd(' ', fd, values);
		else if (map[i] == '1')
			ft_putchar_fd('1', fd, values);
		else if (map[i] == 'C')
			ft_putchar_fd('c', fd, values);
		else if (map[i] == 'E')
			ft_putchar_fd('e', fd, values);
		else if (map[i] == 'P')
			ft_putchar_fd('p', fd, values);
		i++;
	}
	write (fd, "\",\n", 3);
	write (fd, "};", 2);
	close(fd);
	free(values);
}