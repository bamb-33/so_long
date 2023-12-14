/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2023/12/14 15:34:41 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_generator(char *map)
{
	int		i;
	int		fd;
	int 	fd_map_template;
	char	*str;

	i = 0;
	fd = open("game_map.xpm", O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		printf("failed to open the file\n");
	fd_map_template = open ("map_template.txt", O_RDONLY);
	str = get_next_line(fd_map_template);
	write (fd, str, strlen(str));
	printf("%s\n", get_next_line(fd));

	while (map[i])
	{
		if (map[i] == '\n')
		{
			write (fd, "\",\n", 3);
			i++;
		}
		if (i == 0 || map[i -1] == '\n')
			write (fd, "\"", 1);

		if (map[i] == '0')
		{
			write(fd, " ", 1);
			i++;
		}
		else if (map[i] == '1')
		{
			write(fd, "1", 1);
			i++;
		}
		else if (map[i] == 'C')
		{
			write(fd, "c", 1);
			i++;
		}
		else if (map[i] == 'E')
		{
			write(fd, "e", 1);
			i++;
		}
		else if (map[i] == 'P')
		{
			write(fd, "p", 1);
			i++;
		}
	}
	write (fd, "\",\n", 3);
	write (fd, "};", 2);
}