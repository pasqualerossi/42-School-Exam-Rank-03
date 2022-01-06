/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:06:02 by prossi            #+#    #+#             */
/*   Updated: 2022/01/06 19:00:54 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*line;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 1)
		return (NULL);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
