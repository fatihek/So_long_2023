/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:03 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/18 15:05:05 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_vars *vars)
{
	int	x;
	int	fd;
	int	i;

	vars->y = vertical_len(vars->map_name);
	vars->map = malloc(sizeof(char *) * vars->y + 1);
	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->y)
	{
		vars->map[i] = get_next_line(fd);
		i++;
	}
	vars->map[i] = '\0';
	close(fd);
}

int	vertical_len(char *map_name)
{
	int		count;
	int		fd;
	char	*ptr;

	fd = open(map_name, O_RDONLY);
	ptr = get_next_line(fd);
	count = 0;
	while (ptr > 0)
	{
		free(ptr);
		ptr = get_next_line(fd);
		count++;
	}
	return (count);
}

int	horizontal_len(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i] != '\n')
	{
		i++;
	}
	return (i);
}
