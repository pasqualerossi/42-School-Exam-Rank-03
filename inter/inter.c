/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:48:51 by prossi            #+#    #+#             */
/*   Updated: 2022/01/05 13:22:01 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	map[255];
	int		i, j;

	i = -1;
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			j = -1;
			while (argv[2][++j])
			{
				if (map[argv[1][i]] != 1 && (argv[1][i] == argv[2][j]))
				{
					write(1, &argv[1][i], 1);
					map[argv[1][i]] = 1;
				}
			}
		}
	}
	write(1, "\n", 1);
}
