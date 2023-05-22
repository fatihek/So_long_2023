/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:00 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/10 12:47:53 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(int y, int x, t_vars *vars)
{
	if ((vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'V')
		&& vars->path.imap[y + 1][x] < 1)
	{
		if (vars->map[y + 1][x] == 'C' || vars->map[y + 1][x] == 'E')
			vars->path.collectible_coin++;
		vars->path.imap[y + 1][x] = vars->path.imap[y][x] + 1;
		path_finder(y + 1, x, vars);
	}
	path_up(y, x, vars);
	path_right(y, x, vars);
	path_left(y, x, vars);
	return (1);
}

int	path_up(int y, int x, t_vars *vars)
{
	if ((vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'V')
		&& vars->path.imap[y - 1][x] < 1)
	{
		if (vars->map[y - 1][x] == 'C' || vars->map[y - 1][x] == 'E')
			vars->path.collectible_coin++;
		vars->path.imap[y - 1][x] = vars->path.imap[y][x] + 1;
		path_finder(y - 1, x, vars);
	}
	return (1);
}

int	path_right(int y, int x, t_vars *vars)
{
	if ((vars->map[y][x + 1] != '1' && vars->map[y][x + 1] != 'V')
		&& vars->path.imap[y][x + 1] < 1)
	{
		if (vars->map[y][x + 1] == 'C' || vars->map[y][x + 1] == 'E')
			vars->path.collectible_coin++;
		vars->path.imap[y][x + 1] = vars->path.imap[y][x] + 1;
		path_finder(y, x + 1, vars);
	}
	return (1);
}

int	path_left(int y, int x, t_vars *vars)
{
	if ((vars->map[y][x - 1] != '1' && vars->map[y][x - 1] != 'V')
		&& vars->path.imap[y][x - 1] < 1)
	{
		if (vars->map[y][x - 1] == 'C' || vars->map[y][x - 1] == 'E')
			vars->path.collectible_coin++;
		vars->path.imap[y][x - 1] = vars->path.imap[y][x] + 1;
		path_finder(y, x - 1, vars);
	}
	return (1);
}
