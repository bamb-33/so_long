/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:47 by naadou            #+#    #+#             */
/*   Updated: 2023/12/16 16:13:36 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *s1, int len_read)
{
	char	*scpy;
	int		i;

	i = 0;
	scpy = (char *) malloc ((len_read + 1) * sizeof(char));
	if (!scpy)
	{
		free (s1);
		return (NULL);
	}
	while (i < len_read)
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = 0;
	return (scpy);
}

static char	*glue(char *s1, char *s2, char *p, int len_read)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] || j < len_read)
	{
		if (s1[i])
		{
			p[i + j] = s1[i];
			i++;
		}
		else
		{
			p[i + j] = s2[j];
			j++;
		}
	}
	free(s1);
	p[i + j] = 0;
	return (p);
}

char	*strjoin(char *s1, char *s2, int len_read)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2, len_read));
	p = (char *) malloc ((ft_strlen(s1) + len_read + 1) * sizeof(char));
	if (!p)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	return (glue(s1, s2, p, len_read));
}
