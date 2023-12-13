/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/12/13 20:07:11 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



static int	f1(char **buffer, char **tmp, int i)
{
	if (i == -1)
	{
		free(*tmp);
		if (*buffer)
			free(*buffer);
		return (0);
	}
	else if (i == 0)
	{
		free(*tmp);
		return (1);
	}
	*buffer = ft_strjoin(*buffer, *tmp, i);
	if (!(*buffer))
		return (0);
	return (-1);
}

static int	allocation(char **tmp, int fd)
{
	if (BUFFER_SIZE + 1  < 0 || fd == -1 || BUFFER_SIZE > INT_MAX)
		return (0);
	*tmp = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*tmp))
		return (0);
	if (read(fd, *tmp, 0) == -1)
	{
		free (*tmp);
		return (0);
	}
	(*tmp)[BUFFER_SIZE] = 0;
	return (-1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char		*tmp;
	int			i;

	buffer = NULL;
	if (allocation(&tmp, fd) == 0)
		return (NULL);
	while (1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == 0 && !buffer)
		{
			free(tmp);
			return (NULL);
		}
		i = f1(&buffer, &tmp, i);
		if (i == 1)
			return (buffer);
		else if (i == 0)
			return (NULL);
	}
}
