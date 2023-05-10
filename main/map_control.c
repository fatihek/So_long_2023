/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:10 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/04 11:54:44 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_control(t_vars *vars)
{
	int		i;
	int		fd;
	char	*ptr;

	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->len_height - 1)
	{
		ptr = get_next_line(fd);
		if (vars->map[0][i] != '1' || vars->map[vars->len_height
			- 1][i] != '1')
		{
			free(ptr);
			error_center_top_down(vars);
		}
		else if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
		{
			free(ptr);
			error_center_left_right(vars);
		}
		i++;
		free(ptr);
	}
	return (0);
}

void	error_center_top_down(t_vars *vars)
{
	ft_printf("Up or down edges not surrounded by walls");
	exit(1);
}

void	error_center_left_right(t_vars *vars)
{
	ft_printf("Right or left edges are not surrounded by walls");
	exit(1);
}
