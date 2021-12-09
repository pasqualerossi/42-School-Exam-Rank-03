/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextlinemain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:20:10 by prossi            #+#    #+#             */
/*   Updated: 2021/12/09 20:20:11 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line is .%s.\n", line);
		free(line);
		i++;
	}
	return (0);
}
