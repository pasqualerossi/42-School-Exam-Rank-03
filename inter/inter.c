/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:41:19 by prossi            #+#    #+#             */
/*   Updated: 2021/12/10 17:46:50 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i, j, tab[255];	
		i = 0;
		while (i < 255)
			tab[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && tab[(unsigned char)av[i][j]] == 0)
					tab[(unsigned char)av[i][j]] = 1;
				if (i == 1 && tab[(unsigned char)av[i][j]] == 1)
				{
					tab[(unsigned char)av[i][j]] = 2;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
