/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:06 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/02 12:22:17 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read_bonus(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->path.imap = (int **)malloc(sizeof(int *) * (vars->len_height + 1));
	while (i < vars->len_height)
	{
		vars->path.imap[i] = malloc(sizeof(int) * (vars->width + 1));
		j = 0;
		while (j < vars->width)
		{
			if (i == vars->i && j == vars->j)
				vars->path.imap[i][j] = 1;
			else
				vars->path.imap[i][j] = 0;
			j++;
		}
		vars->path.imap[i][j] = '\0';
		i++;
	}
	vars->path.imap[i] = '\0';
}
